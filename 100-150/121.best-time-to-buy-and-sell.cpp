#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            cout << i << " - " << dp[i][1] << endl;
        }
        return dp[prices.size() - 1][0];
    }
};

class Solution1 
{
public:
    unordered_map<int,int> m;
    unordered_map<int,int> mi;
    int maxProfit(vector<int>& prices) {
        mi[0] = -prices[0];
        // mi[1] = -prices[0];
        // cout  << "1 - " <<mi[1] << endl;
        for (int i=1;i<prices.size();i++) {
            mi[i] = max(mi[i-1],-prices[i]);
            cout << i << " - " <<mi[i] << endl;
        }
        return dfs(prices,prices.size()-1);
    }
    int dfs(vector<int> & prices,int i) {
        if(i-1 < 0) return 0;
        if(m.count(i)) return m[i];
        int tmp = dfs(prices,i-1);
        m[i] =  max(tmp,prices[i] + mi[i]);
        return m[i];
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2};
    Solution1 s1;
    cout << s.maxProfit(v) << endl;
    cout << s1.maxProfit(v) << endl;
}