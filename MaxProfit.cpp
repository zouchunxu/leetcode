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

int main() {
	vector<int> res{7,1,5,3,6,4};
	Solution s;
	cout << s.maxProfit(res) << endl; 
	return 0;
}
