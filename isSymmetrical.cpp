/*
题目：对称的二叉树。请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
/*

/*思路：首先根节点以及其左右子树，左子树的左子树和右子树的右子树相同，左子树的右子树和右子树的左子树相同即可，采用递归*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(pRoot == nullptr)
            return true;
        return judgeTree(pRoot->left, pRoot->right);
    }

    bool judgeTree(TreeNode* lefttmp, TreeNode* righttmp)
    {
        if(lefttmp == nullptr && righttmp == nullptr)
            return true;
        //这里需要再判断一次两个结点是否同时为空！
    	else if(lefttmp != nullptr && righttmp != nullptr && lefttmp->val == righttmp->val)
            return judgeTree(lefttmp->left, righttmp->right) && judgeTree(lefttmp->right, righttmp->left);
        return false;
    }

};









