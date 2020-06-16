#include <unordered_map>
#include <list>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, int> m;
    unordered_map<string, int> distance;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};

        if (dict.find(beginWord) == dict.end()) {
            dict.insert(beginWord);
            wordList.push_back(beginWord);
        }
        for (int i = 0; i < wordList.size(); i++) {
            m[wordList[i]] = i;
        }
        vector<vector<int>> graph(wordList.size());
        queue<string> q;
        q.push(beginWord);
        distance.insert(pair<string, int>(beginWord, 0));
        bool found = false;
        while (!q.empty()) {
            int tmpSize = q.size();
            found = false;
            for (int i = 0; i < tmpSize; i++) {
                string word = q.front();
                q.pop();
                int wi = m[word];
                int d = distance[word];
                for (int j = 0; j < word.size(); j++) {
                    char tmp = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (tmp == word[j]) continue;
                        if (word == endWord) found = true;
                        if (dict.find(word) != dict.end()) {
                            graph[wi].push_back(m[word]);
                            if (!distance.count(word)) {
                                distance[word] = d + 1;
                                q.push(word);
                            }
                        }
                    }
                    word[j] = tmp;
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            vector<int> vis(wordList.size(), 0);
            dfs(beginWord, endWord, graph, {}, wordList);
        }
        return res;
    }

    void dfs(string begin, string end, vector<vector<int>> &graph,
             vector<string> solution, vector<string> &wordList) {
        solution.push_back(begin);
        if (begin == end) {
            res.push_back(solution);
        } else {
            int ind = m[begin];
            for (int i = 0; i < graph[ind].size(); i++) {
                int tmp = distance.find(wordList[graph[ind][i]])->second;
                if (tmp == distance[begin] + 1) {
                    dfs(wordList[graph[ind][i]], end, graph, solution, wordList);
                }
            }
        }
        solution.erase(solution.end() - 1);
    }

};


int main() {
    Solution s;
    string begin = "hit";
    string end = "cog";
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> res = s.findLadders(begin, end, wordList);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
