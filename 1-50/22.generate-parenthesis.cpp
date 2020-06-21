#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> res;
    vector<string> generateParenthesis(int n)
    {
        dfs(n, 0, 0, "");
        return res;
    }

    void dfs(int n, int left, int right, string out)
    {
        if (n == left && n == right)
        {
            res.push_back(out);
            return;
        }

        if (left < n)
        {
            dfs(n, left + 1, right, out + "(");
        }
        if (right < left)
        {
            dfs(n, left, right + 1, out + ")");
        }
    }
};
