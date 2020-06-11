#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
		int maxProfit(vector<int> arr) {
			int maxPro = 0;
			for (int i = 1; i < arr.size(); i++) {
				if(arr[i-1] < arr[i]){
					maxPro += arr[i] - arr[i-1];
				}
			}
			return maxPro;
		}
};

// 递归版 会超时
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        return dfs(prices,0);
    }
    int dfs(vector<int> &prices,int first) {
        int m=0;
        if (first == prices.size()) return m;
        for(int i=first;i<prices.size();i++){
            int maxPro = 0;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j] > prices[i]) {
                    int tmp = dfs(prices,j+1) + prices[j] - prices[i];
                    if(tmp > maxPro) {
                        maxPro = tmp;
                    }
                }
            }
            if(maxPro > m) {
                m = maxPro;
            }
        }

        return m;
    }
};

int main() {
	vector<int> res{7,1,5,3,6,4};
	Solution s;
	cout << s.maxProfit(res) << endl; 
	return 0;
}
