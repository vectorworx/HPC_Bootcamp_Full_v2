# Day 4 — Learning Outcomes (Bloom-Aligned): Memory Hierarchy, NUMA & Compiler Power-Ups

Day 4 goals: connect low-level memory behavior, compiler optimizations, and profiling into actionable improvements.

---

## Outcomes (Students will be able to…)

1) **Explain** the cache & NUMA hierarchy and **predict** performance effects of memory placement *(Understand/Analyze)*  
- **Mastery evidence:** Accurately sketches local vs remote access path; predicts latency/throughput differences; matches results in a NUMA binding experiment.

2) **Measure** and **compare** local vs remote NUMA memory performance *(Apply/Analyze)*  
- **Mastery evidence:** Runs the same kernel with `numactl` local vs remote; reports runtime and cache-miss rates; interprets difference.

3) **Validate** bandwidth ceilings with a STREAM-like microbenchmark *(Apply/Analyze)*  
- **Mastery evidence:** Executes provided `stream_like.c`; compares achieved bandwidth with theoretical max; relates to roofline slope.

4) **Optimize** with advanced compiler flags and **evaluate** impact *(Apply/Evaluate)*  
- **Mastery evidence:** Runs code with `-O3`, `-march=native`, LTO, and PGO; reports before/after performance; explains *why* improvement occurred or didn’t.

5) **Profile** kernels with `perf record/report` and **identify** hotspots *(Apply/Analyze)*  
- **Mastery evidence:** Provides a flamegraph or report snippet; names top 1–2 hotspots; proposes one actionable optimization.

6) **Quantify** energy-to-solution and **compare** perf-per-watt across configs *(Apply/Evaluate)*  
- **Mastery evidence:** Measures energy (if available) with RAPL/perf; compares Joules vs runtime for 2–3 runs; discusses tradeoff.

---

## Deliverables (graded artifacts)
- NUMA locality experiment results (table/plot + narrative)  
- STREAM-like bandwidth run + comparison to roofline slope  
- Compiler flag comparison table (baseline vs O3/LTO/PGO)  
- Profiling summary (perf report, hotspot list, proposed fix)  
- Perf-per-watt results (optional if hardware supports energy counters)

---

## Quick Checks (Formative)
- **Hinge Q:** NUMA penalty occurs when…? → **Threads access remote memory** (correct).  
- **Mini-demo prediction:** Will adding `-O3` always improve performance? Why or why not?  
- **Think-pair:** Which compiler flag is most “hardware aware” — O3, march=native, or PGO?

---

## Exit Ticket (Day 4)
- Write 2–3 sentences summarizing one **surprising effect** observed today (NUMA locality, compiler flag, or perf hotspot).

---

## Rubric Anchors (how we grade “Meets” vs “Exceeds”)
- **Meets (3.3–3.6):** Provides correct NUMA comparison, correct STREAM run, compiler flag deltas, and a coherent hotspot analysis.  
- **Exceeds (3.7–4.0):** Includes perf flamegraph or annotated report, discusses stability of measurements, connects NUMA/flags to AI and roofline.

---

## Artifacts to Collect
- Markdown report under `repo/reports/day4/`  
- STREAM-like run logs and bandwidth ceiling check  
- Compiler flag build logs (optional diffs)  
- Perf profiling output (attach snippet or image if allowed)  
- Energy/perf-per-watt table (if supported)
