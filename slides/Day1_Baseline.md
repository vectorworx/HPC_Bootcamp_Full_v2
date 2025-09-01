# HPC Bootcamp — Day 1: Baseline Measurement & Roofline

---

### Objectives
- Compile and run baseline programs
- Collect performance counters (cycles, IPC, cache-misses)
- Compute Arithmetic Intensity (AI)
- Place kernels on the Roofline model

---

### Programs of Focus
- **Matrix Multiplication (matmul)**
- **N-Queens Backtracking**
- **Sorting (naive sort)**

---

### Step 1: Build & Run
```bash
gcc -O0 matmul.c -o matmul
./matmul 256
```
- Record runtime
- Verify correctness of output

---

### Step 2: Measure Performance
```bash
perf stat -e cycles,instructions,cache-misses ./matmul 256
```
- Cycles → execution time proxy
- Instructions → workload size
- Cache-misses → memory pressure
- IPC = instructions / cycles

---

### Step 3: Compute Arithmetic Intensity
- Formula: **AI = FLOPs / Bytes Moved**
- Example: Dense matmul ~ 2N³ / (3N² * 8)
- Place point on roofline diagram

---

### Step 4: Roofline Placement
- If below sloped line → **memory bound**
- If below flat line → **compute bound**
- Identify bottleneck category

---

### Team Deliverables
- Runtime table for matmul, nqueens, sort
- IPC & AI calculations
- Roofline placement diagram
- Narrative: is it compute or memory-bound?

---

### End of Day-1 Goals
- Baseline results collected
- Roofline model placement complete
- Bottlenecks identified for optimization tomorrow
