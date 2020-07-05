#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>& board,int i,int j) {
        if (i >= board.size()) return true;
        if (j >= board[0].size()) return dfs(board,i+1,0);
        if (board[i][j] != '.') return dfs(board,i,j+1);
        for (int k=1;k<=9;k++) {
            if (valid(board,i,j,k+'0')) {
                board[i][j] = k+'0';
                if (dfs(board,i,j+1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    bool valid(vector<vector<char>> &board,int i,int j,char val) {
        for (int x=0;x<9;x++) if(board[x][j] == val)  return false;
        for (int y=0;y<9;y++) if(board[i][y] == val) return false;
        int col = i - i % 3;
        int row = j - j % 3;
        for (int x=0;x<3;x++) for (int y=0;y<3;y++) if (board[col+x][row+y] == val) return false;
        return true;
    }
};
