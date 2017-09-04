/*
   题目：二叉搜索树的第k个结点。给定一颗二叉搜索树，请找出其中的第k大的结点。
         例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
*/

/*
   思路：利用中序遍历可以得到从小到大的排序序列，直接输出第k个即可
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

    void Inorder(TreeNode* root, int k)  //中序遍历
    {
    	if(root->left)
        	Inorder(root->left,k);
        flag++;
        if(flag == k)   //第k个结点时停止
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

    void Inorder(TreeNode* root)  //中序遍历
    {
    	if(root == nullptr)
            return;
        Inorder(root->left);
        tmp.push_back(root);
        Inorder(root->right);
    }

};
*/
