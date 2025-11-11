# 921. Minimum Add to Make Parentheses Valid

## Problem Description

A parentheses string is valid if and only if:

- It is the empty string,
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

Return the minimum number of moves required to make `s` valid.

## Solution

The solution is implemented in the [`solution.py`](./solution.py) file.

### Approach

The solution in `main.py` uses a greedy approach to count the minimum number of parentheses to add.

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

### Code

```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        # Count of unmatched opening parentheses needing closing brackets
        unmatched_open = 0
        
        # Count of unmatched closing parentheses needing opening brackets  
        unmatched_close = 0
        
        for char in s:
            if char == '(':
                # Each opening bracket needs a matching closing bracket
                unmatched_open += 1
            else:  # char == ')'
                if unmatched_open > 0:
                    # Match with previous unmatched opening bracket
                    unmatched_open -= 1
                else:
                    # No matching opening bracket, need to add one before
                    unmatched_close += 1
        
        # Total moves = unmatched opening + unmatched closing brackets needed
        return unmatched_open + unmatched_close
```