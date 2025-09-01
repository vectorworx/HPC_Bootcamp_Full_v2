# Hinge Question Bank — HPC Bootcamp

---

## Day 1
**Q1:** If IPC increases but runtime doesn’t improve, most likely cause?  
A) Front-end stalls  
B) **Memory bandwidth saturation** ✅  
C) Branch mispredicts  
D) Hyper-threading off  

**Q2:** On roofline, if kernel lies on sloped line, best first optimization?  
A) Wider SIMD  
B) Higher frequency  
C) **Increase data reuse (tiling)** ✅  
D) Loop unrolling  

---

## Day 2
**Q1:** Which algorithm improves sort from O(n²) to O(n log n)?  
A) Bubble sort  
B) **Quick/Merge sort** ✅  
C) Linear scan  
D) Hashing  

**Q2:** Cache-blocking improves performance by…  
A) Reducing arithmetic intensity  
B) **Improving temporal locality** ✅  
C) Increasing branch prediction accuracy  
D) Improving network bandwidth  

---

## Day 3
**Q1:** Why might OpenMP tasking slow N-Queens?  
A) Too few tasks  
B) **Tasks too fine-grained** ✅  
C) Not enough memory  
D) Compiler bug  

**Q2:** A loop didn’t vectorize. Fix?  
A) **Add restrict/alignment** ✅  
B) Use fewer iterations  
C) Disable O3  
D) Add printf  

---

## Day 4
**Q1:** NUMA performance drops usually occur when…  
A) Threads access local memory  
B) **Threads access remote memory** ✅  
C) Cache lines align  
D) SIMD width increases  

**Q2:** Which optimization requires profiling runs?  
A) -O3  
B) LTO  
C) **PGO** ✅  
D) -march=native  

---

## Day 5
**Q1:** In strong scaling, runtime ideally decreases…  
A) **Linearly with cores** ✅  
B) Logarithmically  
C) Quadratically  
D) Not at all  

**Q2:** MPI_Allreduce is used to…  
A) Send data from one process to another  
B) Synchronize barriers  
C) **Reduce values across processes and distribute result** ✅  
D) Print from all ranks  
