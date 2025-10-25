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