# Day 5 — Learning Outcomes (Bloom-Aligned): Scaling & Capstone Defense

Day 5 connects scaling studies with professional communication through the capstone portfolio and oral defense.

---

## Outcomes (Students will be able to…)

1) **Design & run** strong and weak scaling experiments *(Apply/Analyze)*  
- **Mastery evidence:** Executes kernels at multiple core counts; produces strong scaling curve (time vs cores) and weak scaling curve (time vs cores with constant work per core).

2) **Calculate & interpret** speedup and efficiency *(Apply/Analyze/Evaluate)*  
- **Mastery evidence:** Computes speedup (T1/Tp) and efficiency (speedup/cores); explains diminishing returns and bottlenecks (compute, memory, communication).

3) **Use** MPI collectives (Allreduce, Scatter/Gather, Broadcast) in simple mini-labs *(Apply/Analyze)*  
- **Mastery evidence:** Runs provided MPI mini-lab; confirms correctness vs serial baseline; discusses latency vs bandwidth regimes.

4) **Integrate** all results into a coherent final portfolio *(Apply/Synthesize)*  
- **Mastery evidence:** Portfolio includes baseline→optimized journey, plots, reproducibility appendix, and narrative; all artifacts organized in repo `reports/final/`.

5) **Defend** optimization choices and tradeoffs in an oral exam *(Evaluate/Create)*  
- **Mastery evidence:** Each team member presents part of the journey; uses data/plots as evidence; responds to instructor Q&A clearly.

6) **Reflect** on HPC tradeoffs and professional practices *(Evaluate)*  
- **Mastery evidence:** Writes a reflection (200–300 words) connecting week’s lessons to real-world HPC (energy vs speed, reproducibility, communication).

---

## Deliverables (graded artifacts)
- Strong scaling plot + weak scaling plot  
- Speedup & efficiency calculations with analysis  
- MPI mini-lab results and notes (optional if MPI not available)  
- Final portfolio in `repo/reports/final/`  
- Oral defense (live, graded with rubric)  
- Reflection essay (200–300 words)

---

## Quick Checks (Formative)
- **Hinge Q:** In strong scaling, ideal runtime decreases… → **Linearly with cores** (correct).  
- **2-minute pair:** What’s one sign your scaling limit is **communication-bound** vs compute-bound?  
- **Think-predict:** Sketch expected speedup curve if overhead = 10% constant. Compare with Amdahl’s Law.

---

## Exit Ticket (Day 5)
- Write one sentence each for: **biggest win** this week, **hardest surprise**, and **next HPC question** you want to explore.

---

## Rubric Anchors (how we grade “Meets” vs “Exceeds”)
- **Meets (3.3–3.6):** Provides clean scaling plots, computes speedup/efficiency, and delivers a coherent portfolio + oral defense.  
- **Exceeds (3.7–4.0):** Integrates MPI mini-lab insights, adds sensitivity analysis (problem size scaling), or reflection shows high transfer to real-world HPC.

---

## Artifacts to Collect
- Markdown report + plots under `repo/reports/day5/`  
- MPI mini-lab logs in `repo/reports/day5/mpi/` (if available)  
- Final portfolio in `repo/reports/final/`  
- Reflection in `repo/reports/final/reflection.md`
