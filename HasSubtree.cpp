/*
  ��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
*/

/*
  ˼·�����õݹ顣
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

        if(pRoot1->val == pRoot2->val)   //��ǰ�����ͬ������������ҽڵ��Ƿ���ͬ
            res = JudgeHasSubtree(pRoot1, pRoot2);
        if(res == false)  //������A����ǰ������������Ѱ����B����ǰ�����ȵĽ��
            res = HasSubtree(pRoot1->left, pRoot2);
        if(res == false)   //��A����������Ѱ����B����ǰ�����ȵĽ��
            res = HasSubtree(pRoot1->right, pRoot2);
        return res;
    }

    bool JudgeHasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == nullptr)  //pRoot2ΪNull��˵��ǰ��Ľ�㶼��ͬ���Ѿ��������
            return true;

        if(pRoot1 == nullptr)  //�������е����м�˵��B����û�����꣬����A�ȱ������ˣ�����
            return false;

        if(pRoot1->val != pRoot2->val)
            return false;
        //����˵����������ǰ�����ͬ�������������������������������
        return (JudgeHasSubtree(pRoot1->left, pRoot2->left)) && JudgeHasSubtree(pRoot1->right, pRoot2->right);
    }
};





