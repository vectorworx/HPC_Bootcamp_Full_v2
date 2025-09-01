# HPC Bootcamp — Day 3: SIMD & OpenMP

---

### Objectives
- Use compiler vectorization (SIMD)
- Parallelize loops with OpenMP
- Apply task parallelism to N-Queens
- Measure scaling and efficiency

---

### Step 1: SIMD Vectorization
- Compile with reports:
```bash
gcc -O3 -ftree-vectorize -fopt-info-vec matmul.c -o matmul
```
- Inspect vectorization success/fail
- Add `restrict` and alignment hints if needed

---

### Step 2: Manual SIMD (Optional)
- Use intrinsics (`<immintrin.h>`) for fine control
- Example: `_mm256_loadu_pd`, `_mm256_fmadd_pd`

---

### Step 3: OpenMP Parallel For
```c
#pragma omp parallel for
for (i=0; i<N; i++)
  for (j=0; j<N; j++)
    for (k=0; k<N; k++)
      C[i][j] += A[i][k] * B[k][j];
```
- Test scaling with 1, 2, 4, 8 threads
- Record runtimes and speedup

---

### Step 4: OpenMP Tasks (N-Queens)
- Recursive backtracking split into tasks
- Use cutoff to avoid excessive overhead
```c
#pragma omp task
solve(position+1, ...);
```

---

### Step 5: Thread Affinity
- Pin threads to cores for consistency
```bash
export OMP_PROC_BIND=close
export OMP_PLACES=cores
```

---

### Team Deliverables
- Vectorization evidence (compiler reports)
- Matmul scaling plot with OpenMP threads
- N-Queens speedup vs sequential
- Affinity settings explained

---

### End of Day-3 Goals
- Students achieve SIMD acceleration
- OpenMP parallelism validated with scaling plots
- N-Queens demonstrates task parallelism
