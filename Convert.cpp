/*
  题目：二叉搜索树与双向链表。输入一棵二叉搜索树，将该二叉搜索树转换成一
        个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/*
  思路：树的中序遍历可以完成结点的排序输出，因此采用中序遍历的思想将结点串起来。
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
    TreeNode* head = nullptr;   //最终指向链表的尾部

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        if(pRootOfTree->left == nullptr && pRootOfTree->right == nullptr)
            return pRootOfTree;

        HelpConvert(pRootOfTree);
        while(head->left != nullptr)
            head = head->left;   //向左遍历找到链表头结点
        return head;
    }

    void HelpConvert(TreeNode* root)
    {
    	if(root->left)  //遍历左子树
        	HelpConvert(root->left);

        if(head == nullptr)  //将遍历到的第一个叶子结点赋值给headtmp
            head = root;
        else              //否则将当前结点加在链表之后
        {
        	 head->right = root;
             root->left = head;
             head = root;
        }

        if(root->right)   //遍历右子树
            HelpConvert(root->right);
        }
};
