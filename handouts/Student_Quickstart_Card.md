# Student Quickstart Card — HPC Bootcamp

---

## Top 10 Rules for Success
1. Measure before you change code
2. Correctness first, speed second
3. Optimize in layers (Algo → Layout → SIMD → Threads → Compiler)
4. Record commands, flags, environment
5. Use libraries before reinventing kernels
6. Evidence beats opinion — always show data
7. Run multiple reps for stable numbers
8. Plot results whenever possible
9. Work as a team, rotate roles daily
10. Document failures as well as successes

---

## Daily Commands Cheat Sheet
- **Build baseline:**
```bash
./scripts/run_baseline.sh
```

- **Probe bandwidth:**
```bash
./scripts/bandwidth_probe.sh
```

- **Check thread affinity:**
```bash
./scripts/sanity_affinity.sh
```

- **Collect perf counters:**
```bash
perf stat -e cycles,instructions,cache-misses ./app
```

- **Roofline arithmetic intensity:**
```bash
# AI = FLOPs / Bytes_moved
```
