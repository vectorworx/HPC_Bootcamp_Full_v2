# HPC Bootcamp Curriculum Guide

## Section 1: Introduction & Philosophy (v2)

### Purpose of the Bootcamp
This one-week HPC Bootcamp is designed for **seasoned C programmers who are new to high performance computing (HPC)**.  
The purpose is to give engineers a **conceptual and practical foundation** in performance measurement, optimization, and scaling so they can contribute to advanced projects in defense, research, and industry.

### Why This Matters
Modern defense, scientific, and industrial problems demand **massive computational power**.  
Solving these problems requires not only coding ability but the ability to **optimize, scale, and reason about performance**.  
This bootcamp is the **primer and indoctrination** for engineers entering HPC — it gives them the essential mindset, tools, and techniques to extend in their work.

### Philosophy of Instruction
1. **Evidence-first mindset** — always measure before you change.  
2. **Reproducibility** — every result must be backed by commands, flags, and environment details.  
3. **Ceilings and limits** — always reason about hardware ceilings (peak FLOPs, memory bandwidth, scaling limits) when analyzing performance.  
4. **Energy awareness** — consider performance per watt as a cross-cutting concern for sustainable, mission-ready computing.  
5. **Scaffolding** — students move from worked examples → guided practice → independent optimization.  
6. **Real-world relevance** — every technique is tied to authentic HPC challenges (climate, cryptography, AI/ML, defense).  
7. **Collaboration** — engineers work in rotating teams with defined roles to simulate HPC project workflows.  

### Course Design Principles
- **Structured Daily Outcomes**: Each day has Bloom-aligned learning outcomes with mastery evidence.  
- **Formative Feedback**: Daily hinge questions, quick checks, and exit tickets ensure concepts are mastered before advancing.  
- **Portfolio-Based Assessment**: Students build a reproducible portfolio of plots, reports, and optimized code.  
- **Oral Defense**: Capstone concludes with a defense of optimization choices, mimicking real HPC review processes.  
- **Accessibility & UDL**: All materials follow Universal Design for Learning (UDL) guidelines to ensure clarity and inclusion. Plots use color-safe palettes, all figures include alt text, and code is formatted for readability.  

### Motivating Example
A naive matrix multiply of size 2048×2048 may take **hours** to run. With cache blocking, SIMD, and OpenMP optimizations, the same problem can be solved in **minutes** or even **seconds** on the same machine. This transformation demonstrates the power of HPC techniques students will master during the bootcamp.

### Bootcamp-Wide Learning Outcomes
By the end of the bootcamp, students will be able to:
1. **Diagnose** whether a workload is compute-bound, memory-bound, or communication-bound.  
2. **Measure & model** performance using IPC, Arithmetic Intensity, and Roofline analysis.  
3. **Optimize** C programs with tiling, SIMD, OpenMP, and NUMA-aware practices.  
4. **Evaluate** performance-per-watt and communicate tradeoffs.  
5. **Produce** a reproducible portfolio of measurements, code, and plots.  
6. **Defend** optimization choices in an oral review.  
7. **Extend** their learning toward distributed (MPI) and accelerator (GPU) computing beyond the bootcamp.  

### What Students Will Leave With
- The ability to **diagnose bottlenecks** (memory, compute, communication).  
- Experience with **roofline modeling**, cache analysis, SIMD, OpenMP, and NUMA.  
- Awareness of **energy/perf-per-watt tradeoffs**.  
- A reproducible **final portfolio** documenting their optimization journey.  
- The confidence to approach more complex HPC projects beyond the bootcamp.  
- A clear roadmap to **advanced HPC topics** (MPI, GPU, distributed systems).  

---
