#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() < 1) {
            return "";
        }
        string m = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].size() < m.size()) {
                m = strs[i];
            }
        }
        int ans = m.size();
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            int tc = 0;
            for (int j = 0; j < ans; j++) {
                if (m[j] == tmp[j]) tc++;
                else break;
            }
            ans = min(ans, tc);
        }
        return m.substr(0, ans);
    }
};
