# Day 2 — Learning Outcomes (Bloom-Aligned): Algorithmic Upgrades & Data Layout

Make Day 2 goals explicit and measurable. Reference this during lab checkpoints and the end-of-day report.

---

## Outcomes (Students will be able to…)

1) **Differentiate** algorithmic complexities and **select** the appropriate algorithm *(Understand/Evaluate)*  
- **Mastery evidence:** Replaces O(n²) sort with O(n log n) (`qsort`) and explains the expected runtime impact for the given `n`.

2) **Implement** cache-blocked (tiled) matrix multiply and **tune** tile size *(Apply/Analyze)*  
- **Mastery evidence:** Working tiled matmul with a parameter sweep (e.g., T ∈ {16, 32, 64}); identifies best T on current hardware with evidence.

3) **Compare** custom kernels with vendor libraries (BLAS) and **interpret** gaps *(Analyze/Evaluate)*  
- **Mastery evidence:** Runs `cblas_dgemm` baseline (if available) and reports speedup ratio vs custom code; explains possible reasons for gaps.

4) **Assess** data layout & alignment impacts (contiguity, AoS↔SoA) *(Analyze)*  
- **Mastery evidence:** Presents a small controlled experiment showing improved locality (e.g., row-major traversal vs strided access).

5) **Conduct** a stride-access microbenchmark to **quantify** cache effects *(Apply/Analyze)*  
- **Mastery evidence:** Produces a plot of runtime (or bandwidth) vs stride; explains L1/L2/L3 behaviors qualitatively.

---

## Deliverables (graded artifacts)
- **Runtime plots**: naive vs `qsort`; naive vs tiled matmul (with T sweep)  
- **BLAS comparison**: speedup table or plot (optional if BLAS unavailable)  
- **Stride experiment plot** with a 150–200 word analysis  
- **Reproducibility appendix**: commands, flags, CPU cache info

---

## Quick Checks (Formative)
- **Concept check:** Why can tiling increase arithmetic intensity for matmul?  
- **Hinge Q:** Which change most directly improves cache reuse? A) Wider SIMD  B) **Blocking**  C) Higher clock  D) More threads → Correct: **B**.  
- **Predict-first:** Sketch the expected trend for runtime vs stride before running; compare to actual.

---

## Exit Ticket (Day 2)
- In 2–3 sentences, justify your chosen tile size **and** predict whether it would change on a CPU with a larger L2 cache—why?

---

## Rubric Anchors (how we grade “Meets” vs “Exceeds”)
- **Meets (3.3–3.6):** Correctly implements tiled matmul; performs T sweep; presents clean plots; provides coherent analysis.  
- **Exceeds (3.7–4.0):** Adds experiment design notes (rep counts, variance bars), connects results to cache sizes/associativity, and explains BLAS gap credibly.

---

## Artifacts to Collect
- Markdown report + plots under `repo/reports/day2/`  
- Source deltas committed with tags/notes describing T sweeps  
- (If available) BLAS run logs and linking flags in `repo/reports/day2/appendix.md`
