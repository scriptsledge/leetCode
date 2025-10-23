Check If Digits Are Equal in String After Operations I

Short intuition
----------------
We repeatedly replace the string by the list of pairwise sums (mod 10) of adjacent digits until only two digits remain, then check if those two digits are equal. Each round reduces the length by exactly 1, so the process always finishes.

What I reasoned
----------------
- Each iteration computes new digits: new[i] = (old[i] + old[i+1]) % 10.
- After k iterations the string length becomes original_length - k. Stop when length == 2.
- Implementation detail: treat characters as digits by subtracting '0', then convert back with + '0'.

Algorithm (straightforward simulation)
-------------------------------------
1. While s.length() > 2:
   - build a new string t of length s.length() - 1
   - for i in [0 .. s.length()-2]: t[i] = char('0' + ((s[i]-'0') + (s[i+1]-'0')) % 10)
   - set s = move(t)
2. Return s[0] == s[1]

Complexity
----------
- Time: O(n^2) worst-case because we rebuild the string each round and there are O(n) rounds; with n <= 100 this is fine.
- Space: O(n) extra for the temporary string per round (can be reused to avoid repeated allocations).

Example
-------
Input: "3902"
Rounds:
- "3902" -> "292" -> "11"
Return: true

What I did wrong (notes from my `solution.cpp`)
-----------------------------------------------
Here are the mistakes I made when I first wrote the solution and how to fix them:

- Casting bytes incorrectly
  - Wrong: char ch = char((int)oldS[i] + (int)oldS[i+1]) % 10;
  - Why: that sums ASCII codes (not digits) and the % 10 happens after the cast, producing non-digit characters.
  - Fix: Convert to numeric digits first: int a = oldS[i] - '0'; int b = oldS[i+1] - '0'; then char ch = char('0' + (a + b) % 10);

- Using the wrong loop bound / stale length
  - Wrong: using a separate variable `n` initialized once before the loop and iterating i < n-1 each round causes out-of-range access after `oldS` shrinks.
  - Fix: use the current string length in the loop (e.g., for (size_t i = 0; i + 1 < oldS.size(); ++i)).

- Frequent reallocations (minor)
  - Wrong: creating new temporary strings repeatedly with concatenation (newS += ch) is fine here but can be optimized.
  - Fix: reserve or construct with size: string t; t.reserve(oldS.size()-1); or string t(oldS.size()-1, '?') and fill by index.

Small corrected snippet (for reference)
------------------------------------

```cpp
bool hasSameDigits(std::string s) {
    while (s.size() > 2) {
        std::string t;
        t.reserve(s.size()-1);
        for (size_t i = 0; i + 1 < s.size(); ++i) {
            int a = s[i] - '0';
            int b = s[i+1] - '0';
            t.push_back(char('0' + (a + b) % 10));
        }
        s = std::move(t);
    }
    return s.size() == 2 && s[0] == s[1];
}
```

Summary
-------
The approach is a simple simulation. The main pitfalls are mixing ASCII codes with numeric values and using stale lengths/indices after mutating the string. With the fixes above the implementation is clear and robust.