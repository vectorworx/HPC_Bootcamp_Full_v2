# Precision Tradeoffs — Mini Case (Day 2/4 Optional)

---

## Goal
Explore performance vs numerical stability when changing precision (double→float) and when using compensated summation.

---

## Tasks
1. **Precision Swap** — Run matrix multiply with `double` and `float` (if your build supports both). Compare runtime and error vs a high-precision reference.  
2. **Compensated Summation** — Implement and benchmark **Kahan summation** for a dot product versus a naive sum.  
3. **Reproducibility** — Fix seeds and document compiler flags; report both **time** and **error**.

---

## Suggested Steps
- Build and time the `dot_kahan.c` reference.
- For matmul, compute an error norm (e.g., `||C_float - C_double|| / ||C_double||`).

---

## Deliverables
- Plots/tables for runtime and error (L2 norm or relative error).
- Narrative explaining when precision reduction is acceptable for the application.
- Reproducibility appendix (commands, flags, CPU info, seeds).
