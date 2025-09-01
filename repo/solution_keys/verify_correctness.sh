#!/usr/bin/env bash
set -euo pipefail

echo "== Build =="
make -j

echo "== Smoke Tests =="
./matmul_blocked 256 32 | tee /dev/stderr
./matmul_openmp 512 | tee /dev/stderr
./sort_optimized 50000 | tee /dev/stderr
./nqueens_tasks 12 0 | tee /dev/stderr

echo "== Optional BLAS Test =="
if [ "${CBLAS:-0}" = "1" ]; then
  ./matmul_blas 512 | tee /dev/stderr
else
  echo "BLAS not enabled (set CBLAS=1 to build/test matmul_blas)."
fi

echo "All tests completed."
