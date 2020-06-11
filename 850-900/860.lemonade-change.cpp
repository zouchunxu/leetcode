class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m5 = 0;
        int m10 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if(bills[i] == 5) m5++;
            else if (bills[i] == 10) { m10++; m5--; }
            else if(bills[i] == 20) { 
                if (m10 > 0) { m10--; m5--; }
                else m5 -= 3; 
            }
            if (m5 < 0) return false;
        }
        return true;
    }
};
