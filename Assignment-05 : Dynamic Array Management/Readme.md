# Assignment-05 : Dynamic Array Management

## Objective

To learn Dynamic Memory Allocation using malloc() and free().

## Problem Statement

Create a program that dynamically allocates memory for storing student marks using malloc(). Display the marks, calculate highest, lowest, total and average marks, and release the allocated memory using free().

## Algorithm

1. Read the number of students.
2. Allocate memory using malloc().
3. Input student marks.
4. Display all marks.
5. Calculate:
   - Highest Marks
   - Lowest Marks
   - Total Marks
   - Average Marks
6. Release memory using free().

## Time Complexity

Memory Allocation : O(1)

Display : O(n)

Statistics : O(n)

Memory Deallocation : O(1)

## Space Complexity

O(n)

## Sample Input

5

80 65 90 72 88

## Sample Output

Student Marks

80 65 90 72 88

Highest Marks : 90

Lowest Marks : 65

Total Marks : 395

Average Marks : 79.00

Memory Released Successfully.

## Learning Outcome

- Dynamic Memory Allocation
- malloc()
- free()
- Pointers
- Arrays
- Functions