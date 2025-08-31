# Teaching Offer Scheduler (C)

This is a small C program that parses “teaching offers” from a text file, encodes weekly availability with bit arrays, and generates simple schedule options for each grade level.  

It was originally built as a learning project to practice data structures (linked lists), bit manipulation, and modular program design in C.

---

## Features
- **Compact availability encoding**: 5 school days are represented with an 8-bit mask.
- **Per-grade organization**: Teaching offers are grouped by grade and “times per week.”
- **Schedule options**: Combines one or two offers to propose a feasible weekly schedule.
- **Readable output**: Pretty-printed tables and schedules in the console.

---

## Project Structure
- `scheduler1.h` – Type definitions, constants, and global tables.  
- `main.c` – Entry point; orchestrates reading offers, building bitmaps, scheduling, and printing.  
- `read-offers.c` – Parses offers from the input file and builds data structures.  
- `bitmaps1.c` – Creates bit arrays and `bitmap` nodes for each offer.  
- `scheduler.c` – Generates schedule options per grade.  
- `print-utils1.c` – Utility functions for pretty-printing offers, bitmaps, and schedules.  


---

# Notes tying this to your code

- **Types, constants, globals** come from `scheduler1.h` (grades `G=7`, days `D=5`, `bit_array`, `bitmap`, `p[G][D]`, `option`, `schedule[G]`). :contentReference[oaicite:3]{index=3}  
- **Bit construction & bitmaps**: `createBitArray` makes a mask based on `times` and left-shifts by `position`; `createBitmap` fills `b[D]` and stores `offer_id`; `insertHead` links lists. :contentReference[oaicite:4]{index=4}  
- **Parsing**: `readOffers` and `readOfferLine` tokenize `Teacher(s):Grade:Times:Assistant(s)`, map grades (`gradeIndex`), and fill `p[gradeIndex][times-1]` via `createBitmap`/`insertHead`. Trimming helpers included. :contentReference[oaicite:5]{index=5}  
- **Scheduling**: `createSchedule()` calls `optionsForGrade(p[i])` per grade; `optionsForGrade` demonstrates simple combos like `(2× + 3×)` and `(1× + 4×)`, plus a single `(5×)` case. (It’s a scaffold you can extend.) :contentReference[oaicite:6]{index=6}  
- **I/O & printing**: `printOffer`, `printBinary`, `printBitmap`, `printTable`, `printOption`, `printSchedule` handle console output; `main` wires it together and expects an input filename. :contentReference[oaicite:7]{index=7} :contentReference[oaicite:8]{index=8}
