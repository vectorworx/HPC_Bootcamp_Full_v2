# Using a Custom ChatGPT Assistant — HPC Bootcamp

---

## Purpose
A custom ChatGPT can act as a **teaching assistant** to provide guidance, scaffolding, and rapid Q&A.

---

## Modes
- **Student mode:** practice, hints, debugging
- **Instructor mode:** demo scripts, hinge questions
- **Team mode:** clarifications during labs

---

## Prompt Patterns
- *Student:*  
  “Why didn’t this loop vectorize? [code + compiler output]”  
  “Check my roofline placement: AI=X, BW=Y”

- *Instructor:*  
  “Generate two hinge questions on cache blocking”  
  “Draft a 5-minute demo script for OpenMP scaling”

---

## Guardrails
- Always require students to show **commands + environment**
- Never provide final numeric answers to graded tasks
- Focus on **process, not solutions**
- Encourage reproducibility logging

---

## Setup
- Train custom GPT with: cheat sheets, handouts, rubrics
- Disable web access; restrict to course materials
- Maintain offline mode for secure environments
