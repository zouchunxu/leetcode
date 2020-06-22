#include <vector>

using namespace std;

// 记忆划递归
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(grid, grid.size() - 1, grid[0].size() - 1, memo);
    }
    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &memo)
    {
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        int res = 0;
        if (i - 1 >= 0 && j - 1 >= 0)
        {
            res = min(dfs(grid, i - 1, j, memo), dfs(grid, i, j - 1, memo)) + grid[i][j];
        }
        else if (i - 1 >= 0)
        {
            res = dfs(grid, i - 1, j, memo) + grid[i][j];
        }
        else if (j - 1 >= 0)
        {
            res = dfs(grid, i, j - 1, memo) + grid[i][j];
        }
        else
        {
            res = grid[0][0];
        }
        memo[i][j] = res;
        return res;
    }
};

// 动态规划
class Solution1
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                if (j == grid[0].size() - 1 && i == grid.size() - 1)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    if (i + 1 > grid.size() - 1)
                    {
                        dp[i][j] = dp[i][j + 1] + grid[i][j];
                    }
                    else if (j + 1 > grid[0].size() - 1)
                    {
                        dp[i][j] = dp[i + 1][j] + grid[i][j];
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
                    }
                }
            }
        }
        return dp[0][0];
    }
};
