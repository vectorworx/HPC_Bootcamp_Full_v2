# HPC Bootcamp Curriculum Guide

## Section 4: Day 2 — Algorithmic Upgrades & Data Layout (v2)

### Overview
Day 2 shifts from measurement to **algorithmic optimization and memory layout**. Students replace naive algorithms with efficient ones, experiment with cache tiling, and explore memory access patterns that affect performance.

### HPC Mindset
Better performance often comes from **better algorithms** and **cache-aware data layouts**, not just compiler flags.

### Learning Outcomes (Bloom-Aligned)
By the end of Day 2, students will be able to:
1. **Replace** naive algorithms with asymptotically faster ones (e.g., `qsort` vs bubble sort).  
2. **Implement** cache tiling for matrix multiplication and tune tile sizes.  
3. **Compare** optimized kernels to vendor libraries (BLAS).  
4. **Analyze** memory access via stride experiments.  

### Mastery Evidence
- Timing results comparing naive sort vs `qsort`.  
- Tile-size sweep results for matrix multiply.  
- Speedup ratio vs BLAS implementation.  
- Plot showing stride length vs runtime.  

### Activities
1. **Algorithm Replacement**  
   - Swap out naive sort for `qsort`. Measure runtime difference.  
   - Emphasize: `qsort` may vary across platforms; focus on **complexity trends** (O(n log n) vs O(n²)) more than absolute timings.  

2. **Cache Tiling for Matmul**  
   - Implement blocked/tiled matrix multiply.  
   - Sweep tile sizes (8, 16, 32, 64).  
   - Formula for feasibility:  
     ```
     Tile³ × 3 × sizeof(double) ≤ Cache Size
     ```  
   - Example: For a 256 KB L2 cache, `Tile=32` is feasible (32³ × 3 × 8 B = 786 KB, too large for L2, so adjust downward).  

   - **Worked Example**:  
     If L1 = 32 KB, and doubles = 8 B, then maximum tile size T satisfies:  
     3 × T² × 8 ≤ 32 KB → T ≤ 36 (round down to 32).  

3. **Compare to BLAS**  
   - If BLAS is available, run `dgemm`.  
   - Note: tuned BLAS often achieves **>80% of peak GFLOPs**. Students should compare ratios, not expect equality.  

4. **Stride Experiment**  
   - Allocate large array, vary access stride (1, 2, 4, 8…).  
   - Measure runtime per access.  
   - Plot runtime vs stride.  
   - Visual anchor: show how stride interacts with cache lines.  
   - Ensure plots are **color-blind safe** and labeled with units.  

### Formative Checks
- **Hinge Q**: “What happens to cache performance when stride > cache line size?” (Answer: more cache misses).  
- **Think-pair-share**: Predict which tile size will work best on your machine.  
- **Quick write**: One reason why BLAS outperforms student’s tiled matmul.  

### Deliverables
- Runtime comparison of naive sort vs `qsort`.  
- Tile sweep results table + plot.  
- BLAS vs tiled matmul speedup ratio.  
- Stride test plot (color-blind safe, labeled).  

### Exit Ticket
Prompt: *Justify your chosen tile size and predict whether it would change on a CPU with a larger L2 cache. Why?*  
File: `assessments/exit_tickets/Day2_ExitTicket.md`

### Instructor Notes
- Stress **algorithmic complexity vs micro-optimizations**.  
- Use worked tile-size example to reduce cognitive load.  
- Tie BLAS comparison to both **motivation** (what’s possible) and **reality check** (hand-tuned vs industrial libraries).  
- Highlight stride lab as a way to understand hardware realities: cache lines, prefetching, TLB.  
- Ensure accessibility: use color-blind-safe palettes, alt text, and clear labels.  

---
