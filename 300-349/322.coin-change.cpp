#include <vector>
#include <unordered_map>

using namespace std;

// 自底向上 通过
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i >= coins[j])
                {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

// 自定向下 会超时
class Solution1
{
public:
    unordered_map<string, int> m;
    int coinChange(vector<int> &coins, int amount)
    {
        if (coins.size() < 1)
        {
            return -1;
        }
        int res = dfs(coins, amount, 0, 0);
        return res == amount + 1 ? -1 : res;
    }
    int dfs(vector<int> &coins, int amount, long curr, int first)
    {
        if (curr == amount)
        {
            return 0;
        }
        else if (curr > amount)
        {
            return amount + 1;
        }
        if (m.count(to_string(curr) + "_" + to_string(first)))
        {
            return m[to_string(curr) + "_" + to_string(first)];
        }
        int res = amount + 1;
        for (int i = first; i < coins.size(); i++)
        {
            long tmp = coins[i] + curr;
            res = min(res, dfs(coins, amount, tmp, i) + 1);
        }
        m[to_string(curr) + "_" + to_string(first)] = res;
        return res;
    }
};