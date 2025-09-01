# Perf-per-Watt Cheat Sheet — HPC Bootcamp

---

## Why It Matters
Performance that ignores energy can be unsustainable at scale. We balance **time-to-solution** with **energy-to-solution**.

---

## How To Measure
1. Capture energy before and after the run (RAPL or perf).
2. Compute `Joules = energy_after - energy_before`.
3. Compute **GFLOP/J** or **Work/J** for your kernel.

---

## Commands (examples)
```bash
# Using perf RAPL events (Intel)
perf stat -e power/energy-pkg,power/energy-cores ./app

# Manual RAPL read (if permitted):
cat /sys/class/powercap/intel-rapl:0/energy_uj  # before
./app
cat /sys/class/powercap/intel-rapl:0/energy_uj  # after
```

**Notes**
- Ensure a steady CPU governor (e.g., `performance`) for consistent measurements.
- Record CPU model, base/turbo frequency, and governor.
- For AMD/ARM/Apple Silicon, use platform-specific counters or fallback to wall energy meters if available.

---

## Reporting
- Always show both **time** and **energy** (and derived metrics like GFLOP/J).
- Compare configurations (e.g., different thread counts, affinities, frequencies).
- Discuss tradeoffs: best **time** vs best **energy** — they may not be the same.
