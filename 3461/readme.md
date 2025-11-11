# 3461. Check If Digits Are Equal in String After Operations

## Problem Description

You are given a string `s` of digits. You have to perform the following operation on `s` until the length of `s` becomes 2:

*   Replace `s` with a new string where each character at index `i` is `(s[i] - '0' + s[i+1] - '0') % 10`.

Return `true` if the final two digits of `s` are equal, and `false` otherwise.

### Example 1:

**Input:** `s = "3902"`
**Output:** `true`
**Explanation:**
1.  `s` becomes `"(3+9)%10 (9+0)%10 (0+2)%10"` which is `"292"`.
2.  `s` becomes `"(2+9)%10 (9+2)%10"` which is `"11"`.
The final two digits are equal.

### Example 2:

**Input:** `s = "123"`
**Output:** `false`
**Explanation:**
1. `s` becomes `"(1+2)%10 (2+3)%10"` which is `"35"`.
The final two digits are not equal.

### Constraints:

*   `2 <= s.length <= 100`
*   `s` consists of digits from '0' to '9'.

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The solution simulates the process described in the problem. It repeatedly generates a new string by taking the pairwise sum of adjacent digits modulo 10 until the string length is 2.

1.  Start with the initial string `s`.
2.  While the length of the current string is greater than 2:
    *   Create a new empty string `next_s`.
    *   Iterate through the current string from the first to the second-to-last character.
    *   For each pair of adjacent characters, convert them to integers, sum them, take the result modulo 10, and append it to `next_s`.
    *   Replace the current string with `next_s`.
3.  After the loop, the string length will be 2. Check if the two characters are equal and return the result.

### Code

```cpp
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        string current_s = s;
        while (current_s.size() > 2)
        {
            string next_s = "";
            for (size_t i = 0; i + 1 < current_s.size(); ++i)
            {
                int digit1 = current_s[i] - '0';
                int digit2 = current_s[i+1] - '0';
                next_s += to_string((digit1 + digit2) % 10);
            }
            current_s = next_s;
        }
        return current_s.size() == 2 && current_s[0] == current_s[1];
    }
};

int main()
{
    Solution sol;
    vector<string> test_cases = {"34789", "3902", "11", "123"};
    for (string s : test_cases)
    {
        bool result = sol.hasSameDigits(s);
        cout << "For s = \"" << s << "\", the result is: " << (result ? "true" : "false") << '\n';
    }
    return 0;
}
```