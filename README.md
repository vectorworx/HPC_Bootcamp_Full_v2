# HPC Bootcamp Repository

This repository contains the **complete one-week HPC Bootcamp** package for seasoned C programmers entering the world of High Performance Computing (HPC).  
It provides reproducible labs, supporting guides, and scaffolding for both instructors and students.

---

## 📂 Repo Map
See [Repo_Map.md](Repo_Map.md) for a one-page overview of the full structure.

**Highlights:**
- **START_HERE.md** → Instructor’s master runbook.
- **guides/curriculum/Curriculum_Guide.md** → Full course narrative (philosophy, day-by-day sections, appendices).
- **assessments/** → Rubrics, exit tickets, portfolio templates.
- **repo/src/** → Student baseline C codes.
- **repo/solution_keys/** → Instructor reference solutions.
- **repo/reports/** → Student output folders (daily + final).
- **tools/** → Utilities (roofline plotter, wrappers).
- **references/** → CSV schema, visual aids, portability appendix.
- **extras/** → Optional labs (STREAM-like, MPI).

---

## 🎯 Course Goals
By the end of this bootcamp, students will:
- Diagnose bottlenecks (compute, memory, communication).
- Apply algorithmic upgrades, SIMD, OpenMP, NUMA-aware practices.
- Measure and model performance with IPC, Arithmetic Intensity, and Roofline analysis.
- Interpret scaling studies via Amdahl’s & Gustafson’s Laws.
- Assemble a reproducible **final portfolio** documenting their optimization journey.
- Defend their decisions in an **oral capstone review**.

---

## 📑 Key Documents
- **[START_HERE.md](START_HERE.md):** Instructor’s daily guide.
- **guides/curriculum/Curriculum_Guide.md:** Complete textual curriculum guide.
- **guides/Instructor_Guidebook_Playbook.md:** Instructor tips, pitfalls, pacing.
- **guides/UDL_Checklist.md:** Accessibility practices.
- **Repo_Map.md:** One-page overview of repo structure.

---

## ⚙️ Getting Started
1. Clone the repo.  
2. In `repo/src/`, build the baseline codes (`matmul`, `sort`, `nqueens`).  
3. Follow **START_HERE.md** for daily activities and sequencing.  
4. Students save all logs and plots into `repo/reports/dayX/`.  
5. On Day 5, assemble everything into `repo/reports/final/`.

---

## 📢 Notes
- Instructor should review **Curriculum_Guide.md** before teaching.  
- All code and artifacts are designed for **C programmers new to HPC**.  
- The bootcamp is **introductory**; MPI and GPU acceleration are previewed, not taught in depth.  

---
