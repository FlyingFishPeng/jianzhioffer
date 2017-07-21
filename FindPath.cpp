/*
  题目：二叉树中和为某一值的路径。输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
        路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

/*
  思路：利用递归的思想。深度优先搜索的典型例题！
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
    vector<vector<int> > res;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr)
            return res;
        vector<int> tmp;
        int sum = 0;
        HelpToFindPath(root, expectNumber, 0, tmp);
        return res;
    }

    void HelpToFindPath(TreeNode* root,int expectNumber, int sum, vector<int> tmp)
    {
        sum += root->val;
        tmp.push_back(root->val);
        if(sum == expectNumber && root->left == nullptr && root->right == nullptr)  //如果当前路径和等于目标值且当前结点为叶子结点，输出
            res.push_back(tmp);

        if(root->left)
            HelpToFindPath(root->left, expectNumber, sum, tmp);

        if(root->right)
            HelpToFindPath(root->right, expectNumber, sum, tmp);
    }
};
