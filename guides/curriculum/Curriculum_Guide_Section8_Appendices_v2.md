# HPC Bootcamp Curriculum Guide

## Section 8: Appendices & References (v2)

The appendices provide supporting material that enriches the bootcamp experience and ensures instructors and students have reference resources beyond daily lessons.

---

### Appendix A — Hinge Question Bank (with Examples)
Quick checks for understanding, organized by day.

- **Day 1:** “If Arithmetic Intensity < 1 FLOP/byte, what is the likely bottleneck?”  
  - *Worked Example*: A kernel performs 2e6 FLOPs and moves 8e6 bytes. AI = 0.25 FLOP/byte → memory-bound.  

- **Day 2:** “What happens to cache performance when stride > cache line size?”  
  - *Answer*: More cache misses; data in each line is underutilized.  

- **Day 3:** “If a loop has a data dependency, will it auto-vectorize?”  
  - *Answer*: No, dependencies block SIMD parallelization.  

- **Day 4:** “If a kernel moves more bytes than fits in cache, what dominates performance?”  
  - *Answer*: DRAM bandwidth, not cache.  

- **Day 5:** “If runtime halves with double threads at fixed size, what scaling law is demonstrated?”  
  - *Answer*: Strong scaling.  

---

### Appendix B — Roofline CSV Schema (with Example)
Schema for `references/Roofline_Template.csv`:

```csv
Kernel, GFLOPs, ArithmeticIntensity, BandwidthGBs, Classification
matmul_naive, 2.75, 0.52, 60, memory-bound
matmul_tiled, 22.1, 2.0, 60, compute-bound
sort_naive, 0.01, 0.02, 60, memory-bound
nqueens, 1.5, 1.1, 60, compute-bound
```

- **GFLOPs:** measured FLOP rate.  
- **ArithmeticIntensity:** FLOPs/byte moved.  
- **BandwidthGBs:** STREAM ceiling for machine.  
- **Classification:** memory-bound or compute-bound.  

---

### Appendix C — STREAM-like Calibration Notes
The STREAM-like microbenchmark measures sustainable memory bandwidth.

- **Triad kernel:** `A[i] = B[i] + scalar * C[i]`.  
- **Guidance**: Run with array sizes ≥ 4× LLC size to ensure DRAM bandwidth measurement.  
- Compare measured GB/s to vendor peak (DDR4 ~ 50–120 GB/s, DDR5 > 150 GB/s).  
- Use measured bandwidth as the **memory ceiling** in Roofline plots.  

---

### Appendix D — Accessibility & UDL Practices
To ensure the bootcamp is inclusive:

- **Figures & plots**: use **color-blind safe palettes**, add **alt text**, include **shapes + text labels**.  
- **Logs & code**: always present in **monospaced font**.  
- **Multiple modalities**: reinforce concepts with text, visuals, and examples.  
- **Team roles**: rotate roles daily so all students experience coder, analyzer, presenter roles.  
- **Visual Anchor**: show a pyramid diagram of memory hierarchy (L1, L2, L3, DRAM, NUMA).  

---

### Appendix E — Sample Logs & Files

**Perf Stat Example:**  
```bash
$ perf stat -e cycles,instructions,cache-misses ./matmul 256
 Performance counter stats for './matmul 256':

       12,345,678      cycles
       18,765,432      instructions              # 1.52  insn per cycle
          123,456      cache-misses              # 5.3% of all accesses
```

**Roofline CSV Example:** See Appendix B. Include template in `references/Roofline_Template.csv`.  

Both examples should be distributed to students so they can sanity-check their results.

---

### References
- Williams, S., et al. *Roofline: An Insightful Visual Performance Model for Multicore Architectures.* CACM, 2009.  
- McCalpin, J. *STREAM Benchmark.* (https://www.cs.virginia.edu/stream/)  
- Dagum, L., Menon, R. *OpenMP: An Industry-Standard API for Shared-Memory Programming.* IEEE Computational Science & Engineering, 1998.  
- Amdahl, G. *Validity of the Single Processor Approach to Achieving Large-Scale Computing Capabilities.* AFIPS Conference Proceedings, 1967.  
- Gustafson, J. *Reevaluating Amdahl’s Law.* CACM, 1988.  

---
