# Outcome → Evidence → Rubric Mapping

This matrix explicitly aligns each learning outcome with the activity/artifact students produce and the rubric anchors used for grading.

---

## Day 0 — Orientation & Primer
| Outcome | Evidence | Rubric Anchor |
|---------|----------|---------------|
| Define HPC mindset & reproducibility | Written restatement in lab log | **Meets**: correctly lists 4+ reproducibility items; **Exceeds**: adds rationale/examples |
| Verify tool setup with sanity scripts | Logs from 3 scripts | **Meets**: runs all scripts; **Exceeds**: explains warnings/errors |
| Establish team charter | Team_Charter.md | **Meets**: roles & rotation documented; **Exceeds**: includes conflict plan & decision rule |
| Create lab log template | Markdown file in `reports/` | **Meets**: sections created; **Exceeds**: adds reproducibility appendix |

---

## Day 1 — Baseline & Roofline
| Outcome | Evidence | Rubric Anchor |
|---------|----------|---------------|
| Collect perf counters | perf logs & table | **Meets**: 3 kernels logged; **Exceeds**: includes cache miss details |
| Compute IPC & AI | Calculations in table | **Meets**: correct units ±5%; **Exceeds**: explains significance |
| Place kernels on roofline | Plot + memo | **Meets**: correct placement; **Exceeds**: adds scaling sensitivity |
| Diagnose bottleneck | 200-word memo | **Meets**: identifies bottleneck; **Exceeds**: proposes plausible next step |

---

## Day 2 — Algorithmic Upgrades
| Outcome | Evidence | Rubric Anchor |
|---------|----------|---------------|
| Replace naive sort | Runtime plot | **Meets**: shows speedup; **Exceeds**: analyzes crossover points |
| Implement & tune tiled matmul | Runtime vs tile size plot | **Meets**: correct implementation; **Exceeds**: connects best tile to cache size |
| Compare to BLAS | Speedup table | **Meets**: reports ratio; **Exceeds**: credible explanation of gaps |
| Run stride test | Plot of runtime vs stride | **Meets**: correct shape; **Exceeds**: links results to cache hierarchy |

---

## Day 3 — SIMD & OpenMP
| Outcome | Evidence | Rubric Anchor |
|---------|----------|---------------|
| Remove SIMD blockers | Compiler vectorization log | **Meets**: 1 blocker removed; **Exceeds**: adds alignment/padding analysis |
| Show SIMD speedup | Before/after timings | **Meets**: ≥1.3× or justified; **Exceeds**: sensitivity analysis |
| Parallelize with OpenMP | Scaling plots | **Meets**: shows speedup curve; **Exceeds**: discusses efficiency limits |
| Implement task parallelism | N-Queens cutoff run | **Meets**: correct solutions; **Exceeds**: granularity analysis |
| Control affinity | Affinity notes | **Meets**: explains binding choice; **Exceeds**: connects to NUMA |

---

## Day 4 — Memory & Compiler Power-Ups
| Outcome | Evidence | Rubric Anchor |
|---------|----------|---------------|
| Compare local vs remote NUMA | Table of runtimes | **Meets**: shows difference; **Exceeds**: links to cache miss rates |
| Validate bandwidth ceilings | STREAM-like run | **Meets**: reports bandwidth; **Exceeds**: connects to roofline slope |
| Optimize with compiler flags | Comparison table | **Meets**: reports deltas; **Exceeds**: explains why |
| Profile hotspots | perf report snippet | **Meets**: names top hotspot; **Exceeds**: actionable proposal |
| Quantify perf-per-watt | Energy vs time plot | **Meets**: records Joules; **Exceeds**: tradeoff analysis |

---

## Day 5 — Scaling & Capstone
| Outcome | Evidence | Rubric Anchor |
|---------|----------|---------------|
| Strong & weak scaling | Plots | **Meets**: correct curves; **Exceeds**: ties to Amdahl |
| Compute speedup/efficiency | Table | **Meets**: correct math; **Exceeds**: insightful interpretation |
| Run MPI mini-lab | Logs + scaling | **Meets**: correct Allreduce; **Exceeds**: latency vs bandwidth analysis |
| Final portfolio | Markdown report | **Meets**: organized, complete; **Exceeds**: polished, professional |
| Oral defense | Presentation | **Meets**: clear explanation; **Exceeds**: confident Q&A |

---

## Cross-Cutting (All Week)
| Outcome | Evidence | Rubric Anchor |
|---------|----------|---------------|
| Maintain reproducibility | Repro appendix daily | **Meets**: logs commands; **Exceeds**: includes hardware/seed info |
| Communicate clearly | Plots, tables, memos | **Meets**: readable, labeled; **Exceeds**: concise & professional |

