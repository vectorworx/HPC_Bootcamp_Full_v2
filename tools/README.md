# tools — Plotting & Utilities

## Roofline Plot Helper
- `roofline_plot.py` — Log–log roofline plot from CSV.
- Input template: `references/Roofline_Template.csv`

### Usage
```bash
python tools/roofline_plot.py   --csv references/Roofline_Template.csv   --out roofline.png   --peak-gflops 2000   --mem-bandwidth 200
```
