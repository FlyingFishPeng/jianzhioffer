/*
    题目：平衡二叉树。输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/*
    思路：递归求每个结点左右子树的深度。存在的问题是每次求深度时都会重复计算，需改进。
*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot == nullptr)
            return true;
        int deepleft = deepTree(pRoot->left);
        int deepright = deepTree(pRoot->right);
        if(abs(deepleft - deepright) > 1)
            return false;
        else
            return (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right));
    }

    int deepTree(TreeNode* pRoot)
    {
    	if(pRoot == nullptr)
            return 0;
        int dleft = deepTree(pRoot->left) + 1;
        int dright = deepTree(pRoot->right) + 1;
        return dleft > dright ? dleft : dright;
    }
};
