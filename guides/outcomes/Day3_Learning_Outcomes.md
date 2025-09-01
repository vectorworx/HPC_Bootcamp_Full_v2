# Day 3 — Learning Outcomes (Bloom-Aligned): SIMD & OpenMP

Make Day 3 goals explicit and measurable. Use this sheet during lab checkpoints and to frame the scaling discussion.

---

## Outcomes (Students will be able to…)

1) **Detect** auto-vectorization status and **remove** blockers *(Analyze/Apply)*  
- **Mastery evidence:** Compiles with `-fopt-info-vec`; explains at least one blocker (e.g., aliasing, misalignment) and demonstrates a fix (`restrict`, alignment, loop structure).

2) **Achieve** measurable SIMD speedup *(Apply/Evaluate)*  
- **Mastery evidence:** Before/after timings for a vectorizable loop (e.g., matmul inner loop) with ≥1.3× speedup, or a justified analysis if speedup is limited (memory-bound).

3) **Parallelize** a kernel with OpenMP and **evaluate** schedules *(Apply/Analyze)*  
- **Mastery evidence:** Uses `#pragma omp parallel for`; compares `schedule(static)` vs `schedule(dynamic)` (and chunk sizes if relevant), reports runtime & load balance observations.

4) **Implement** OpenMP **tasks** for a recursive workload (N-Queens) with a **cutoff** *(Apply/Analyze)*  
- **Mastery evidence:** Working implementation with cutoff; discusses task granularity effects and overhead; shows correctness identical to sequential baseline.

5) **Control** thread placement and **avoid** false sharing *(Apply/Analyze)*  
- **Mastery evidence:** Runs with `OMP_PROC_BIND`/`OMP_PLACES`; pinning improves stability; demonstrates a false-sharing fix (padding or privatization) if encountered.

6) **Quantify** scaling and **interpret** efficiency *(Analyze/Evaluate)*  
- **Mastery evidence:** Speedup & efficiency plots for 1,2,4,8(,16) threads; interprets diminishing returns and identifies the dominant limit (Amdahl/memory).

---

## Deliverables (graded artifacts)
- **Vectorization report** (compiler output) + before/after timings  
- **OpenMP scaling plots** (speedup & efficiency) with labeled schedules  
- **N-Queens task implementation** with cutoff and runtime comparison  
- **Affinity note** (what binding you used and why)

---

## Quick Checks (Formative)
- **Hinge Q:** A loop didn’t vectorize. First fix to try? **Add `restrict`/alignment hints** (correct).  
- **2-minute inspect:** Is your parallel loop operating on disjoint output elements? If not, how are you avoiding races?  
- **Predict-first:** Static vs dynamic schedule — which will win for your kernel and why? Compare to data.

---

## Exit Ticket (Day 3)
- In 2–3 sentences, explain your **best-performing schedule** and the **likely limiting factor** for further speedup.

---

## Rubric Anchors (how we grade “Meets” vs “Exceeds”)
- **Meets (3.3–3.6):** Shows vectorization evidence, working OpenMP with scaling, and a sound analysis of schedules & affinity.  
- **Exceeds (3.7–4.0):** Adds variance/error bars, discusses NUMA interaction with threads, or shows a false-sharing case study with a fix.

---

## Artifacts to Collect
- Markdown report + plots under `repo/reports/day3/`  
- Compiler vectorization logs (attach or paste key lines)  
- Command lines and environment in `repo/reports/day3/appendix.md`
