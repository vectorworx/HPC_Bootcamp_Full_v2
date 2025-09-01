#!/usr/bin/env bash
# Wrapper for STREAM-like Triad benchmark
# Builds and runs stream_like.c with default parameters.
# Results saved to reports/day4/stream_like_results.md

set -euo pipefail

SRC="stream_like.c"
BIN="stream_like"
OUT="../../reports/day4/stream_like_results.md"

mkdir -p ../../reports/day4

echo "# STREAM-like Benchmark Results" > "$OUT"
echo "Run date: $(date)" >> "$OUT"
echo "" >> "$OUT"

# Build
echo "Building $SRC..."
gcc -O3 -march=native -fopenmp "$SRC" -o "$BIN"

# Run (default N=100M, reps=10, scalar=3.0)
echo "## Default Run (N=100e6, reps=10, scalar=3.0)" >> "$OUT"
./"$BIN" 100000000 10 3.0 | tee -a "$OUT"

# Example variation
echo "" >> "$OUT"
echo "## Half-size Run (N=50e6)" >> "$OUT"
./"$BIN" 50000000 10 3.0 | tee -a "$OUT"

echo "" >> "$OUT"
echo "Results written to $OUT"
