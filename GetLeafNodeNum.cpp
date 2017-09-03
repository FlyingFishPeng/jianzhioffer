/*
    题目：二叉树叶子节点个数。
*/

/*
   思路：（1）如果二叉树为空，返回0
         （2）如果二叉树不为空且左右子树为空，返回1
         （3）如果二叉树不为空，且左右子树不同时为空，返回左子树中叶子节点个数加上右子树中叶子节点个数
*/

int GetLeafNodeNum(BTree* root)
{
	if(root == NULL)
		return 0;
	if(root->m_pLeft == NULL && root->m_pRight == NULL)
		return 1;

	int LeafNumOfLeft = GetLeafNodeNum(root->m_pLeft);
	int LeafNumOfRight = GetLeafNodeNum(root->m_pRight);

	int ret = LeafNumOfLeft + LeafNumOfRight;

	return ret;

}
