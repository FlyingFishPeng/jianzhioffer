/*
��Ŀ���ؽ�������������ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡���������ǰ���������
{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
*/

/*
˼·���ݹ�
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	if(pre.size()== 0 || vin.size() == 0)
        	return nullptr;

    	TreeNode* root = new TreeNode(pre[0]);
        int index = 0;
    	int tmp = vin[index];
        while(tmp != pre[0])     //�ҵ�root��������������е�λ��
            tmp = vin[++index];

        vector<int> pre_left, pre_right;
        vector<int> vin_left, vin_right;
        int i = 0, len = vin.size();
        for( ; i < len; i ++)       //��������rootλ��֮ǰ�����к�֮������зֱ�洢��������Ӧ��ǰ������Ҳ������
        {
            if(i < index)
            {
                pre_left.push_back(pre[i+1]);
                vin_left.push_back(vin[i]);
            }
            else if(i > index)
            {
                pre_right.push_back(pre[i]);
                vin_right.push_back(vin[i]);
            }
        }
        if(!vin_left.empty())  //��������Ϊ��ʱ����������
            root->left = reConstructBinaryTree(pre_left, vin_left);
        if(!vin_right.empty())   //����������
            root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};
