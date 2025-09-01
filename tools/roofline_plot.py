#!/usr/bin/env python3
# Roofline Plot Helper (HPC Bootcamp)
# Usage:
#   python tools/roofline_plot.py \
#       --csv references/Roofline_Template.csv \
#       --out roofline.png \
#       --peak-gflops 2000 \
#       --mem-bandwidth 200
#
# Notes:
# - This script expects a CSV with columns:
#     kernel,N,flops,bytes,seconds,gflops,ai_flops_per_byte,notes
# - If gflops or ai_flops_per_byte are empty in the CSV, they are computed from flops/seconds and flops/bytes.
# - The plot uses log-log axes and draws two ceilings:
#     y = peak_gflops (flat line) and y = mem_bandwidth * x (slope line).
# - Do not use seaborn; use matplotlib only (bootcamp rule).
# - Colors/styles are not customized to keep exports consistent and accessible.

import argparse
import csv
import math
import sys
from typing import List, Tuple

import matplotlib
matplotlib.use("Agg")  # headless
import matplotlib.pyplot as plt

def read_rows(csv_path: str):
    rows = []
    with open(csv_path, newline="") as f:
        reader = csv.DictReader(f)
        for r in reader:
            rows.append(r)
    return rows

def to_float(val, default=None):
    if val is None or str(val).strip() == "":
        return default
    try:
        return float(val)
    except ValueError:
        return default

def prepare_points(rows):
    pts = []
    for r in rows:
        flops = to_float(r.get("flops"))
        bytes_moved = to_float(r.get("bytes"))
        seconds = to_float(r.get("seconds"))
        gflops = to_float(r.get("gflops"))
        ai = to_float(r.get("ai_flops_per_byte"))
        name = r.get("kernel", "kernel")
        note = r.get("notes", "")
        # Derive missing metrics
        if flops is not None and seconds and not gflops:
            gflops = (flops / seconds) * 1e-9
        if flops is not None and bytes_moved and not ai:
            ai = flops / bytes_moved
        if ai and gflops:
            pts.append((ai, gflops, f"{name} ({note})" if note else name))
    return pts

def plot_roofline(points: List[Tuple[float,float,str]], peak_gflops: float, mem_bandwidth: float, out_path: str, title: str):
    fig, ax = plt.subplots(figsize=(8,6))
    # Ceilings
    # Flat (compute) ceiling
    xs = [1e-3, 1e3]
    flat_y = [peak_gflops, peak_gflops]
    slope_y = [mem_bandwidth * x for x in xs]
    ax.plot(xs, flat_y, linewidth=2, label="Peak Compute (GFLOP/s)")
    ax.plot(xs, slope_y, linewidth=2, label="Memory BW * AI")
    # Points
    for ai, gflops, label in points:
        ax.scatter(ai, gflops, s=40)
        ax.annotate(label, (ai, gflops), textcoords="offset points", xytext=(5,5), fontsize=8)
    ax.set_xscale("log")
    ax.set_yscale("log")
    ax.set_xlabel("Arithmetic Intensity (FLOPs / Byte)")
    ax.set_ylabel("Performance (GFLOP/s)")
    ax.set_title(title)
    ax.grid(True, which="both", linestyle="--", linewidth=0.5)
    ax.legend()
    fig.tight_layout()
    fig.savefig(out_path, dpi=180)
    plt.close(fig)

def main():
    p = argparse.ArgumentParser(description="Roofline plot helper")
    p.add_argument("--csv", required=True, help="CSV file with kernel metrics")
    p.add_argument("--out", default="roofline.png", help="Output image path")
    p.add_argument("--peak-gflops", type=float, required=True, help="Peak compute (GFLOP/s) for the CPU")
    p.add_argument("--mem-bandwidth", type=float, required=True, help="Sustained memory bandwidth (GB/s)")
    p.add_argument("--title", default="Roofline Model", help="Plot title")
    args = p.parse_args()

    rows = read_rows(args.csv)
    pts = prepare_points(rows)
    if not pts:
        print("No valid points found. Ensure CSV has flops/bytes/seconds or gflops+ai.", file=sys.stderr)
        sys.exit(1)
    plot_roofline(pts, args.peak_gflops, args.mem_bandwidth, args.out, args.title)
    print(f"Wrote {args.out} with {len(pts)} point(s).")

if __name__ == "__main__":
    main()
