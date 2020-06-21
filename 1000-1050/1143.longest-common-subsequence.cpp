#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2)
    {
        memo = vector(text1.size(), vector<int>(text2.size(), -1));
        dfs(text1, text2, text1.size() - 1, text2.size() - 1);
        return memo[text1.size() - 1][text2.size() - 1];
    }
    int dfs(string &text1, string &text2, int i, int j)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        if (text2[j] == text1[i])
        {
            memo[i][j] = dfs(text1, text2, i - 1, j - 1) + 1;
        }
        else
        {
            memo[i][j] = max(dfs(text1, text2, i, j - 1), dfs(text1, text2, i - 1, j));
        }

        return memo[i][j];
    }
};
