# Makefile — Solution Keys Wrapper

```
# Solution Keys Makefile
CC ?= gcc
CFLAGS ?= -O3 -march=native -fopenmp -std=c11 -Wall -Wextra -Wno-unused-parameter
LDFLAGS ?= 
BLAS_LIBS ?= -lopenblas
CBLAS ?= 0

all: matmul_blocked matmul_openmp nqueens_tasks sort_optimized

matmul_blocked: matmul_blocked.c common.h
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

matmul_openmp: matmul_openmp.c common.h
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

nqueens_tasks: nqueens_tasks.c common.h
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

sort_optimized: sort_optimized.c common.h
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Optional BLAS target
ifeq ($(CBLAS),1)
matmul_blas: matmul_blas.c common.h
	$(CC) $(CFLAGS) -DUSE_CBLAS $< -o $@ $(BLAS_LIBS) $(LDFLAGS)
else
matmul_blas:
	@echo "Skipping matmul_blas (set CBLAS=1 and BLAS_LIBS to build)"
endif

clean:
	rm -f matmul_blocked matmul_openmp matmul_blas nqueens_tasks sort_optimized

```
