/*
   ��Ŀ�����л�����������ʵ�������������ֱ��������л��ͷ����л�������
*/

/*
   ˼·�����л�����ǰ�������ʽ�������������ҽڵ�Ϊ�գ���'*'��ʾ��
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
        if(*str == '*')     //�ýڵ�Ϊ*ʱ˵��Ϊ�գ�ֱ�ӷ���
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




