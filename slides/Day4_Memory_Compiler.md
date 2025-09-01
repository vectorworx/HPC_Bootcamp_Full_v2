# HPC Bootcamp — Day 4: Memory & Compiler Power-Ups

---

### Objectives
- Explore NUMA effects and affinity
- Apply compiler optimizations (O3, LTO, PGO)
- Profile performance with tools
- Evaluate performance vs energy (perf-per-watt)

---

### Step 1: NUMA Binding
- Use `numactl` or OpenMP places
```bash
numactl --cpunodebind=0 ./matmul
```
- Compare runtime local vs remote memory

---

### Step 2: Compiler Flags
- `-O3 -march=native` → aggressive optimization
- **LTO (Link-Time Optimization)**: `-flto`
- **PGO (Profile-Guided Optimization)**:
```bash
gcc -fprofile-generate -O3 app.c -o app
./app
gcc -fprofile-use -O3 app.c -o app
```

---

### Step 3: Profiling
- Use `perf record` / `perf report`
- Optional: HPCToolkit, Intel VTune
- Identify hotspots and instruction mix

---

### Step 4: Energy Efficiency (Optional)
- Measure energy counters via RAPL
```bash
perf stat -e power/energy-pkg ./matmul
```
- Compute GFLOP/J (performance per watt)

---

### Team Deliverables
- NUMA experiment results
- Before/after compiler flags runtime
- Profiling output (hotspot summary)
- Perf-per-watt discussion

---

### End of Day-4 Goals
- NUMA locality effects understood
- Compiler optimizations applied with evidence
- Hotspots identified via profiling
- Awareness of energy-performance tradeoffs
