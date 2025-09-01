# Portability Appendix — HPC Bootcamp

---

## ARM & Apple Silicon
- Compilers: `clang`, `gcc`
- BLAS: use OpenBLAS
- Perf tools may differ (e.g., `perf` not supported → use `time`)

---

## GPU Awareness (Preview)
- CUDA/OpenCL for accelerators
- Roofline model extends to GPU memory BW
- Awareness only (no GPU coding required in bootcamp)

---

## Cluster Environments
- MPI scaling across nodes
- Slurm job submission basics (if applicable)
- Not required in this bootcamp, but awareness prepares students for larger systems
