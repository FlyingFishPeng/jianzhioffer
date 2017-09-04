/*
    题目：求二叉树中的节点个数。
*/

int countNodes(TreeNode* root)
{
	if (root == NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}
