# STREAM-like Microbenchmark — Lab Note

**Suggested locations**  
- Code: `repo/extras/stream_like.c`  
- Lab handout: `extras/Stream_Like_Lab.md`

---

## Purpose
Calibrate your machine’s **sustained memory bandwidth** to compare against the **roofline slope**. Use this as your bandwidth ceiling when classifying kernels as memory-bound.

## Build & Run
```bash
cd repo/extras
gcc -O3 -march=native -fopenmp stream_like.c -o stream_like
export OMP_PROC_BIND=close
export OMP_PLACES=cores
export OMP_NUM_THREADS=$(nproc)
./stream_like 100000000 10 3.0
```

## What to Record
- `N`, threads, **best time** (s), **approx BW** (GB/s)  
- CPU model and DRAM type if available

> Approx bytes moved (triad) ≈ 24 × N bytes (2 loads + 1 store, double precision).  
> Note: This **ignores write-allocate (RFO)** traffic; your observed GB/s may be below peak DRAM specs.

## Use in Roofline
- Set **mem-bandwidth** (GB/s) in `tools/roofline_plot.py` to the measured triad GB/s.  
- Re-plot your kernels to see if they approach the bandwidth ceiling.

## Experiments
1. Vary threads (1, 2, 4, …) and observe BW saturation.  
2. Alter `OMP_PLACES`/`OMP_PROC_BIND` to check affinity impact.  
3. Try `float` vs `double` (optional modification) and compare BW.

## Deliverable
- A short note in `repo/reports/day4/` listing your measured bandwidth and how it changed your roofline interpretation.
