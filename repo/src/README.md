# repo/src — Baseline Codes

Baseline C programs used across labs.

## Programs
- `matmul.c` — naive matrix multiply (reference baseline)
- `sort.c` — naive sort for complexity comparison
- `nqueens.c` — backtracking search (tasking demo later)

## Build & Run (examples)
```bash
gcc -O0 -std=c11 matmul.c -o matmul
./matmul 256

gcc -O0 -std=c11 sort.c -o sort
./sort 100000

gcc -O0 -std=c11 nqueens.c -o nqueens
./nqueens 12
```

> Keep Day 1 builds at **-O0** to capture true baselines. Optimization comes later.
