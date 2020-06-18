#include <vector>

using namespace std;

class Solution {
public:
    struct status {
        int leftMax;
        int rightMax;
        int sum;
        int m;
    };
    int maxSubArray(vector<int>& nums) {
       return dfs(0,nums.size()-1,nums).m;
    }
    status dfs(int i,int j,vector<int> &nums) {
        if (i==j) return status{nums[i],nums[i],nums[i],nums[i]};
        int m = (i+j) / 2;
        status left = dfs(i,m,nums);
        status right = dfs(m+1,j,nums);
        return builder(left,right);
    }
    status builder(status left,status right) {
        int sum = left.sum + right.sum;
        int leftMax = max(left.leftMax,left.sum+right.leftMax);
        int rightMax = max(right.rightMax,right.sum+left.rightMax);
        int m = max(max(left.m,right.m),left.rightMax + right.leftMax);
        return status{leftMax,rightMax,sum,m};
    }
};
