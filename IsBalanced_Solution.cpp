/*
    ��Ŀ��ƽ�������������һ�ö��������жϸö������Ƿ���ƽ���������
*/

/*
    ˼·���ݹ���ÿ�����������������ȡ����ڵ�������ÿ�������ʱ�����ظ����㣬��Ľ���
*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot == nullptr)
            return true;
        int deepleft = deepTree(pRoot->left);
        int deepright = deepTree(pRoot->right);
        if(abs(deepleft - deepright) > 1)
            return false;
        else
            return (IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right));
    }

    int deepTree(TreeNode* pRoot)
    {
    	if(pRoot == nullptr)
            return 0;
        int dleft = deepTree(pRoot->left) + 1;
        int dright = deepTree(pRoot->right) + 1;
        return dleft > dright ? dleft : dright;
    }
};
