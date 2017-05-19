/*
��Ŀ���ԳƵĶ���������ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
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
/*˼·�����ȸ��ڵ��Լ���������������������������������������������ͬ����������������������������������ͬ���ɣ����õݹ�*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if(pRoot == nullptr)
            return true;
        return judgeTree(pRoot->left, pRoot->right);
    }

    bool judgeTree(TreeNode* lefttmp, TreeNode* righttmp)
    {
        if(lefttmp == nullptr && righttmp == nullptr)
            return true;
        //������Ҫ���ж�һ����������Ƿ�ͬʱΪ�գ�
    	else if(lefttmp != nullptr && righttmp != nullptr && lefttmp->val == righttmp->val)
            return judgeTree(lefttmp->left, righttmp->right) && judgeTree(lefttmp->right, righttmp->left);
        return false;
    }

};









