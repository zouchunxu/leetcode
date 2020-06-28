#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        return dfs(s);
    }
    int dfs(string s)
    {
        int res = 0;
        if (s.size() >= 2) {
            string ts = s.substr(s.size() - 2, 2);
            int tmp = 0;
            for (int i=1;i>=0;i++) {
                // tmp += (ts[i] - '0') * pow(10, 1 - i);
            }
            cout << ts << endl;
        }

        return 0;

    }
};

int main()
{
    Solution s;
    // string s = "12";
    // cout << s.size() << endl;
    // cout << s.substr(0,-2) << endl;
    cout << s.numDecodings("226") << endl;
    return 0;
}