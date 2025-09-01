# Instructor Guidebook & Playbook — HPC Bootcamp v2.0

---

## Purpose
This playbook equips instructors to deliver the one-week HPC Bootcamp with confidence.  
It contains daily objectives, timing, pitfalls, and troubleshooting notes.

---

## Daily Structure
- **Morning (2 hrs):** Lecture + worked examples
- **Afternoon (3 hrs):** Labs + team work
- **Evening (1 hr):** Reflection + reporting

---

## Instructor Priorities
1. **Correctness before speed** — enforce reproducibility contract
2. **Scaffolding** — support teams without giving away solutions
3. **Team dynamics** — enforce daily role rotation
4. **Formative assessment** — use hinge questions and retrieval grids

---

## Common Pitfalls
- Students chasing performance before correctness
- Skipping reproducibility documentation
- Teams failing to rotate roles → uneven workload
- Over-optimization without baseline measurement

---

## Demo Scripts (5-minute instructor demos)
- **Roofline placement demo:** show how to compute AI from perf counters
- **Tiled matmul demo:** run naive vs blocked to show speedup
- **OpenMP scaling demo:** threads = 1,2,4,8 → plot runtime
- **NUMA demo:** run local vs remote with `numactl`
- **MPI demo:** run Allreduce on 2–4 ranks

---

## Troubleshooting
- **perf not available** → use wallclock time with `time`
- **BLAS not installed** → skip BLAS comparison, focus on tiled matmul
- **No energy counters** → omit perf-per-watt lab

---

## Instructor Checklist
- Review slides before each day
- Confirm all scripts run in student environment
- Verify reproducibility in sample reports
- Keep backup slides and offline copies ready
