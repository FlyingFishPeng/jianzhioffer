/*
题目：重建二叉树。输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/*
思路：递归
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
        while(tmp != pre[0])     //找到root结点在中序序列中的位置
            tmp = vin[++index];

        vector<int> pre_left, pre_right;
        vector<int> vin_left, vin_right;
        int i = 0, len = vin.size();
<<<<<<< HEAD
        for( ; i < len; i ++)       //��������rootλ��֮ǰ�����к�֮������зֱ�洢��������Ӧ��ǰ������Ҳ������
=======
        for( ; i < len; i ++)       //中序序列root位置之前和之后的序列分别存储，并将对应的前序序列也存起来
>>>>>>> origin/master
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
        if(!vin_left.empty())  //左子树不为空时构造左子树
            root->left = reConstructBinaryTree(pre_left, vin_left);
        if(!vin_right.empty())   //构造右子树
            root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};
