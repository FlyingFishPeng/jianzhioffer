/*
    ��Ŀ����ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
    �ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ�����
*/

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot == nullptr)
            return res;
        vector<TreeNode*> tmp;
        tmp.push_back(pRoot);
        int flag = 1;
        while(tmp.size() != 0)
        {
            if(flag)   //��������
            {
                vector<int> tmpval;
                vector<TreeNode*> cur;
                for(int i = tmp.size() - 1; i >= 0; i --)
                {
                    tmpval.push_back(tmp[i]->val);
                    if(tmp[i]->left)
                    {
                        cur.push_back(tmp[i]->left);
                    }

                    if(tmp[i]->right)
                    {
                        cur.push_back(tmp[i]->right);
                    }

                }
                res.push_back(tmpval);
                swap(tmp, cur);  //��swap����Ч
                flag = 0;
            }
            else
            {
                vector<int> tmpval;
                vector<TreeNode*> cur;
                for(int i = tmp.size() - 1; i >= 0; i --)
                {
                    tmpval.push_back(tmp[i]->val);
                    if(tmp[i]->right)
                    {
                        cur.push_back(tmp[i]->right);
                    }
                    if(tmp[i]->left)
                    {
                        cur.push_back(tmp[i]->left);
                    }

                }
                res.push_back(tmpval);
                swap(tmp, cur);
                flag = 1;
            }
        }
        return res;
    }

};
