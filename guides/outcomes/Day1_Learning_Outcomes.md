# Day 1 — Learning Outcomes (Bloom-Aligned): Baseline & Roofline

This sheet makes Day 1 objectives explicit and measurable. Add it to your repo and reference it during lab checkpoints.

---

## Outcomes (Students will be able to…)

1) **Operate** perf tooling to collect baseline counters *(Apply)*  
- **Mastery evidence:** Runs `perf stat` with events `cycles,instructions,cache-misses` for 3 kernels (matmul, sort, N-Queens); logs exact commands and environment.

2) **Compute** IPC and Arithmetic Intensity (AI = FLOPs / Bytes) *(Apply)*  
- **Mastery evidence:** IPC and AI calculations shown in a table; units correct; AI within **±5%** of reference for at least one kernel.

3) **Place & interpret** kernels on a Roofline plot *(Analyze)*  
- **Mastery evidence:** Roofline plot with each kernel tagged; correct classification as **memory-bound** (slope) or **compute-bound** (ceiling), with 1–2 sentence justification per kernel.

4) **Diagnose** the primary bottleneck and **propose** the next optimization step *(Analyze/Evaluate)*  
- **Mastery evidence:** Short plan mapping diagnosis → next step (e.g., “Memory-bound → cache blocking / data layout”; “Compute-bound → SIMD/threads”).

5) **Document** reproducible baselines *(Apply)*  
- **Mastery evidence:** Baseline table (N, time, counters, IPC, AI) + reproducibility appendix (commands, flags, CPU info).

---

## Deliverables (graded artifacts)
- **Baseline Table** (3 kernels): `N, time(s), cycles, instructions, cache-misses, IPC, AI`  
- **Roofline Plot** (use CSV template in Appendix B of Curriculum v3)  
- **Bottleneck Memo** (≤200 words) with next-step plan  
- **Reproducibility Appendix** (commands, flags, env, hardware)

---

## Quick Checks (Formative)
- **Worked→Faded Mini:** Given N=256 matmul, compute FLOPs (`2*N^3`) and approximate bytes (`3*N^2*8`), then AI.  
- **Hinge Q:** If IPC ↑ but runtime ~same, most likely cause? **A) Memory bandwidth saturation** (correct).  
- **2-minute Pair:** Where would a dot product land on the roofline and why?

---

## Exit Ticket (Day 1)
- State your **#1 bottleneck** for one kernel and the **next experiment** you will run tomorrow. Include the expected outcome.

---

## Rubric Anchors (how we grade “Meets” vs “Exceeds”)
- **Meets (3.3–3.6):** Correct counters, correct IPC/AI, correct placement & classification, actionable plan.  
- **Exceeds (3.7–4.0):** Adds sensitivity analysis (vary N), discusses measurement stability (reps/variance), and cites ceilings (BW/peak).

---

## Artifacts to Collect
- Markdown report with tables/plots saved under `repo/reports/day1/`  
- CSV used for the roofline plot (commit to version control)  
- Commands and environment in `repo/reports/day1/appendix.md`
