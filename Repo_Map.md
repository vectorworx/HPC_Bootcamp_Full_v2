# 📂 HPC Bootcamp Repo Map (One Page)

```text
HPC-Bootcamp/
│
├── README.md                # Overview
├── START_HERE.md             # Instructor guide & scaffolding
│
├── guides/                   # Instructor & course guides
│   ├── UDL_Checklist.md
│   ├── Team_Charter.md
│   └── curriculum/           # Curriculum guide (sections + compiled)
│
├── assessments/              # Rubrics & reflections
│   ├── Outcome_Evidence_Rubric.md
│   ├── exit_tickets/         # Daily exit tickets
│   └── Final_Portfolio_Template.md
│
├── references/               # Templates & reference docs
│   ├── Roofline_Template.csv
│   ├── Visualization_Aids.md
│   └── Portability_Appendix.md
│
├── tools/                    # Helper scripts
│   └── roofline_plot.py
│
├── repo/                     # Student workspace
│   ├── src/                  # Baseline codes (matmul, sort, nqueens)
│   ├── solution_keys/        # Instructor-only reference solutions
│   ├── extras/               # STREAM-like + MPI labs
│   └── reports/              # Daily outputs + final portfolio
│
└── extras/                   # Handouts & optional mini-labs
    ├── Stream_Like_Lab.md
    ├── Run_Stream_Like_Wrapper.md
    └── MPI_Allreduce_MiniLab.md
```

---

## 🔑 Quick Orientation
- **Start Here**: `START_HERE.md` → daily teaching script.  
- **Daily Outcomes**: `guides/curriculum/` → show students each day.  
- **Daily Reports**: Students save outputs in `repo/reports/dayX/`.  
- **Exit Tickets**: `assessments/exit_tickets/DayX_ExitTicket.md` → reflection each day.  
- **Final Portfolio**: `repo/reports/final/`.  
- **Tools**: Use `roofline_plot.py` + `Roofline_Template.csv` for plots; run STREAM-like test for bandwidth ceiling.  
- **Accessibility**: Check `guides/UDL_Checklist.md` before teaching.  
- **Teamwork**: Fill out `guides/Team_Charter.md` on Day 0.  
