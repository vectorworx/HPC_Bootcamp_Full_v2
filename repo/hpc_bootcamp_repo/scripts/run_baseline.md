# Run Baseline Script — Source Code

```bash
#!/bin/bash
gcc -O0 src/matmul.c -o matmul
gcc -O0 src/sort.c -o sort
gcc -O0 src/nqueens.c -o nqueens
./matmul 256
./sort 1000
./nqueens 12
```
