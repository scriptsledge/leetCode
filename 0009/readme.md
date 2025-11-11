# 9. Palindrome Number

## Problem Description

Given an integer `x`, return `true` if `x` is a palindrome, and `false` otherwise.

### Example 1:

**Input:** `x = 121`
**Output:** `true`
**Explanation:** `121` reads as `121` from left to right and from right to left.

### Example 2:

**Input:** `x = -121`
**Output:** `false`
**Explanation:** From left to right, it reads `-121`. From right to left, it becomes `121-`. Therefore it is not a palindrome.

### Example 3:

**Input:** `x = 10`
**Output:** `false`
**Explanation:** Reads `01` from right to left. Therefore it is not a palindrome.

### Constraints:

*   `-2^31 <= x <= 2^31 - 1`

**Follow up:** Could you solve it without converting the integer to a string?

## Solution

The solution is implemented in the [`solution.py`](./solution.py) file.

### Approach

The solution manually reverses the integer by extracting each digit and building a new reversed number.

1.  Store the original number `x` in a temporary variable `tempNum`.
2.  Initialize `reverseNum` to 0.
3.  Iterate while `tempNum` is greater than 0:
    *   Get the last digit of `tempNum` using the modulo operator (`% 10`).
    *   Append the last digit to `reverseNum`.
    *   Remove the last digit from `tempNum` using integer division (`// 10`).
4.  Compare the original number `x` with `reverseNum`. If they are equal, the number is a palindrome.

### Code

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # manually reverting number by extracting each digit
        tempNum = x
        reverseNum = 0
        while (tempNum > 0):
            lastDigit = tempNum % 10
            # adding lastDigit to reverseNum
            reverseNum = (reverseNum * 10) + lastDigit
            tempNum = tempNum // 10
        # return the boolean value: x (original number) == reverseNum
        return x == reverseNum
```