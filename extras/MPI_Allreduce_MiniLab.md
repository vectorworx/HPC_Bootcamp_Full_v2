# MPI Allreduce Mini-Lab — HPC Bootcamp (Day 5 Optional)

---

## Goal
Introduce an essential MPI collective (`MPI_Allreduce`) and compare it to a serial reduction baseline.

---

## Prerequisites
- MPI installed (`mpicc`, `mpirun`)
- 2–8 ranks available on the test system
- Compiles on Linux/macOS with an MPI implementation (OpenMPI/MPICH/Intel MPI)

---

## Files
- `mpi_allreduce_example.c` — reference implementation (block distribution + optional serial check)

---

## Build & Run
```bash
# build
mpicc mpi_allreduce_example.c -O3 -march=native -o mpi_allreduce

# run (4 ranks, 10 million elements)
mpirun -np 4 ./mpi_allreduce 10000000
```

**Tips**
- Try ranks = 2, 4, 8
- Try N = 1e6, 1e7, 5e7 (adjust if memory-limited)
- Pin ranks if your MPI supports it for stability

---

## Experiments
1. **Correctness** — Verify that the parallel sum equals the serial baseline (the program prints both when `N <= 5e6`).  
2. **Scaling (Strong)** — Fix N; vary ranks (1,2,4,8). Record runtime of the `MPI_Allreduce` section.  
3. **Scaling (Weak)** — Increase N proportional to ranks so per-rank work stays constant. Check if time stays ~flat.  
4. **Latency vs Bandwidth** — Discuss why small N is latency-dominated whereas large N becomes bandwidth-dominated.

---

## Report Deliverables
- Table/plot of runtime vs ranks (strong scaling) and vs N-per-rank (weak scaling)
- Correctness evidence (parallel vs serial sum)
- Discussion of latency vs bandwidth regimes
- Reproducibility appendix (commands, environment, MPI version, CPU info)
