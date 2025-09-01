# Visualization Aids — HPC Bootcamp

---

## Roofline Model
- X-axis = Arithmetic Intensity (FLOPs/Byte)
- Y-axis = Performance (GFLOP/s)
- Two lines:
  - Sloped line = memory bandwidth limit
  - Flat line = peak compute
- Kernel placement shows bottleneck:
  - On slope → memory-bound
  - Below flat line → compute-bound

---

## Scaling Plots
- **Strong scaling:** runtime vs cores (ideal ~1/N)
- Efficiency = (speedup / #cores)
- **Weak scaling:** runtime vs cores (ideal ~flat)

---

## NUMA Diagrams
- NUMA = Non-Uniform Memory Access
- Each socket has local memory
- Remote access → higher latency
- Visual: two sockets, cross-links

---

## Thread Affinity
- Binding threads to cores
- Prevents migration overhead
- Example: 4 threads bound to 4 physical cores
