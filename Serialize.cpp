/*
   题目：序列化二叉树。请实现两个函数，分别用来序列化和反序列化二叉树
*/

/*
   思路：序列化采用前序遍历方式，如果左结点或者右节点为空，用'*'表示。
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
class Solution
{
public:
    vector<int> tmp;
    void front(TreeNode* root)
    {
        if(root == nullptr)
        {
            tmp.push_back('*');
            return;
        }
        tmp.push_back(root->val);
        front(root->left);
        front(root->right);
    }

    char* Serialize(TreeNode *root)
    {
        front(root);
        int len = tmp.size();
        int* res = new int[len];
        for(int i = 0; i < len; i++)
            res[i] = tmp[i];
        return (char*)res;
    }

    TreeNode* Deserhelp(int *&str)
    {
        if(*str == '*')     //该节点为*时说明为空，直接返回
        {
            str++;
            return nullptr;
        }
        TreeNode* head = new TreeNode(*str);
        str++;
        head->left = Deserhelp(str);
        head->right = Deserhelp(str);
        return head;
    }

    TreeNode* Deserialize(char *str)
    {
        int *p = (int *)str;
        return Deserhelp(p);
    }
};




