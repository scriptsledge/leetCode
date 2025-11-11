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
