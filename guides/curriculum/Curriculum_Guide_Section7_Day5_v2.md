# HPC Bootcamp Curriculum Guide

## Section 7: Day 5 — Scaling Studies & Capstone Defense (v2)

### Overview
Day 5 expands performance analysis to **scaling studies** and culminates with a **capstone project and oral defense**. Students test strong vs. weak scaling, run optional MPI mini-labs, and assemble their final reproducible portfolio.

### HPC Mindset
Scaling reveals the limits of parallelism. Students learn to interpret scaling efficiency, laws of parallel speedup, and apply them to real HPC workloads.

### Learning Outcomes (Bloom-Aligned)
By the end of Day 5, students will be able to:
1. **Distinguish** between strong and weak scaling experiments.  
2. **Run** scaling studies across multiple thread counts or nodes.  
3. **Interpret** scaling curves using Amdahl’s and Gustafson’s Laws.  
4. **Calculate** scaling efficiency and identify inefficiencies.  
5. **Assemble** a reproducible final portfolio with code, plots, and analysis.  
6. **Defend** optimization choices in an oral review.  

### Mastery Evidence
- Strong scaling plot (runtime vs cores, fixed problem size).  
- Weak scaling plot (runtime vs cores, problem size ∝ cores).  
- Annotated analysis referencing Amdahl/Gustafson.  
- Efficiency calculations included in results.  
- Final portfolio submission in `repo/reports/final/`.  
- Oral defense graded with rubric.  

### Activities
1. **Scaling Studies**  
   - **Strong scaling**: keep problem size fixed, increase threads.  
   - **Weak scaling**: increase problem size with threads, measure efficiency.  
   - **Efficiency formulas**:  
     - Strong scaling efficiency = Speedup / #Cores.  
     - Weak scaling efficiency = T(1) / T(P).  

   - **Worked Example**:  
     - Runtime T(1) = 100 s. Runtime T(4) = 30 s.  
     - Speedup = 100 / 30 ≈ 3.33×. Efficiency = 3.33 / 4 = 0.83 (83%).  

   - **Reference behaviors**:  
     - Ideal strong scaling line: runtime = T(1)/P.  
     - Real systems flatten after LLC/NUMA effects.  

2. **MPI Mini-Lab (optional)**  
   - Run `mpi_allreduce_example.c` (if environment supports MPI).  
   - Observe communication overhead as core counts rise.  
   - Clarification: Optional, but **recommended for exposure** to distributed scaling.  

3. **Capstone Portfolio Assembly**  
   - Each team compiles results: logs, plots, memos.  
   - Ensure reproducibility appendix includes commands, flags, hardware details.  

4. **Oral Defense**  
   - Each team presents one kernel’s full optimization journey.  
   - Defend: measurement choices, optimizations, tradeoffs.  
   - Instructor + peers ask probing questions.  

### Formative Checks
- **Hinge Q**: “If runtime halves with double threads at fixed problem size, what scaling law is demonstrated?” (Answer: strong scaling).  
- **Predict-first**: Which experiment (strong vs weak) will show better efficiency on memory-bound kernels? (Answer: weak scaling).  
- **Worked efficiency check**: Students calculate efficiency for a given speedup scenario.  

### Deliverables
- Strong and weak scaling plots.  
- Annotated scaling analysis memo with efficiency calculations.  
- Final portfolio in `repo/reports/final/`.  
- Oral defense presentation.  

### Exit Ticket
Prompt: *What was your most effective optimization this week, and how will you apply this mindset beyond the bootcamp?*  
File: `assessments/exit_tickets/Day5_ExitTicket.md`

### Instructor Notes
- Emphasize **laws of scaling**:  
  - **Amdahl’s Law**: speedup limited by serial fraction.  
  - **Gustafson’s Law**: larger problems scale better.  
- Show **visual anchor diagram** of strong vs weak scaling curves.  
- Provide **reference efficiency examples** for context.  
- Keep oral defense constructive: focus on reasoning, not just results.  
- Celebrate reproducibility: portfolio should be a “lab notebook” of the entire bootcamp.  
- Ensure scaling plots are accessible: use shapes + colors + labels, add alt text.  

---
