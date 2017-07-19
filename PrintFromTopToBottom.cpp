/*
  题目：从上往下打印二叉树。从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/*
  思路：二叉树的广度优先遍历。通过定义一个队列来辅助实现，不能用递归。先将某个结点压入队列，然后
        将此结点存入输出序列，再将此结点的左右结点一次压入队列，最后弹出此结点，如此
        循环。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
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

            if(tmp.front()->left)           //队列第一个元素是左结点放入队列
                tmp.push(tmp.front()->left);
            if(tmp.front()->right)          //右结点放入队列
                tmp.push(tmp.front()->right);

            tmp.pop();     //弹出第一个元素
        }
     	return res;
    }
};
