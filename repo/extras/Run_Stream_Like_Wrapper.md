# Run Wrapper for STREAM-like Benchmark

**Location:** `repo/extras/run_stream_like.sh`  
**Companion:** `repo/extras/stream_like.c`  
**Reports to:** `repo/reports/day4/stream_like_results.md`

---

## Purpose
This wrapper automates building and running the STREAM-like triad benchmark, then logs results in Markdown for reproducibility.

## Usage
```bash
cd repo/extras
chmod +x run_stream_like.sh
./run_stream_like.sh
```

## Behavior
- Builds `stream_like.c` with `gcc -O3 -march=native -fopenmp`.  
- Runs two experiments:
  1. Default run: N = 100e6, reps = 10, scalar = 3.0  
  2. Half-size run: N = 50e6, reps = 10, scalar = 3.0  
- Logs all results to `repo/reports/day4/stream_like_results.md`.  

## Expected Output (excerpt)
```text
STREAM-like Triad: N=100000000 reps=10 threads=16
Best time: 0.432101 s  Approx BW: 180.25 GB/s
Note: BW ignores RFO/write-allocate traffic; real DRAM BW may be higher.
```

## Extension Ideas
- Add more problem sizes or thread counts to sweep saturation curves.  
- Capture CPU/DRAM info (`lscpu`, `dmidecode -t memory`) into the report.  
- Pass arguments to the wrapper (e.g., N, reps) and append results.  
