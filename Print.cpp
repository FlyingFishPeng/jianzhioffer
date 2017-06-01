/*
    题目：请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
    第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推
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
            if(flag)   //从右往左
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
                swap(tmp, cur);  //用swap更高效
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
