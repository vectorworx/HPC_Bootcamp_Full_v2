# START HERE — Instructor Runbook

This document is the **day-by-day scaffolding** for running the HPC Bootcamp.  
It ties together **learning outcomes, activities, deliverables, and assessments**.

---

## Day 0 — Orientation & Reproducibility
- **Goal:** Establish HPC mindset: *Measure → Analyze → Change → Validate*.  
- Run sanity checks (`perf`, compiler, OpenMP).  
- Complete **Team Charter** (`guides/Team_Charter.md`).  
- Students create lab logs in `repo/reports/day0/`.  
- **Deliverables:** sanity logs, Team Charter, lab logs.  
- **Exit Ticket:** [assessments/exit_tickets/Day0_ExitTicket.md].

---

## Day 1 — Baseline Measurement & Roofline
- **Goal:** Measure naive codes and place on Roofline.  
- Collect IPC, AI from perf logs.  
- Fill in [references/Roofline_Template.csv].  
- Plot Roofline with `tools/roofline_plot.py`.  
- **Deliverables:** logs, Roofline plot, bottleneck memo.  
- **Exit Ticket:** [assessments/exit_tickets/Day1_ExitTicket.md].

---

## Day 2 — Algorithmic Upgrades & Data Layout
- **Goal:** Apply algorithmic optimizations (tiling, qsort).  
- Sweep tile sizes, compare vs BLAS.  
- Run stride experiment.  
- **Deliverables:** tile sweep plots, sort vs qsort comparison, BLAS ratio, stride plot.  
- **Exit Ticket:** [assessments/exit_tickets/Day2_ExitTicket.md].

---

## Day 3 — SIMD & OpenMP Parallelism
- **Goal:** Introduce vectorization and OpenMP threading.  
- Inspect compiler vectorization logs.  
- Parallelize kernels with OpenMP, compare schedules.  
- False sharing demo + fix.  
- **Deliverables:** scaling plots, vectorization logs, scheduling comparison, false sharing write-up.  
- **Exit Ticket:** [assessments/exit_tickets/Day3_ExitTicket.md].

---

## Day 4 — Memory Hierarchy, NUMA & Compiler Power-Ups
- **Goal:** Understand cache vs DRAM bandwidth and NUMA effects.  
- Run STREAM-like test to measure bandwidth ceiling.  
- NUMA binding experiment with `numactl`.  
- Compare compiler flags: -O0, -O2, -O3, -march=native, LTO, PGO.  
- Profile kernels with `perf record/report`.  
- **Deliverables:** STREAM results, NUMA plots, compiler comparison table, annotated perf report.  
- **Exit Ticket:** [assessments/exit_tickets/Day4_ExitTicket.md].

---

## Day 5 — Scaling Studies & Capstone Defense
- **Goal:** Study strong vs weak scaling and present capstone.  
- Run strong and weak scaling experiments.  
- Optional MPI mini-lab (`repo/extras/mpi_allreduce_example.c`).  
- Teams assemble final portfolio in `repo/reports/final/`.  
- **Capstone Oral Defense:** teams present optimization journey.  
- **Deliverables:** scaling plots, portfolio, oral defense presentation.  
- **Exit Ticket:** [assessments/exit_tickets/Day5_ExitTicket.md].

---

## Instructor Notes
- Use **guides/curriculum/Curriculum_Guide.md** for full narrative and supporting content.  
- Refer to **guides/Instructor_Guidebook_Playbook.md** for pacing, pitfalls, and demos.  
- Check **guides/UDL_Checklist.md** daily to ensure accessibility.  
- Encourage reproducibility and teamwork throughout.  
- Celebrate capstone presentations — they mark the transition into applied HPC practice.  

---
