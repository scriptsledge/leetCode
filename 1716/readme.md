# 1716. Calculate Money in Leetcode Bank

Short intuition
----------------
Hercy deposits money every day. The deposit pattern in a single week (Monday..Sunday) is an arithmetic sequence starting from the week's Monday value. Each new Monday the amount starts one dollar higher than the previous Monday.

What I reasoned
----------------
- For a full week starting with value x on Monday, the week sum = x + (x+1) + ... + (x+6) = 7*x + 21.
- If there are fullWeeks = n / 7, the Mondays values are 1, 2, ..., fullWeeks so the contribution is sum_{i=0..fullWeeks-1} (7*(i+1) + 21) which the solution computes compactly.

Algorithm
---------
1. Compute number of full weeks and remaining days.
2. Sum each full week using the arithmetic progression formula (or the compact 28 + i*7 used in the solution).
3. Add the remaining days considering the increase from completed weeks.

Complexity
----------
- Time: O(weeks) = O(n/7) -> effectively O(n) worst-case with small constant.
- Space: O(1)

Examples
--------
Example 1:

Input: n = 4

Output: 10

Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.

Example 2:

Input: n = 10

Output: 37

Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37.

Example 3:

Input: n = 20

Output: 96

Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.

Constraints
-----------

- 1 <= n <= 1000

Solution
--------
See `solution.cpp` for an implementation and a `main()` that runs the examples.