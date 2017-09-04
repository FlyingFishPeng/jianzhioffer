/*
  题目：二叉树按层次打印（广度优先）。每层分行打印。
*/

/*
  思路：思路：二叉树的广度优先遍历。通过定义一个队列来辅助实现，不能用递归。先将某个结点压入队列，然后
        将此结点存入输出序列，再将此结点的左右结点一次压入队列，最后弹出此结点，如此循环。
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

// 每层分行打印
class TreePrinter
{
public:
    vector<vector<int> > printTree(TreeNode* root)
    {
        vector<vector<int>>result;
        if (root == NULL)return result;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int size = Q.size();
            vector<int>row;
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = Q.front();
                Q.pop();
                row.push_back(cur->val);   //打印
                if (cur->left)
                    Q.push(cur->left);
                if (cur->right)
                    Q.push(cur->right);
            }
            result.push_back(row);  //将该层压入结果矩阵
        }
        return result;
    }
};


// 不分行打印
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        queue<TreeNode *> tmp;
        tmp.push(root);
        while(!tmp.empty())
        {
            res.push_back(tmp.front()->val);    //队列第一个元素存入数组
            tmp.pop();     //弹出第一个元素
          
            if(tmp.front()->left)           //队列第一个元素是左结点放入队列
                tmp.push(tmp.front()->left);
            if(tmp.front()->right)          //右结点放入队列
                tmp.push(tmp.front()->right);
        }
     	return res;
    }
};
