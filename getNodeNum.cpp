/*
  题目：二叉树第K层结点数。
*/

/*
   思路：求第K层结点的个数也可以用递归来实现：

        ①若二叉树为空或者K小于0，返回0

        ②若K等于0，第0层就是树根，根只有一个，返回1

        ③若K大于0，返回左子树中第K-1层结点个数 加上 右子树中第K-1层结点的个数

        因为，第K层结点，相对于根的左子树 和 右子树 而言，就是第K-1层结点

递归的基准条件只有两个：

    1) k==0 当递归到K==0时，说明：第K层是有结点的

    ) root==null  当递归到root==null时，说明：第K层没有结点
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

// 二叉树中第K层结点的个数(根位于第0层)

int getNodeNum(TreeNode * T, int k){
    if (!T || k < 1){
        return 0;
    }
    if (k == 1){
        return 1;
    }
    return getNodeNum(T->left, k-1) + getNodeNum(T->right, k-1);
}
