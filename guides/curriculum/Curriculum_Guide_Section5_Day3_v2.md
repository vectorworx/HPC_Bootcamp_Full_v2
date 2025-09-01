# HPC Bootcamp Curriculum Guide

## Section 5: Day 3 — SIMD & OpenMP Parallelism (v2)

### Overview
Day 3 introduces **intra-node parallelism**: **SIMD vectorization** at the instruction level and **OpenMP threading** at the core level. Students experiment with compiler auto-vectorization, OpenMP scheduling, and the limits of thread scaling.

### HPC Mindset
Modern CPUs achieve performance through **vector width (SIMD)** and **multicore parallelism (OpenMP)**. Understanding both — and their limits — is critical for high performance.

### Learning Outcomes (Bloom-Aligned)
By the end of Day 3, students will be able to:
1. **Inspect** compiler vectorization reports to verify SIMD usage.  
2. **Apply** OpenMP pragmas to parallelize loops and control scheduling.  
3. **Evaluate** thread scalability and identify bottlenecks.  
4. **Analyze** issues like false sharing, load imbalance, and early NUMA effects.  

### Mastery Evidence
- Compiler vectorization logs showing successful auto-vectorization.  
- OpenMP-parallelized kernels with runtime scaling plots.  
- Comparative results of scheduling policies (static, dynamic, guided).  
- Reflection on false sharing experiment.  

### Activities
1. **Vectorization**  
   - Compile matmul/sort with `-O3 -ftree-vectorize -fopt-info-vec`.  
   - Inspect logs to see which loops vectorized.  
   - **Vector width awareness**: AVX = 256-bit = 4 doubles per vector; AVX-512 = 512-bit = 8 doubles.  
   - Optional: explore intrinsics (e.g., `_mm256_load_pd`) for advanced students.  

2. **OpenMP Parallelization**  
   - Add `#pragma omp parallel for` to kernels.  
   - Experiment with scheduling: `static`, `dynamic`, `guided`.  
   - Measure runtime across thread counts (1, 2, 4, 8, …).  

3. **Scaling Study**  
   - Plot runtime vs threads.  
   - **Worked Example (Amdahl’s Law)**:  
     - Suppose 80% of a program is parallelizable.  
     - With infinite threads, speedup = 1 / (0.2 + 0.8/∞) = 5×.  
     - Even with 16 threads, expect ~4.7×, not 16×.  
   - **Worked scaling curve**: runtime halves up to 8 threads, then flattens due to synchronization + memory.  

4. **False Sharing Experiment**  
   - Parallelize updates to an array of structs.  
   - Show slowdown from multiple threads writing to the same cache line.  
   - **Visual anchor**: diagram of cache line (64 bytes) with two threads updating adjacent fields.  
   - Fix with padding or array-of-structs → struct-of-arrays transformation.  

### Formative Checks
- **Hinge Q**: “If a loop has a data dependency, will it auto-vectorize?” (Answer: No).  
- **Think-pair-share**: Which schedule (`static`, `dynamic`, `guided`) will best balance work for irregular workloads?  
- **Scaling check**: At what point does Amdahl’s Law predict diminishing returns?  

### Deliverables
- Vectorization logs for one kernel.  
- OpenMP runtime scaling table + plot.  
- Scheduling comparison results.  
- False sharing experiment write-up with diagram.  

### Exit Ticket
Prompt: *Explain your best-performing OpenMP schedule and the likely limiting factor for further speedup.*  
File: `assessments/exit_tickets/Day3_ExitTicket.md`

### Instructor Notes
- Stress that **auto-vectorization is fragile**; check compiler logs, don’t assume.  
- Emphasize **vector width** to help students reason about SIMD gains.  
- Reinforce that **thread scaling is bounded by Amdahl’s Law** and NUMA effects (preview for Day 4).  
- Use **worked scaling example + curve** to illustrate plateau.  
- Ensure scaling and false sharing plots follow **UDL guidelines**: color-blind safe, alt text, monospaced logs, diagrams annotated clearly.  

---
