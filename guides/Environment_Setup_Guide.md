# Environment Setup Guide — HPC Bootcamp

---

## Prerequisites
- Linux environment (bare metal or VM)
- GCC or ICC compiler with OpenMP support
- perf tools (`linux-perf`)
- Optional: BLAS library (OpenBLAS, MKL)

---

## Scripts
- `run_baseline.sh` → builds and runs baseline codes
- `bandwidth_probe.sh` → measures STREAM-like memory bandwidth
- `sanity_affinity.sh` → checks OpenMP binding

---

## Recommended Environment Variables
```bash
export OMP_PROC_BIND=close
export OMP_PLACES=cores
```

---

## Optional Tools
- HPCToolkit
- Intel VTune
- numactl
- RAPL counters (if supported)

---

## Notes
- Students must run sanity scripts on Day-0
- If tools missing: instructor provides fallback workflows
