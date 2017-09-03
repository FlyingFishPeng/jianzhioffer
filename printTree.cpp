/*
  ��Ŀ������������δ�ӡ��������ȣ���ÿ����д�ӡ��
*/

/*
  ˼·���������У��Ƚ����ڵ�ѹ����У�������ڵ㣬������ѹ�������ҽڵ㡣����
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

class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
        // write code here
        vector<vector<int>>result;
    if (root == NULL)return result;
    queue<TreeNode*>Q;
    Q.push(root);
    while (!Q.empty())
    {
        int size = Q.size();
        vector<int>row;
        for (int i = 0; i < size; i++)
        {
            TreeNode* cur = Q.front();
            Q.pop();
            row.push_back(cur->val);
            if (cur->left)Q.push(cur->left);
            if (cur->right)Q.push(cur->right);
        }
        result.push_back(row);
    }
    return result;
    }
};
