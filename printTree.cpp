/*
  题目：二叉树按层次打印（广度优先）。每层分行打印。
*/

/*
  思路：借助队列，先将父节点压入队列，输出父节点，再依次压入其左右节点。。。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
        // write code here
        vector<vector<int>>result;
    if (root == NULL)return result;
    queue<TreeNode*>Q;
    Q.push(root);
    while (!Q.empty())
    {
        int size = Q.size();
        vector<int>row;
        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = Q.front();
            Q.pop();
            row.push_back(cur->val);
            if (cur->left)Q.push(cur->left);
            if (cur->right)Q.push(cur->right);
        }
        result.push_back(row);
    }
    return result;
    }
};
