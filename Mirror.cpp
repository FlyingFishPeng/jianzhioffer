/*
  题目：二叉树的镜像。操作给定的二叉树，将其变换为源二叉树的镜像。
*/

/*
  思路：从上到下依次交换左右结点。
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
//递归
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot == nullptr)
            return;

        if(pRoot->left == nullptr && pRoot->right == nullptr)
            return;

        TreeNode *ptmp = pRoot->left;   //交换结点
        pRoot->left = pRoot->right;
        pRoot->right = ptmp;

        if(pRoot->left != nullptr)     //处理左子树的交换
            Mirror(pRoot->left);

        if(pRoot->right != nullptr)    //处理右子树的交换
            Mirror(pRoot->right);
    }
};

//非递归
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL)
            return;
        stack<TreeNode*> stackNode;
        stackNode.push(pRoot);
        while(stackNode.size()){
            TreeNode* tree=stackNode.top();
            stackNode.pop();
            if(tree->left!=NULL || tree->right!=NULL){
                TreeNode *ptemp=tree->left;
                tree->left=tree->right;
                tree->right=ptemp;
            }
            if(tree->left)
                stackNode.push(tree->left);
            if(tree->right)
                stackNode.push(tree->right);
        }
    }
};
