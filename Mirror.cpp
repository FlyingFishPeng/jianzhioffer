/*
  ��Ŀ���������ľ��񡣲��������Ķ�����������任ΪԴ�������ľ���
*/

/*
  ˼·�����ϵ������ν������ҽ�㡣
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
    void Mirror(TreeNode *pRoot) {
		if(pRoot == nullptr)
            return;

        if(pRoot->left == nullptr && pRoot->right == nullptr)
            return;

        TreeNode *ptmp = pRoot->left;   //�������
        pRoot->left = pRoot->right;
        pRoot->right = ptmp;

        if(pRoot->left != nullptr)     //�����������Ľ���
            Mirror(pRoot->left);

        if(pRoot->right != nullptr)    //�����������Ľ���
            Mirror(pRoot->right);
    }
};
