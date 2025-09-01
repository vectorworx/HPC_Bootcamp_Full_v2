# Solution Keys — HPC Bootcamp v2.0

These **reference implementations** show *one set* of optimizations instructors can use to demo techniques and for grading comparisons.  
They are **not** the only correct solutions. Use them to validate student results and to run quick demos.

## Contents
- `Makefile` — builds all solutions (OpenMP by default; optional BLAS)
- `common.h` — timing + aligned allocation helpers
- `matmul_blocked.c` — cache-blocked (tiled) matrix multiply (CPU)
- `matmul_openmp.c` — OpenMP-parallel matmul (row-major)
- `matmul_blas.c` — BLAS-backed `dgemm` reference (optional; requires CBLAS)
- `nqueens_tasks.c` — N-Queens with OpenMP tasks (cutoff to avoid fine grains)
- `sort_optimized.c` — switch to `qsort` (O(n log n)) with verification
- `verify_correctness.sh` — quick smoke tests on small sizes
- `expected_outputs.md` — example outputs & checks

## Build
```bash
# Default: OpenMP enabled, native tuning
make -j

# With BLAS (e.g., OpenBLAS). Set CBLAS=1 and adjust BLAS_LIBS if needed.
make matmul_blas CBLAS=1 BLAS_LIBS="-lopenblas"
```

## Run (examples)
```bash
./matmul_blocked 512 32
./matmul_openmp 1024
./nqueens_tasks 12 4     # N=12, cutoff depth=4
./sort_optimized 200000
./matmul_blas 512        # requires CBLAS=1 + BLAS installed
```

## Notes
- For deterministic checks, several programs initialize arrays to **1.0** so correctness is easy to validate (e.g., `C[0] == N` for matmul).
- The `nqueens_tasks` default cutoff prevents pathological task explosion. Set cutoff `0` to enumerate all solutions (slower).
- When grading, focus on *method & evidence* (counters/plots), not just absolute times (hardware varies).
