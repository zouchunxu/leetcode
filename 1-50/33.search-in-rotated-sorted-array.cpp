#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 1) return -1;
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[mid] < target || nums[0] > target) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};