# Offline Reference Pack — HPC Bootcamp

---

## Key Commands
- `perf stat -e cycles,instructions,cache-misses ./app`
- `numactl --cpunodebind=0 ./app`
- `export OMP_PROC_BIND=close`
- `export OMP_PLACES=cores`

---

## Compiler Flags
- `-O3` → aggressive optimization
- `-march=native` → target local CPU
- `-flto` → link-time optimization
- `-fprofile-generate` / `-fprofile-use` → PGO

---

## OpenMP Essentials
- `#pragma omp parallel for`
- `#pragma omp task`
- Env vars: `OMP_NUM_THREADS`, `OMP_PROC_BIND`

---

## MPI Essentials (Optional)
- `MPI_Init`, `MPI_Finalize`
- `MPI_Comm_size`, `MPI_Comm_rank`
- `MPI_Allreduce`
