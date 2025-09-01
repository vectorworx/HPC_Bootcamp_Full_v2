# Worked → Faded Examples — HPC Bootcamp

---

## Day 1 Example
**Worked:**
```bash
perf stat -e cycles,instructions ./matmul 256
# IPC = instructions / cycles
```
**Faded:**
```bash
perf stat -e cycles,instructions,cache-misses ./[your program] N
# Compute IPC and classify compute vs memory-bound
```

---

## Day 2 Example
**Worked (Tiled matmul pseudocode):**
```c
for (i=i0; i<i0+T; i++)
  for (j=j0; j<j0+T; j++)
    for (k=k0; k<k0+T; k++)
      C[i][j] += A[i][k] * B[k][j];
```
**Faded:** Implement this in C with `T=32`. Compare runtime vs naive matmul.

---

## Day 3 Example
**Worked:**
```c
#pragma omp parallel for
for (int i=0; i<N; i++) C[i]=A[i]+B[i];
```
**Faded:** Parallelize matmul with OpenMP. Measure scaling with 1–8 threads.

---

## Day 4 Example
**Worked (PGO flow):**
```bash
gcc -fprofile-generate -O3 app.c -o app
./app
gcc -fprofile-use -O3 app.c -o app
```
**Faded:** Recompile matmul with PGO; compare runtime before/after.

---

## Day 5 Example
**Worked:**
```c
MPI_Allreduce(&local, &global, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
```
**Faded:** Use MPI_Allreduce to sum dot products across ranks. Compare vs serial.
