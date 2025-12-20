# Push_Swap

*This project has been created as part of the 42 curriculum by <rcompain>.*

## Sommary

- [Description](#description)
- [Instructions](#instructions)
  - [Compilation](#compilation)
  - [Execution](#execution)
- [Allowed Operations](#allowed-operations)
- [Algorithm Overview](#algorithm-overview)
  - [Index Mapping](#index-mapping)
  - [Small Stack Optimization](#small-stack-optimization)
  - [Chunk-Based Push to Stack B (Butterfly Algorithm)](#chunk-based-push-to-stack-b-butterfly-algorithm)
  - [Cost Calculation and Reinsertion into Stack A](#cost-calculation-and-reinsertion-into-stack-a)
  - [Instruction Storage and Optimization](#instruction-storage-and-optimization)
  - [Final Rotation and Output](#final-rotation-and-output)
- [Error Handling](#error-handling)
- [Resources](#resources)

## Description

**Push_swap** is an algorithmic project whose goal is to sort a stack of 
integers using a limited set of instructions and the smallest possible 
number of operations.

The program receives a list of integers as arguments, places them into a 
stack called **stack A**, and sorts them in ascending order using an 
auxiliary stack (**stack B**). Only a specific set of stack operations is 
allowed, making this project a challenge in algorithm design, optimization, 
and data structure manipulation.

The main objective is not only to sort the numbers correctly, but also 
to do so efficiently, by minimizing the total number of operations.

---

## Instructions

### Compilation

To compile this project, run:

```bash
make
```

This will generate an executable named:

```text
push_swap
```

To clean objects files:

```bash
make clean
```

To remove the executable and objects files:

```bash
make fclean
```

To remove all and recompile:

```bash
make re
```
---

### Execution

Run the program with a list of integers arguments:

```bash
./push_swap 3 2 1
```
The program will output a sequence of instructions that sorts the stack.

## Allowed operations

The program uses the following operations:

* `sa` -> swap the first two elements of stack a.
* `pa`, `pb` -> push elements between stacks.
* `ra`, `rb`, `rr` -> rotate stack a or b or same time.
* `rra`, `rrb`, `rrr` reverse rotate stack a or b or same time.

---

## Algorithm Overview

The algorithm is structured into multiple stages to ensure both correctness and
operation efficiency.

### Index Mapping

All values from **stack A** are first converted into a normalized index range.
This mapped version of the stack, referred to as **map**, allows the algorithm to
operate on relative ordering rather than raw integer values, simplifying comparisons
and decision-making.

### Small Stack Optimization

If the size of **stack A** is less than or equal to 5, a dedicated **tiny_sort**
algorithm is used.
This specialized sorting logic guarantees an optimal number of operations for small
inputs.

### Chunk-Based Push to Stack B (Butterfly Algorithm)

For larger inputs, all elements from **stack A** are pushed to **stack B** using a
chunk-based strategy, commonly known as the **butterfly algorithm**.

- The mapped values are divided into chunks
- Elements belonging to the current chunk are pushed from **stack A** to **stack B**
- The lower half of each chunk is pushed using `pb`
- The upper half is pushed using `pb` followed by `rb`

This technique spreads values evenly inside **stack B**, preparing it for efficient
reinsertion into **stack A**.

### Cost Calculation and Reinsertion into Stack A

To move values back from **stack B** to **stack A**, the algorithm computes the cost
of reinsertion for each element in **stack B**.

For every value, all possible rotation scenarios are evaluated:

- `ra` + `rb`
- `rra` + `rrb`
- `ra` + `rrb`
- `rra` + `rb`

The element with the lowest total cost is selected and pushed back into **stack A**.
This process is repeated until **stack B** is empty.

### Instruction Storage and Optimization

All generated operations are stored in a linked list during execution.
Once the sorting logic is complete, this list is optimized by:

- Merging compatible rotations into `rr`
- Merging reverse rotations into `rrr`
- Removing redundant instruction pairs such as `pb` followed immediately by `pa`

This optimization phase reduces the total number of operations without altering the
sorting result.

### Final Rotation and Output

After all elements have been reinserted, **stack A** is rotated to place the smallest
value at the top.

Finally, the optimized list of instructions is written to standard output (`stdout`),
representing the final solution.

---

## Error Handling

The program handles the following errors :

* Non-numeric arguments.
* Duplicates numbers.
* Integer overflow/underflow.
* Invalid input format.

In caseof an error, the program outputs:

```text
Error
```

---

## Resources

* 42 Subject PDF: *Push_swap*.
* Excalidraw for brainstorming and structuring ideas.
* Understanding the different types of algorithms. [Algomius](https://www.youtube.com/@algomius) on Youtube.
* The 42 following students for the time spent discussing ideas, algorithms,
and optimization strategies:
    - <Pchasam>, 
    - <Bamagere>,
    - <Tseche>
* AI was used to further research and deepen understanding of new concepts.

