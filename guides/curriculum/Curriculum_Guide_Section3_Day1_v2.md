# HPC Bootcamp Curriculum Guide

## Section 3: Day 1 — Baseline Measurement & Roofline Model (v2)

### Overview
Day 1 introduces students to **baseline measurement** and the **Roofline model**, the cornerstone of performance analysis. Students measure naive C codes, compute **IPC (Instructions per Cycle)** and **Arithmetic Intensity (AI)**, and place results on the Roofline chart to diagnose bottlenecks.

### HPC Mindset
Performance analysis begins with **accurate baselines**.  
Core loop: **Measure → Analyze → Change → Validate**.  
Today focuses on **measure** and **analyze**.

### Learning Outcomes (Bloom-Aligned)
By the end of Day 1, students will be able to:
1. **Collect** performance counters (cycles, instructions, FLOPs, memory ops) with `perf`.  
2. **Compute** IPC and Arithmetic Intensity for kernels.  
3. **Plot** kernels on a Roofline diagram using measured bandwidth ceilings.  
4. **Diagnose** bottlenecks as compute-bound or memory-bound.  

### Mastery Evidence
- Perf logs for three kernels (`matmul`, `sort`, `nqueens`).  
- Calculations of IPC and AI in a results table.  
- A Roofline plot with points correctly placed.  
- A short bottleneck memo (~200 words).  

### Activities
1. **Lecture/Demo**  
   - Introduce IPC, Arithmetic Intensity, and the Roofline model (compute vs memory ceilings).  
   - Show a **visual anchor Roofline diagram** with ceilings (peak GFLOPs line and memory bandwidth slope).  
   - Explain FLOP counting for matrix multiply: baseline `matmul` performs ~2 × N³ operations for an N×N matrix.  

2. **Hands-on: Measurement**  
   - Run naive kernels, capture perf logs.  
   - Include **warmup runs** before measurement to avoid cold-cache skew.  
   - Example command:  
     ```bash
     perf stat -e cycles,instructions,cache-misses,cache-references ./matmul 256
     ```  

3. **Analysis**  
   - Calculate IPC: `IPC = Instructions / Cycles`.  
   - Calculate AI: `AI = FLOPs / Bytes`.  
   - **Worked example**: If `matmul 256` runs with ~33 million FLOPs, moves ~64 MB, and takes 0.012 s:  
     - GFLOPs = 33e6 / 0.012 / 1e9 = 2.75 GFLOP/s  
     - AI = 33e6 / 64e6 = 0.52 FLOP/byte  
     - IPC = Instructions / Cycles (from perf stat, e.g., 1.5)  

4. **Plotting**  
   - Populate CSV template (`references/Roofline_Template.csv`).  
   - Use `tools/roofline_plot.py` to generate a log–log Roofline plot.  
   - Ensure **color-blind-safe markers** and **alt text descriptions** are included with each plot.  

5. **Reflection**  
   - Students explain what limits each kernel (compute or memory).  

### Formative Checks
- **Hinge Q**: “If Arithmetic Intensity < 1 FLOP/byte, what is the likely bottleneck?” (Answer: memory).  
- **Predict-first**: Sketch where `matmul` vs `sort` might land on the Roofline before plotting.  
- **Worked-example check**: Instructor walks through IPC calculation live.  

### Deliverables
- Perf logs saved in `repo/reports/day1/`.  
- Results table with IPC and AI.  
- Roofline plot image (with alt text).  
- Bottleneck memo (~200 words).  

### Exit Ticket
Prompt: *State your #1 bottleneck for one kernel and the next experiment you plan to run tomorrow.*  
File: `assessments/exit_tickets/Day1_ExitTicket.md`

### Instructor Notes
- Emphasize **correct units** (GFLOP/s, FLOP/byte).  
- Use provided perf command so teams generate reproducible logs.  
- Keep plotting helper simple; avoid seaborn or styling overhead.  
- Stress that the Roofline is about **classification and intuition**, not exact decimals.  
- Ensure visuals follow **UDL guidelines**: color-blind safe, alt text for images, monospaced code for logs.  

---
