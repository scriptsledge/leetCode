
# 2043. Simple Bank System

Short intuition
----------------
A bank system simulation that manages multiple accounts (1-indexed) where the core challenge is to maintain data consistency and handle various banking operations while ensuring proper validation of account indices and sufficient funds.

What I reasoned
----------------
- Design a robust bank system using a vector to store account balances
- Handle edge cases through careful validation:
  - Ensure account indices are within valid range [1, n]
  - Verify sufficient funds exist for withdrawals/transfers
  - Maintain atomicity in transfer operations
- Implement operations with O(1) time complexity using direct array access

Algorithm
---------
1. Initialize bank with an array storing account balances (0-indexed internally)
2. For each operation:
   - Validate account numbers are in range [1, n]
   - For withdrawals/transfers, verify sufficient balance
   - Update balances atomically
   - Return success/failure status

API Methods
----------
- `Bank(long[] balance)`: Initialize bank with starting balances
- `transfer(int account1, int account2, long money)`: Transfer money between accounts
- `deposit(int account, long money)`: Add money to an account
- `withdraw(int account, long money)`: Remove money from an account

Complexity
----------
- Time: O(1) for all operations
- Space: O(n) where n is the number of accounts

Examples
--------
Example 1:
```
Input: 
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]

Output: 
[null, true, true, true, false, false]

Explanation:
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // true, account 3: $20 → $10
bank.transfer(5, 1, 20); // true, account 5: $30 → $10, account 1: $10 → $30
bank.deposit(5, 20);     // true, account 5: $10 → $30
bank.transfer(3, 4, 15); // false, insufficient funds
bank.withdraw(10, 50);   // false, invalid account
```

Constraints
-----------
- n == balance.length
- 1 <= n, account, account1, account2 <= 10^5
- 0 <= balance[i], money <= 10^12
- At most 10^4 calls will be made to each function transfer, deposit, withdraw

Solution
--------
See `solution.cpp` for a straightforward implementation and an example `main()` that runs the sample test case.
