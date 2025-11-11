# 2520. Count the Digits That Divide a Number

## Problem Description

Given an integer `num`, return the number of digits in `num` that divide `num`.

An integer `val` divides `nums` if `nums % val == 0`.

### Example 1:

**Input:** `num = 7`
**Output:** `1`
**Explanation:** 7 divides itself, hence the answer is 1.

### Example 2:

**Input:** `num = 121`
**Output:** `2`
**Explanation:** 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.

### Example 3:

**Input:** `num = 1248`
**Output:** `4`
**Explanation:** 1248 is divisible by all of its digits, hence the answer is 4.

### Constraints:

*   `1 <= num <= 10^9`
*   `num` does not contain `0` as one of its digits.

## Solution

The solution is implemented in the [`solution.py`](./solution.py) file.

### Approach

The solution iterates through each digit of the number and checks if the digit divides the original number.

1.  Initialize `count` to 0.
2.  Create a temporary variable `number` to store the value of `num`.
3.  Iterate while `number` is greater than 0:
    *   Extract the last digit using the modulo operator (`% 10`).
    *   Check if the original number `num` is divisible by the `lastDigit`.
    *   If it is, increment `count`.
    *   Remove the last digit from `number` using integer division (`// 10`).
4.  Return `count`.

### Code

```python
class Solution:
    def countDigits(self, num: int) -> int:
        # copying the input
        number = num
        count = 0

        while (number > 0):
            # extract last digit with % operator
            lastDigit = number % 10
            if (num % lastDigit == 0):
                count += 1
            # eleminate lastDigit by floor division with 10
            number = number // 10

        return count
```
