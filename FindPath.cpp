/*
  ��Ŀ���������к�Ϊĳһֵ��·��������һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
        ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/

/*
  ˼·�����õݹ��˼�롣������������ĵ������⣡
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
    vector<vector<int> > res;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr)
            return res;
        vector<int> tmp;
        int sum = 0;
        HelpToFindPath(root, expectNumber, 0, tmp);
        return res;
    }

    void HelpToFindPath(TreeNode* root,int expectNumber, int sum, vector<int> tmp)
    {
        sum += root->val;
        tmp.push_back(root->val);
        if(sum == expectNumber && root->left == nullptr && root->right == nullptr)  //�����ǰ·���͵���Ŀ��ֵ�ҵ�ǰ���ΪҶ�ӽ�㣬���
            res.push_back(tmp);

        if(root->left)
            HelpToFindPath(root->left, expectNumber, sum, tmp);

        if(root->right)
            HelpToFindPath(root->right, expectNumber, sum, tmp);
    }
};
