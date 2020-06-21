#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tr;
            int tmpSize = q.size();
            for (int i = 0; i < tmpSize; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                tr.push_back(t->val);
                if (t->left)
                {
                    q.push(t->left);
                }
                if (t->right)
                {
                    q.push(t->right);
                }
            }
            res.push_back(tr);
        }
        return res;
    }
};
