#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++) {
            int tmp = target - nums[i];
            if(m.count(tmp)) {
                return {m[tmp],i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
