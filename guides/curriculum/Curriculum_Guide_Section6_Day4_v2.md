# HPC Bootcamp Curriculum Guide

## Section 6: Day 4 — Memory Hierarchy, NUMA & Compiler Power-Ups (v2)

### Overview
Day 4 explores **memory hierarchy effects**, **NUMA locality**, and **compiler-level optimizations**. Students measure bandwidth ceilings, investigate locality with `numactl`, and experiment with compiler flags such as `-O3`, LTO, and PGO.

### HPC Mindset
Performance is shaped by the **memory hierarchy**: L1/L2/L3 caches, DRAM, and NUMA domains. Students learn to distinguish between cache-limited and bandwidth-limited performance.

### Learning Outcomes (Bloom-Aligned)
By the end of Day 4, students will be able to:
1. **Measure** sustained memory bandwidth with the STREAM-like benchmark.  
2. **Demonstrate** NUMA effects using process/thread binding.  
3. **Evaluate** compiler optimization levels and flags for performance impact.  
4. **Profile** workloads using `perf record/report` to identify hotspots.  

### Mastery Evidence
- STREAM-like benchmark results (GB/s).  
- NUMA locality experiment logs with performance deltas.  
- Timing comparisons of code compiled with different optimization flags.  
- Annotated perf report identifying hotspots.  

### Activities
1. **Memory Bandwidth Calibration**  
   - Run STREAM-like triad (`repo/extras/stream_like.c` or wrapper).  
   - Record GB/s and compare to vendor peak bandwidth.  
   - **Reference point**: modern DDR4 nodes often sustain 50–120 GB/s; DDR5 >150 GB/s.  
   - Use value as bandwidth ceiling in Roofline model.  

2. **NUMA Locality Experiments**  
   - Use `numactl --membind` and `--cpubind` to control locality.  
   - Compare remote vs local memory access performance.  
   - Plot bandwidth/latency differences.  
   - Reminder: use **color-safe palettes + labeled markers** for accessibility.  

3. **Compiler Optimizations**  
   - Build matmul with `-O0`, `-O2`, `-O3`.  
   - Add `-march=native`, `-flto` (link-time optimization).  
   - Optional: run **profile-guided optimization (PGO)** workflow.  
   - **Worked Example Table**:  

     | Flags              | Runtime (ms) | Speedup vs -O0 |
     |--------------------|--------------|----------------|
     | -O0                | 1200         | 1.0×           |
     | -O2                | 250          | 4.8×           |
     | -O3                | 180          | 6.7×           |
     | -O3 -march=native  | 140          | 8.6×           |
     | -O3 -march=native -flto | 120     | 10.0×          |  

4. **Profiling with Perf**  
   - Use `perf record` and `perf report` to identify top hotspots.  
   - **Worked Example (annotated perf report snippet):**  
     ```text
     +   60.25%  matmul     matmul_blocked    [.] matmul_inner
     +   20.13%  matmul     libc.so.6         [.] memcpy
     +    5.20%  matmul     [kernel]          [k] clear_page_c_e
     ```  
   - Students annotate: most time spent in `matmul_inner`, improvement target.  

### Formative Checks
- **Hinge Q**: “If a kernel moves more bytes than fits in cache, will performance depend on cache or memory bandwidth?” (Answer: memory bandwidth).  
- **Predict-first**: Will NUMA binding matter if dataset < LLC? (Answer: less impact).  
- **Quick write**: What compiler flag gave the biggest gain, and why?  

### Deliverables
- STREAM-like bandwidth report (repo/reports/day4/).  
- NUMA locality experiment plot.  
- Compiler optimization timing table.  
- Annotated perf report with notes.  

### Exit Ticket
Prompt: *Identify one experiment today that changed your understanding of memory or compilers, and why.*  
File: `assessments/exit_tickets/Day4_ExitTicket.md`

### Instructor Notes
- Reinforce **cache vs DRAM bandwidth distinction** with visual anchor diagram (L1/L2/L3/DRAM pyramid).  
- Use reference STREAM values to sanity-check bandwidth results.  
- Encourage students to tie NUMA locality to tomorrow’s scaling experiments.  
- Keep compiler flags focused; don’t overwhelm with obscure switches.  
- Ensure plots and tables follow **UDL guidelines**: color-blind safe, labeled axes, alt text.  

---
