# HPC Bootcamp — Lab Handouts

Each lab handout provides **daily objectives, tasks, and deliverables**.  
⚠️ Teams must rotate roles daily: **Driver / Navigator / Recorder / Presenter**

---

## Day 1 — Baseline Measurement & Roofline
### Objectives
- Build and run baseline codes
- Collect perf counters (IPC, cache-misses)
- Place kernels on roofline

### Tasks
- Compile matmul, nqueens, sort at `-O0`
- Run with `perf stat`
- Compute IPC & Arithmetic Intensity
- Plot roofline placement

### Deliverables
- Table of runtimes and IPC
- Roofline diagram
- Narrative: compute-bound or memory-bound?

---

## Day 2 — Algorithmic Upgrades & Data Layout
### Objectives
- Apply faster algorithms
- Introduce tiling/cache-blocking
- Compare with BLAS

### Tasks
- Replace naive sort with `qsort`
- Implement cache-blocked matmul
- Compare vs OpenBLAS
- Optional: float vs double precision

### Deliverables
- Runtime plots for sort and matmul
- Speedup vs BLAS
- Discussion of data layout
- Optional: precision tradeoff report

---

## Day 3 — SIMD & OpenMP
### Objectives
- Enable SIMD vectorization
- Parallelize matmul with OpenMP
- Use tasks for N-Queens

### Tasks
- Compile with `-fopt-info-vec`
- Fix vectorization blockers
- Parallelize loops with `#pragma omp parallel for`
- Implement N-Queens tasks
- Explore thread affinity

### Deliverables
- Vectorization report + runtime
- Scaling plots (1–8 threads)
- Task-parallel N-Queens results

---

## Day 4 — Memory & Compiler Power-Ups
### Objectives
- Explore NUMA effects
- Apply advanced compiler flags
- Profile hotspots
- Measure perf-per-watt (optional)

### Tasks
- Use `numactl` for binding
- Compile with `-O3`, LTO, PGO
- Profile with `perf` or HPCToolkit
- Measure energy counters (if available)

### Deliverables
- NUMA locality results
- Compiler flag before/after
- Hotspot summary
- Perf-per-watt discussion

---

## Day 5 — Scaling & Capstone
### Objectives
- Perform strong/weak scaling
- Optional MPI Allreduce lab
- Assemble portfolio
- Deliver defense

### Tasks
- Measure strong scaling
- Run weak scaling test
- Run MPI Allreduce
- Assemble daily results into portfolio
- Prepare defense slides

### Deliverables
- Scaling plots
- Portfolio submitted
- Capstone defense delivered
