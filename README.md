*This project has been created as part of the 42 curriculum by aakhmeto*

# Push Swap

## Description
push_swap is a program that sorts a stack of integers using only a limited set
of operations on two stacks (A and B). The goal is to produce the smallest
number of operations for each input.

Allowed operations (each line printed counts as 1 move; `ss`, `rr`, `rrr` are
single moves even though they act on both stacks):
- `sa`: swap the first 2 elements of stack A.
- `sb`: swap the first 2 elements of stack B.
- `ss`: `sa` and `sb` at the same time.
- `pa`: push the top element from B to A.
- `pb`: push the top element from A to B.
- `ra`: rotate A (first element becomes last).
- `rb`: rotate B (first element becomes last).
- `rr`: `ra` and `rb` at the same time.
- `rra`: reverse rotate A (last element becomes first).
- `rrb`: reverse rotate B (last element becomes first).
- `rrr`: `rra` and `rrb` at the same time.

Benchmarks for maximum score (subject requirements):
- 100 random numbers: fewer than 700 operations.
- 500 random numbers: no more than 5500 operations.

## Instructions

### Build
```bash
make
```

Other make targets:
```bash
make bonus    # builds checker if bonus is implemented
make clean    # removes object files
make fclean   # removes objects and binaries
make re       # full rebuild
```

### Run
```bash
./push_swap 3 2 1
```

The program prints the list of operations to stdout. You can verify the result
with the checker (if available in your setup).

### Checker (manual)
If you have a checker binary (bonus or provided by the subject):
```bash
./push_swap 3 2 1 | ./checker 3 2 1
```
On Linux with the provided binary:
```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

## Theory Notes

### Stack Basics
- Stack is a LIFO structure: last in, first out.
- `top` is the element where operations are applied.
- `bottom` is the oldest element in the stack.
- `push` moves the top element from one stack to the other.
- `pop` removes the top element (for push_swap this is done by `push`).

### Invariants
- All values must be unique (subject rules).
- The total number of elements across A and B stays constant.
- After sorting, stack A is in ascending order and stack B is empty.

### Indexing
Instead of sorting raw values, each value can be replaced by its index in the
sorted order. This makes comparisons simpler and keeps values in a small range.

### Complexity
- Big-O describes how work grows when input size `n` grows.
- O(1): constant time, does not grow with `n`.
- O(log n): grows slowly (e.g., binary search).
- O(n): linear, proportional to `n`.
- O(n log n): common for good sorts (merge sort, heap sort).
- O(n^2): slow for big `n` (simple sorts like insertion/selection).
- For small inputs, O(n^2) can still be fine.
- For large inputs, aim for O(n log n) strategies.

### Merge Sort (used for indexing)
- Merge sort splits the array into halves, sorts each half, then merges them.
- It always runs in O(n log n) time.
- It needs extra memory for merging.
- In this project it is used to sort values before assigning indexes.

### Binary Search (used for indexing)
- Binary search works on a sorted array.
- It cuts the search space in half each step.
- Time complexity is O(log n).
- Here it helps find the index of a value in the sorted array.

### LIS (Longest Increasing Subsequence)
- LIS is the longest subsequence that is already in increasing order.
- We keep LIS in stack A and move the rest to stack B.
- This reduces the number of moves needed later.
- LIS is computed with dynamic programming here.

### Pivot Grouping (not fixed-size chunks)
- This project does not use classic fixed-range "chunks".
- Instead, it splits non-LIS values using a single pivot (median).
- While pushing to B, values above the pivot are rotated to the bottom of B.
- This keeps B in a better order for cheaper push back.

### Cost (Greedy Choice)
- "Cost" is the number of rotations needed to place an element correctly.
- We compute rotations for A and B and pick the smallest total cost.
- This is a greedy step: always choose the cheapest move now.


## Resources
- 42 push_swap subject (project description and constraints).
- Algorithms: CLRS (Cormen, Leiserson, Rivest, Stein).
- Merge sort: `https://en.wikipedia.org/wiki/Merge_sort`
- Binary search: `https://en.wikipedia.org/wiki/Binary_search_algorithm`
- LIS (greedy / patience sorting): `https://en.wikipedia.org/wiki/Longest_increasing_subsequence`
- Greedy algorithm: `https://en.wikipedia.org/wiki/Greedy_algorithm`
- Median / pivot idea: `https://en.wikipedia.org/wiki/Median`
- Sorting overview: `https://en.wikipedia.org/wiki/Sorting_algorithm`
- Searching overview: `https://en.wikipedia.org/wiki/Search_algorithm`

### AI Usage
AI was used only to edit this README: translate Russian notes to English, expand instructions, add resource links, explain some concepts, and provide advice on project structure and on proper naming of folders, files, functions, and commit messages in English.

## Algorithm (very simple explanation)
Below is a simplified view of the current sorting strategy in this project.
The explanation is intentionally basic.

### Terms
- Stack: like a pile of plates; you can only take the top.
- A and B: two stacks used to reorder numbers.
- Index: position of a value in sorted order (smallest = 0).
- LIS: longest increasing subsequence (already-in-order part).
- Pivot: a middle value used to split elements when pushing to B.
- Cost: number of moves needed to place a value.
- rr/rrr: rotating both stacks together is cheaper than separately.

### Core idea
This describes the **big sort** strategy (for large inputs).

1) Compute LIS (longest increasing subsequence) on indexes in stack order.
2) Build a flags array: `1` if index is in LIS, `0` otherwise.
3) Collect all non-LIS indexes into an array.
4) Sort that array and take the middle element -> **pivot** (median).
5) Iterate exactly `size(A)` times over the current A:
6) If top of A is in LIS -> `ra` (keep it in A).
7) Else -> `pb` (move to B).
8) After `pb`, if the moved index > pivot -> `rb` (push big values down).
9) When all non-LIS are in B, start moving back to A.
10) For each element in B, compute its target position in A:
11) Find the first index in A that is greater than this element.
12) If none is greater, target is the smallest index in A.
13) Convert that target into a position `pos_a` (0 = top).
14) Convert the element's place in B into `pos_b` (0 = top).
15) Compute `rot_a` = rotations to bring `pos_a` to top (ra/rra).
16) Compute `rot_b` = rotations to bring `pos_b` to top (rb/rrb).
17) Compute total cost:
18) If `rot_a` and `rot_b` have the same sign, merge part of them as `rr`/`rrr`.
19) `total_cost` is the number of operations after merging.
20) Repeat steps 10–19 for **all** elements in B.
21) Pick the element with the smallest `total_cost`.
22) Apply combined rotations (`rr`/`rrr`) while both rotations share direction.
23) Finish remaining rotations for A (`ra`/`rra`).
24) Finish remaining rotations for B (`rb`/`rrb`).
25) Do `pa` to insert the chosen element into A.
26) Go back to step 10 (recompute costs) until B is empty.
27) Finally rotate A so the smallest index is on top.

### Metaphor
Imagine arranging books by height on a shelf (A).
Some books are already in order (LIS) — do not touch them.
The rest go into a box (B), then return one by one, always picking the book
that is easiest to place correctly.

### Example with 6 numbers
Numbers: 6 1 4 2 5 3  
Indexes: 5 0 3 1 4 2  
LIS (one possible): 0 3 4 -> stay in A.  
Others (5, 1, 2) go to B.  
Pivot = median of non-LIS indexes [1, 2, 5] -> pivot = 2.

Return phase (short version):
1) Pick the cheapest element in B (not always the top).
2) Rotate A so the target position for that element is on top.
3) Rotate B so that element is on top.
4) Use `rr`/`rrr` when both rotations go the same way.
5) `pa` inserts the element into A.
6) Repeat with new costs until B is empty.
Finally rotate A so index 0 is on top.

Cost example (simple numbers):
After pushing non-LIS, one possible state is:
- A (top -> bottom): [0, 3, 4]
- B (top -> bottom): [2, 1, 5]

Take element `2` from B:
- Target in A is the first index bigger than 2 -> `3`.
- Position of `3` in A is `pos_a = 1`, so `rot_a = +1` (one `ra`).
- Position of `2` in B is `pos_b = 0`, so `rot_b = 0`.
- Total cost is `max(|1|, |0|) = 1` (same direction or zero).

So we do `ra`, then `pa`, and A becomes:
- A: [2, 3, 4, 0]
- B: [1, 5]

Then we recompute costs for the new A and B and repeat.

## Small input strategies (2 to 5)
Simple dedicated routines are used for very small sizes.

- 2 numbers: if top > next, do `sa`.
- 3 numbers: check the order of top/middle/bottom and apply a minimal combo
  of `sa`, `ra`, `rra`.
- 4 numbers: bring the smallest to top, `pb`, sort 3 in A, then `pa`.
- 5 numbers: push two smallest to B, sort 3 in A, fix order in B if needed,
  then `pa` `pa`.
