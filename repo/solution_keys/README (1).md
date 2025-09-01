# solution_keys — Instructor Reference Implementations

These are *one* set of optimized references used for demos and grading comparison.
See top-level `README.md` for course structure; see `assessments/Outcome_Evidence_Rubric.md` for alignment.

## Contents
- `Makefile`, `common.h`
- `matmul_blocked.c`, `matmul_openmp.c`, `matmul_blas.c` (optional BLAS)
- `nqueens_tasks.c`, `sort_optimized.c`
- `verify_correctness.sh`, `expected_outputs.md`

## Build
```bash
make -j
# Optional BLAS:
make matmul_blas CBLAS=1 BLAS_LIBS="-lopenblas"
```
