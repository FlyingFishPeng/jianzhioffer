/*
    题目：二叉树的最小深度。
*/

/*
    思路：递归。
*/

int minDepth(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL&&root->right == NULL)
		return 1;
	int left = minDepth(root->left);
	int right = minDepth(root->right);
	if (root->left == NULL)
		return right + 1;
	if (root->right == NULL)
		return left + 1;
	return left > right ? (right + 1) : (left + 1);
}
