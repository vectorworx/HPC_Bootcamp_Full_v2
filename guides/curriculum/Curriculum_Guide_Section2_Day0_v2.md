# HPC Bootcamp Curriculum Guide

## Section 2: Day 0 — Orientation & Reproducibility Primer (v2)

### Overview
Day 0 sets the foundation for the entire bootcamp. Students learn the **HPC performance mindset** and establish the habits of **measurement, reproducibility, and collaboration** that will guide the rest of the week.

### HPC Mindset
Core loop: **Measure → Analyze → Change → Validate**.  
No optimization is meaningful without accurate measurement and reproducibility.

**Visual Anchor:**  
```
[Measure] → [Analyze] → [Change] → [Validate] → (repeat)
```
This diagram should appear on screen and in handouts at the start of the course.

### Learning Outcomes (Bloom-Aligned)
By the end of Day 0, students will be able to:
1. **Define** the HPC performance loop and reproducibility contract.  
2. **Verify** their environment using sanity scripts.  
3. **Organize** into teams and establish roles via a Team Charter.  
4. **Create** a reproducible lab log template that includes hardware awareness.  

### Mastery Evidence
- Students restate the loop in their own words.  
- Logs from sanity scripts (`perf`, compiler, OpenMP).  
- Logs include **CPU model, cache hierarchy, and memory details** (`lscpu`, `/proc/cpuinfo`).  
- Completed Team Charter with roles & rotation schedule.  
- Lab log file in `repo/reports/day0/` with clear, monospaced code/log formatting.  

### Activities
1. **Kickoff Discussion**: Why HPC? Why reproducibility? Examples from defense and science where reproducibility failures caused setbacks.  
   - Anecdote: An HPC team lost 2 weeks of results because compiler flags weren’t recorded. When they recompiled, results changed and could not be verified.  
2. **Sanity Checks**: Run scripts to confirm tool availability. Capture logs in `repo/reports/day0/`.  
   - Include a **simple perf counter demo**: run `perf stat` on a trivial loop (e.g., sum of 1e6 integers) and interpret cycles/instructions.  
3. **Team Formation**: Fill out `guides/Team_Charter.md`. Rotate roles daily.  
4. **Lab Log Setup**: Each student creates a Markdown log with sections: commands, environment (hardware + software), results, lessons learned.  

### Formative Checks
- **Poll**: “What is the *first* step before you change code?” (Correct: measure).  
- **Hinge Question**: Which of these affects reproducibility? (Correct: All of the above — random seed, loop unrolling, compiler flags).  
- **Think-pair-share**: How could forgetting hardware info (CPU/cache) affect reproducibility?  

### Deliverables
- Sanity script logs (including hardware awareness).  
- Completed Team Charter.  
- Lab log template committed to `repo/reports/day0/`.  

### Exit Ticket
Prompt: *List one risk if you skip reproducibility documentation, and one step you’ll add to your workflow.*  
File: `assessments/exit_tickets/Day0_ExitTicket.md`

### Instructor Notes
- Keep lecture <30 min; most of Day 0 is **hands-on setup**.  
- Highlight reproducibility horror stories (lost configs, untracked flags).  
- Reinforce teamwork from the start; this models real HPC projects.  
- Ensure visuals (slides, plots) follow **UDL guidelines**: color-blind safe, alt text provided, and logs shown in monospaced fonts.  

---
