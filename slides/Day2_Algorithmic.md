# HPC Bootcamp — Day 2: Algorithmic Upgrades & Data Layout

---

### Objectives
- Improve algorithms for better complexity
- Explore data layout transformations
- Compare custom vs library implementations
- Measure performance vs correctness

---

### Step 1: Sorting Upgrade
- Replace naive O(n²) sort with O(n log n) algorithm
- Use `qsort` from the C standard library
```c
qsort(arr, n, sizeof(int), compare);
```
- Compare runtime vs naive sort
- Verify sorted output

---

### Step 2: Tiled Matrix Multiply
- Apply **cache-blocking (tiling)** to matmul
```c
for (i=0; i<N; i+=T)
  for (j=0; j<N; j+=T)
    for (k=0; k<N; k+=T)
      // inner tile computation
```
- Experiment with different tile sizes (T = 16, 32, 64)
- Measure runtimes

---

### Step 3: Library Comparison
- Compare custom tiled matmul vs **BLAS (OpenBLAS, MKL)**
- Use `cblas_dgemm` as reference
- Report speedup factor vs naive baseline

---

### Step 4: Data Layout
- **Row-major vs column-major** effects
- Contiguous memory improves cache locality
- Align arrays on cache-line boundaries if possible

---

### Step 5: Precision Tradeoff (Optional)
- Compare `float` vs `double` matmul
- Use Kahan summation for accuracy check
- Discuss runtime vs error tolerance

---

### Team Deliverables
- Runtime plots for naive vs qsort, naive vs tiled matmul
- Speedup factor vs BLAS
- Data layout discussion with evidence
- Optional: precision tradeoff results

---

### End of Day-2 Goals
- Algorithmic complexity improvements applied
- Cache-blocking tested and tuned
- Libraries leveraged as performance baselines
- Students understand accuracy vs speed tradeoffs
