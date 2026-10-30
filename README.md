*This project has been created as part of the 42 curriculum by dahanlon, jmarin-l.*

# Push_swap

## Description

**Push_swap** is an algorithmic project at 42. The goal is simple: sort a list of unique integers in ascending order using two stacks (**Stack A** and **Stack B**) and a limited set of allowed operations, producing the smallest number of moves possible.

At the start, all numbers are placed in Stack A, while Stack B is empty. By carefully planning moves - such as swapping the top elements, pushing elements between stacks, and rotating elements up or down - the program figures out an efficient sequence of operations to achieve a fully sorted Stack A.

In addition to basic sorting, this version includes:
- **Disorder measurement**: Measuring how disorganised the input is before making any moves.
- **Multiple strategies**: Supporting four distinct algorithms ($O(n^2)$, $O(n\sqrt{n})$, $O(n \log n)$, and Adaptive).
- **Benchmark mode (`--bench`)**: Displaying statistics such as disorder level, strategy chosen, and detailed operation counts.
- **Bonus Checker**: A verification tool to confirm whether a given sequence of operations actually sorts the numbers correctly.

---

## Instructions

### Compilation

Build the project using the provided `Makefile`:

```bash
# Compile push_swap
make

# Compile the bonus checker
make bonus

# Clean object files
make clean

# Remove all compiled binaries and objects
make fclean

# Recompile everything
make re
```

### Execution

Run `push_swap` with a list of integers as separate arguments or as a quoted string:

```bash
# Basic run (uses the Adaptive strategy by default)
./push_swap 4 67 3 87 23

# Quoted string argument
./push_swap "4 67 3 87 23"
```

#### Strategy Flags

You can specify a strategy flag before your numbers:

| Flag | Strategy | Complexity Class |
|---|---|---|
| `--adaptive` | Default. Selects strategy based on disorder level | $O(n)$, $O(n\sqrt{n})$, or $O(n \log n)$ |
| `--simple` | Selection sort | $O(n^2)$ |
| `--medium` | Chunk sort | $O(n\sqrt{n})$ |
| `--complex` | Radix sort | $O(n \log n)$ |

#### Benchmark Mode (`--bench`)

Adding `--bench` outputs detailed sorting statistics to `stderr`:

```bash
./push_swap --bench --adaptive 5 4 3 2 1
```

*Example output:*
```text
[bench] disorder:   100.00%
[bench] strategy:   Adaptive / O(n log n)
[bench] total_ops:  25
[bench] sa: 0 sb: 0 ss: 0 pa: 10 pb: 10
[bench] ra: 5 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0
```

#### Running the Checker (Bonus)

The `checker` program takes the initial numbers, reads sorting operations from standard input, and validates the result:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Outputs: OK (if sorted) or KO (if not sorted)
```

---

## Algorithms & Strategy Selection

### 1. Disorder Metric

Before taking any action, the program measures the input's **disorder**:
$$\text{Disorder} = \frac{\text{mistakes}}{\text{total pairs}}$$
- A "mistake" is any pair where a larger number appears before a smaller number.
- `0.0% (0.00)` means the numbers are already completely sorted.
- `100.0% (1.00)` means the numbers are in completely reverse order.

### 2. Implemented Strategies

* **Simple ($O(n^2)$)**:
  Repeatedly searches for the smallest remaining number in Stack A, moves it to the top using rotations, and pushes it to Stack B. Once Stack A is empty, all elements are pushed back in sorted order.
* **Medium ($O(n\sqrt{n})$)**:
  Divides normalised values into sliding windows (chunks) of size proportional to $\sqrt{n}$. Elements falling within the current window are pushed to Stack B, and Stack B is rotated to keep larger elements near the top. Finally, elements are pushed back into Stack A in descending order.
* **Complex ($O(n \log n)$)**:
  Implements a binary Least Significant Digit (LSD) Radix Sort. Numbers are first assigned normalised index values ($0$ to $n-1$). For each bit position:
  - If the bit is `0`, the element is pushed to Stack B (`pb`).
  - If the bit is `1`, the element stays in Stack A and rotates (`ra`).
  - All elements from Stack B are pushed back to Stack A (`pa`).
  This process repeats for the maximum number of bits required to represent $n-1$.

### 3. Adaptive Strategy & Threshold Rationale

The adaptive strategy chooses the most practical method based on the input disorder:

| Disorder Range | Regime | Selected Technique | Time Complexity |
|---|---|---|---|
| **$< 0.20$** ($< 20\%$) | Low Disorder | Targeted linear insertion / rotation | $O(n)$ |
| **$0.20 \le D < 0.50$** ($20\% - 50\%$) | Medium Disorder | Chunk sort | $O(n\sqrt{n})$ |
| **$\ge 0.50$** ($\ge 50\%$) | High Disorder | Binary Radix sort | $O(n \log n)$ |

**Rationale**:
- **Low Disorder ($< 20\%$)**: When numbers are nearly sorted, full partitioning is unnecessary; the few misplaced elements can be extracted and placed directly in linear moves.
- **Medium Disorder ($20\% - 50\%$)**: Chunk sorting gives an optimal balance between low operation count (averaging under 600 operations for 100 numbers and around 5,200 for 500 numbers) and low algorithmic overhead.
- **High Disorder ($\ge 50\%$)**: Heavily scrambled or reverse-ordered data benefits from Radix Sort's strictly bounded operation guarantee ($2n \times \lceil\log_2 n\rceil$), avoiding worst-case behavior.

**Complexity Arguments**:
- **Time Complexity**: Refers to the total count of Push_swap instructions. Simple runs in $O(n^2)$ operations, Medium runs in $O(n\sqrt{n})$ operations, and Complex runs in $O(n \log n)$ operations.
- **Space Complexity**: Auxiliary memory is $O(1)$ during execution. Stacks are represented as doubly linked lists consuming $O(n)$ heap space for $n$ nodes.

---

## Team Contributions

This project was developed collaboratively by **jmarin-l** and **dahanlon**:

- **jmarin-l**:
  - Core stack operation functions (`swap`, `push`, `rotate`, `reverse rotate`).
  - Disorder metric calculation function (`compute_disorder`).
  - Simple algorithm ($O(n^2)$ selection sort).
  - Medium algorithm ($O(n\sqrt{n})$ chunk sort).
  - Benchmark module (`--bench` metric collection and formatting).
  - Initial bonus checker pipeline setup.

- **dahanlon**:
  - Unified command-line argument parser (supporting plain and quoted argument lists, syntax validation, duplicate checks, integer overflow checks).
  - Stack linked-list data structures and memory cleanup.
  - Complex algorithm ($O(n \log n)$ Radix Sort implementation).
  - Adaptive algorithm integration and routing logic.
  - Bonus checker input parsing, error exit codes, and memory leak prevention.

Both team members contributed to testing edge cases, 42 Norm compliance, and memory leak auditing under Valgrind.

---

## Resources & AI Usage

### References
- **Radix Sort & Sorting Algorithms**: Introduction to Algorithms (CLRS) and standard literature on non-comparative integer sorting, Stack Exchange and other online resources.
- **Chunk Sorting Mechanics**: 42 community articles and guides on push_swap chunking and two-stack optimisation.
- **GNU Make & C Standard Library**: Man pages for `read`, `write`, `malloc`, `free`, and `limits.h`.

### AI Assistance Disclosure
AI assistance was consulted during development for:
1. **Algorithmic Review**: Explaining the mathematical intuition behind LSD Radix sorting and verifying time complexity classifications within the Push_swap stack model.
2. **Debugging & Edge Cases**: Identifying memory leaks in the bonus `get_next_line` loop, catching flag string typos, and verifying non-zero exit codes on malformed inputs.
3. **Architecture Guidance**: Assisting with function distribution across source files to maintain strict 42 Norm compliance (maximum 5 functions per file and 25 lines per function) and resolving Makefile linker dependencies between `push_swap` and `checker`.
