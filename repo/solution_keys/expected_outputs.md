# Expected Outputs — Solution Keys (Examples)

These are **example** outputs to sanity-check builds. Exact timings vary by hardware.

## matmul_blocked (N=256, T=32)
```
N=256 T=32 time=0.0xxx s  perf=YYY.YY GFLOP/s  C[0]=256.0
```
- **Check:** `C[0]` should equal `N` (since A=B=1.0).

## matmul_openmp (N=512)
```
N=512 threads=8 time=0.0xxx s perf=YYY.YY GFLOP/s C[0]=512.0
```
- **Check:** `C[0] == 512.0`

## matmul_blas (N=512) *optional*
```
BLAS dgemm: N=512 time=0.0xxx s perf=ZZZ.ZZ GFLOP/s C[0]=512.0
```
- Requires `CBLAS=1` and a BLAS library.

## sort_optimized (n=50000)
```
n=50000 time=0.0xxx s sorted=yes first=... last=...
```
- **Check:** Sorted = yes.

## nqueens_tasks (N=12, cutoff=0)
```
N=12 cutoff=0 solutions=14200 time=... s
```
- With cutoff=0 (exhaustive), many references cite **14200** solutions for N=12.
  If you use a nonzero cutoff, you still get the **same count**, but overhead may change.
