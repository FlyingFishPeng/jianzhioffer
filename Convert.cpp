/*
  ��Ŀ��������������˫����������һ�ö��������������ö���������ת����һ
        �������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/

/*
  ˼·�������������������ɽ��������������˲������������˼�뽫��㴮������
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
    TreeNode* head = nullptr;   //����ָ�������β��

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr)
            return nullptr;
        if(pRootOfTree->left == nullptr && pRootOfTree->right == nullptr)
            return pRootOfTree;

        HelpConvert(pRootOfTree);
        while(head->left != nullptr)
            head = head->left;   //��������ҵ�����ͷ���
        return head;
    }

    void HelpConvert(TreeNode* root)
    {
    	if(root->left)  //����������
        	HelpConvert(root->left);

        if(head == nullptr)  //���������ĵ�һ��Ҷ�ӽ�㸳ֵ��headtmp
            head = root;
        else              //���򽫵�ǰ����������֮��
        {
        	 head->right = root;
             root->left = head;
             head = root;
        }

        if(root->right)   //����������
            HelpConvert(root->right);
        }
};
