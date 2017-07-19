/*
  ��Ŀ���������´�ӡ���������������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
*/

/*
  ˼·���������Ĺ�����ȱ�����ͨ������һ������������ʵ�֣������õݹ顣�Ƚ�ĳ�����ѹ����У�Ȼ��
        ���˽�����������У��ٽ��˽������ҽ��һ��ѹ����У���󵯳��˽�㣬���
        ѭ����
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

    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        queue<TreeNode *> tmp;
        tmp.push(root);
        while(!tmp.empty())
        {
            res.push_back(tmp.front()->val);    //���е�һ��Ԫ�ش�������

            if(tmp.front()->left)           //���е�һ��Ԫ��������������
                tmp.push(tmp.front()->left);
            if(tmp.front()->right)          //�ҽ��������
                tmp.push(tmp.front()->right);

            tmp.pop();     //������һ��Ԫ��
        }
     	return res;
    }
};
