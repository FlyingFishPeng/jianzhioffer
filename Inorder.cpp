/*
   ��Ŀ�������������ĵ�k����㡣����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣
         ���磬 5 / \ 3 7 /\ /\ 2 4 6 8 �У��������ֵ��С˳�����������ֵΪ4��
*/

/*
   ˼·����������������Եõ���С������������У�ֱ�������k������
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

class Solution {
public:
    vector<TreeNode*> tmp;
    int flag = 0;
    TreeNode* node= nullptr;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0)
            return nullptr;
        Inorder(pRoot, k);
        return node;
    }

    void Inorder(TreeNode* root, int k)  //�������
    {
    	if(root->left)
        	Inorder(root->left,k);
        flag++;
        if(flag == k)   //��k�����ʱֹͣ
        {
            node = root;
            return;
        }
        if(root->right)
        Inorder(root->right, k);
    }

};

/*
class Solution {
public:
    vector<TreeNode*> tmp;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0)
            return nullptr;
        Inorder(pRoot);
        if(k > tmp.size())
            return nullptr;
        return tmp[k-1];
    }

    void Inorder(TreeNode* root)  //�������
    {
    	if(root == nullptr)
            return;
        Inorder(root->left);
        tmp.push_back(root);
        Inorder(root->right);
    }

};
*/
