/*
  题目：树的子结构。输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

/*
  思路：利用递归。
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
     	bool res = false;
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return res;

        if(pRoot1->val == pRoot2->val)   //当前结点相同，则检查左结点和右节点是否相同
            res = JudgeHasSubtree(pRoot1, pRoot2);
        if(res == false)  //继续在A树当前结点的左子树中寻找与B树当前结点相等的结点
            res = HasSubtree(pRoot1->left, pRoot2);
        if(res == false)   //在A的右子树中寻找与B树当前结点相等的结点
            res = HasSubtree(pRoot1->right, pRoot2);
        return res;
    }

    bool JudgeHasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == nullptr)  //pRoot2为Null，说明前面的结点都相同且已经对照完毕
            return true;

        if(pRoot1 == nullptr)  //程序运行到此行即说明B树还没遍历完，但是A先遍历完了，错误
            return false;

        if(pRoot1->val != pRoot2->val)
            return false;
        //否则，说明两棵树当前结点相同，继续检查两棵树的左子树和右子树
        return (JudgeHasSubtree(pRoot1->left, pRoot2->left)) && JudgeHasSubtree(pRoot1->right, pRoot2->right);
    }
};





