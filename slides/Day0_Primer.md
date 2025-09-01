# HPC Bootcamp — Day 0: Primer & Orientation

---

### Welcome & Orientation
- Course: **HPC Bootcamp — From C to Performance Computing**
- Audience: Experienced C programmers, new to HPC
- Goal: Prepare for advanced HPC project work
- Context: **National security, mission-critical**

---

### Bootcamp Roadmap
- **Day 0:** Primer (tools, reproducibility, contract)
- **Day 1:** Baseline measurement & roofline placement
- **Day 2:** Algorithmic upgrades & data layout
- **Day 3:** SIMD & OpenMP
- **Day 4:** Memory hierarchy & compiler power-ups
- **Day 5:** Scaling & capstone defense

---

### The HPC Mindset
- Always **measure before changing code**
- **Correctness > speed**
- Optimize in **layers**  
  Algorithm → Layout → SIMD → OpenMP → Memory/Compiler
- **Evidence > opinion**  
  Counters, plots, reproducibility

---

### Tools You’ll Use
- Compiler: `gcc` or `icc` with optimization flags
- Profilers: `perf`, HPCToolkit
- Libraries: BLAS/qsort
- OpenMP for threading
- Scripts: bandwidth probe, affinity checks

---

### Reproducibility Contract
- One change at a time
- Record **commands, flags, environment**
- Share **both successes and failures**
- Outputs must be **correct + reproducible**

---

### Sanity Scripts
Run these before labs:
```bash
./scripts/run_baseline.sh
./scripts/bandwidth_probe.sh
./scripts/sanity_affinity.sh
```

---

### End of Day-0 Goals
- Tools installed and verified
- Students sign reproducibility contract
- Team roles assigned (Driver/Navigator/Recorder/Presenter)
- Ready to measure baselines tomorrow
