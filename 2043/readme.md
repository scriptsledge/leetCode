# 2043. Simple Bank System

## Problem Description

You are tasked with designing a simple bank system. You have to support three types of transactions: `transfer`, `deposit`, and `withdraw`. The bank has `n` accounts, numbered from `1` to `n`. The initial balance of each account is stored in an array `balance`, where `balance[i]` is the initial balance of account `i + 1`.

Implement the `Bank` class:

*   `Bank(long[] balance)`: Initializes the object with the initial balances.
*   `boolean transfer(int account1, int account2, long money)`: Transfers `money` from `account1` to `account2`. Returns `true` if the transaction is successful, `false` otherwise.
*   `boolean deposit(int account, long money)`: Deposits `money` into `account`. Returns `true` if the transaction is successful, `false` otherwise.
*   `boolean withdraw(int account, long money)`: Withdraws `money` from `account`. Returns `true` if the transaction is successful, `false` otherwise.

A transaction is successful if:

*   The account numbers are valid (between `1` and `n`).
*   The amount of money to withdraw or transfer is not more than the account's balance.

### Example 1:

**Input:**
```
["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
```

**Output:**
```
[null, true, true, true, false, false]
```

**Explanation:**
```
Bank bank = new Bank([10, 100, 20, 50, 30]);
bank.withdraw(3, 10);    // returns true, account 3's balance is now 10
bank.transfer(5, 1, 20); // returns true, account 5's balance is now 10, account 1's balance is now 30
bank.deposit(5, 20);     // returns true, account 5's balance is now 30
bank.transfer(3, 4, 15); // returns false, account 3 has only 10, so the transfer fails
bank.withdraw(10, 50);   // returns false, account 10 does not exist
```

### Constraints:

*   `n == balance.length`
*   `1 <= n, account, account1, account2 <= 10^5`
*   `0 <= balance[i], money <= 10^12`
*   At most `10^4` calls will be made to each function `transfer`, `deposit`, `withdraw`.

## Solution

The solution is implemented in the [`solution.cpp`](./solution.cpp) file.

### Approach

The `Bank` class is designed with a `vector<long long>` to store the balances of the accounts. The core of the implementation is the validation logic within each transaction method.

1.  **Initialization:** The constructor initializes the `balances` vector.
2.  **Validation:** Each method (`transfer`, `deposit`, `withdraw`) first validates the account numbers to ensure they are within the valid range `[1, n]`.
3.  **Sufficient Funds Check:** For `transfer` and `withdraw`, the methods check if the account has sufficient funds.
4.  **Transaction Execution:** If the validation and funds check pass, the balances are updated.

### Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Bank
{
private:
    vector<long long> balances;

public:
    Bank(vector<long long> &balance) { balances = balance; }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 < 1 || account1 > (int)balances.size() || account2 < 1 ||
            account2 > (int)balances.size() || balances[account1 - 1] < money)
        {
            return false;
        }
        else
        {
            balances[account1 - 1] -= money;
            balances[account2 - 1] += money;
            return true;
        }
    }

    bool deposit(int account, long long money)
    {
        if (account < 1 || account > (int)balances.size())
        {
            return false;
        }
        balances[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account < 1 || account > (int)balances.size() ||
            balances[account - 1] < money)
        {
            return false;
        }
        else
        {
            balances[account - 1] -= money;
            return true;
        }
    }
};
```
