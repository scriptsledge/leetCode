# 921. Minimum Add to Make Parentheses Valid

## Problem Description

A parentheses string is valid if and only if:

- It is the empty string,
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

Return the minimum number of moves required to make `s` valid.

## Solution

The solution in `main.py` uses a greedy approach to count the minimum number of parentheses to add.

### Approach

1. Traverse the string while keeping track of unmatched opening `(` and closing `)` parentheses.
2. For each `(`, increment the count of unmatched opening parentheses.
3. For each `)`, if there's an unmatched `(`, decrement the unmatched opening count (matching them); otherwise, increment the unmatched closing count.
4. The total moves needed are the sum of unmatched opening and closing parentheses.

### Example

```python
s = "())"
# Process:
# '(' -> unmatched_open = 1
# ')' -> matches '(', unmatched_open = 0
# ')' -> no match, unmatched_close = 1
# Result: 0 + 1 = 1
```