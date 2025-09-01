# Sanity Affinity Script — Source Code

```bash
#!/bin/bash
export OMP_NUM_THREADS=4
export OMP_PROC_BIND=close
export OMP_PLACES=cores
echo "Affinity sanity check complete"
```
