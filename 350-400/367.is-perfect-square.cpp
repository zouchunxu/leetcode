class Solution {
public:
    bool isPerfectSquare(int num) {
        long low = 0;
        long high = num;
        while (low <= high) {
            long mid = (high + low) / 2;
            long tmp = mid * mid;
            if (tmp == num) {
                return true;
            } else if(tmp < num) {
                low = mid + 1;
            } else {
                high = mid-1;
            }
        }
        return false;
    }
};
