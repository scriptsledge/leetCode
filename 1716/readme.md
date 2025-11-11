# 1716. Calculate Money in Leetcode Bank

## Problem Description

Hercy deposits money in a LeetCode bank. He starts by putting in `$1` on Monday, the first day. Every day from Tuesday to Sunday, he will put in `$1` more than the day before. On every subsequent Monday, he will put in `$1` more than the previous Monday.

Given `n`, the number of days he will deposit money, return the total amount of money he will have in the bank.

### Example 1:

**Input:** `n = 4`
**Output:** `10`
**Explanation:**
- Day 1 (Monday): $1
- Day 2 (Tuesday): $2
- Day 3 (Wednesday): $3
- Day 4 (Thursday): $4
Total: `1 + 2 + 3 + 4 = 10`

### Example 2:

**Input:** `n = 10`
**Output:** `37`
**Explanation:**
- Week 1: `1 + 2 + 3 + 4 + 5 + 6 + 7 = 28`
- Week 2 (starting Monday): `2 + 3 + 4 = 9`
Total: `28 + 9 = 37`

### Example 3:

**Input:** `n = 20`
**Output:** `96`
**Explanation:**
- Week 1: `28`
- Week 2: `2 + 3 + 4 + 5 + 6 + 7 + 8 = 35`
- Week 3 (starting Monday): `3 + 4 + 5 + 6 + 7 + 8 = 33`
Total: `28 + 35 + 33 = 96`

### Constraints:

*   `1 <= n <= 1000`

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The solution calculates the total money based on the number of full weeks and remaining days.

1.  **Calculate Full Weeks and Remaining Days:**
    *   `fullWeeks = n / 7`
    *   `remainingDays = n % 7`

2.  **Calculate Money from Full Weeks:**
    *   The first week's sum is `1 + 2 + ... + 7 = 28`.
    *   Each subsequent week, the Monday deposit increases by 1, so the weekly sum increases by 7.
    *   The sum for `fullWeeks` can be calculated by iterating from `i = 0` to `fullWeeks - 1` and adding `28 + (i * 7)` for each week.

3.  **Calculate Money from Remaining Days:**
    *   The deposit on the first day of the week after the full weeks is `fullWeeks + 1`.
    *   The remaining days' deposits form an arithmetic progression.

### Code

```cpp
#include <iostream>
#include <vector>

class Solution
{
public:
    int totalMoney(int n)
    {
        int amount = 0;
        int fullWeeks = n / 7;
        int remainingDays = n % 7;
        for (int i = 0; i < fullWeeks; i++)
        {
            amount += 28 + (i * 7);
        }
        for (int i = 0; i < remainingDays; i++)
        {
            amount += (i + 1) + fullWeeks;
        }
        return amount;
    }
};

int main()
{
    Solution sol;
    std::vector<int> tests = {4, 10, 20};
    for (int n : tests)
    {
        std::cout << "Input: n = " << n << "\n";
        std::cout << "Output: " << sol.totalMoney(n) << "\n\n";
    }
    return 0;
}
```