#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool hasSameDigits(string s)
    {
        string oldS = s;
        int n = oldS.size();
        int loopOutValue = n;
        while (loopOutValue != 2)
        {
            string newS = "";
            for (int i = 0; i < n - 1; i++)
            {
                char ch = char('0' + (int(oldS[i]) + int(oldS[i + 1])) % 10);
                newS += ch;
            }
            oldS = newS;
            n = oldS.size();
            loopOutValue = newS.size();
        }
        if (oldS[0] == oldS[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution sol;
    string s = "34789";
    bool result = sol.hasSameDigits(s);
    cout << (result ? "true" : "false") << '\n';
    return 0;
}