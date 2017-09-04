/*
   题目：重建二叉树（中序+后序）。
*/

typedef vector<int>::iterator Iter;
TreeNode* buildTree2(Iter pbegin, Iter pend, Iter ibegin, Iter iend)
{
	if (pbegin == pend || ibegin == iend)
		return NULL;
	TreeNode* root = new TreeNode(*(pend - 1));

	auto iroot = find(ibegin, iend, *(pend - 1));
	int leftlength = iroot - ibegin;
	root->left = buildTree2(pbegin, pbegin + leftlength, ibegin, iroot);
	root->right = buildTree2(pbegin + leftlength, pend - 1, iroot + 1, iend);

	return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	if (postorder.size() == 0 || inorder.size() == 0 || postorder.size() != inorder.size())
		return NULL;
	return buildTree2(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
}
