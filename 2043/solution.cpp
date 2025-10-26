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

int main()
{
    // Test from README: ["Bank","withdraw","transfer","deposit","transfer","withdraw"]
    // Operations: [[[10,100,20,50,30]], [3,10], [5,1,20], [5,20], [3,4,15], [10,50]]
    vector<long long> init = {10, 100, 20, 50, 30};
    Bank bank(init);

    cout << "Input:\n[\"Bank\", \"withdraw\", \"transfer\", \"deposit\", \"transfer\", \"withdraw\"]\n";
    cout << "[[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]\n\n";

    cout << "Output:\n[null";
    bool res;
    res = bank.withdraw(3, 10);
    cout << ", " << (res ? "true" : "false");
    res = bank.transfer(5, 1, 20);
    cout << ", " << (res ? "true" : "false");
    res = bank.deposit(5, 20);
    cout << ", " << (res ? "true" : "false");
    res = bank.transfer(3, 4, 15);
    cout << ", " << (res ? "true" : "false");
    res = bank.withdraw(10, 50);
    cout << ", " << (res ? "true" : "false");
    cout << "]\n";

    return 0;
}

/*
 * Example usage (expected Output):
 * [null, true, true, true, false, false]
 */