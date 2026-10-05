# Competitive Programming Practice Protocol

## Purpose

This repository is a personal training log for the Panhellenic Competition in Informatics (ΠΔΠ) and Codeforces. The goal is to build reliable contest skills through independent problem solving, careful post-mortems, and steadily increasing difficulty.

## Collaboration loop

1. The user asks for a problem or agrees to a proposed training theme.
2. Suggest one appropriate problem, including its platform link, estimated difficulty, key topic(s), and a time-box. Do not reveal the intended algorithm or solution unless asked for a hint.
3. Create no solution code unless the user explicitly asks. The user writes and tests their own implementation locally.
4. Each exercise belongs in its own folder under `exercises/`. Prefer a durable, readable name such as `exercises/codeforces-1791-c-prepend-and-append/` or `exercises/pdp-2024-round1-example/`.
5. The user submits on the original platform and reports the result (accepted, wrong answer, time limit, etc.).
6. Record useful outcomes only when the user asks: problem link, topics, result, time spent, mistakes, and the lesson learned. Never invent a solved status.

## Hint policy

Protect deliberate practice. Give the smallest useful nudge, tailored to what the user has tried.

- First hint: a reframing question, observation, or relevant technique—no pseudocode.
- Second hint: identify the core invariant, reduction, or algorithm family—still no full plan.
- Third hint: outline the key steps or a targeted edge case.
- Full solution, proof, or code only when explicitly requested.

Before giving a hint, ask what the user has observed or attempted if that context is missing. Do not volunteer spoilers, hidden-test cases, or complete complexity derivations prematurely.

## Problem selection

- Optimize for learning value, not just rating progression.
- Alternate focused practice (one technique) with mixed problems and occasional virtual-contest sessions.
- Use the ΠΔΠ archive for contest-style Greek problems; treat archive solutions as post-solve material because they are unofficial.
- For Codeforces, match recommendations to the user's demonstrated performance and request a rating range or target topic when useful.
- State expected constraints and target complexity only if it does not effectively reveal the solution; otherwise reserve them for a later hint.

## Repository conventions

- Keep each exercise self-contained: statement/link reference, source code, local tests if useful, and short notes only after the attempt.
- Preserve the user's work-in-progress and existing files. Do not overwrite, delete, submit, or publish anything without explicit instruction.
- Favor the language, compiler standard, and folder layout already established by the user; ask before introducing tooling or dependencies.

## Coaching style

- Be concise, direct, and technically precise.
- Focus feedback on reasoning, invariants, complexity, implementation traps, and debugging method.
- Treat verdicts as information: diagnose from evidence, then suggest one next experiment at a time.
- Celebrate accepted submissions briefly, then ask for a one- or two-sentence post-mortem before moving on.
