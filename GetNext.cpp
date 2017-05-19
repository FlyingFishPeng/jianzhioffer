/*
��Ŀ������������һ����㡣����һ�������������е�һ����㣬���ҳ��������˳�����
һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
/*˼·����1�� ���ýڵ����������������һ���ڵ�Ϊ�����������ӽڵ�
	   ��2�� ���ýڵ㲻��������������ʱ�����������
         2.1 �ýڵ�Ϊ���ڵ�����ӽڵ㣬����һ���ڵ�Ϊ�丸�ڵ�
         2.2 �ýڵ�Ϊ���ڵ�����ӽڵ㣬�����Ÿ��ڵ����ϱ�����֪���ҵ�һ���ڵ�ĸ��ڵ�����ӽڵ�Ϊ�ýڵ㣬��ýڵ�ĸ��ڵ���һ���ڵ�
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
            return nullptr;
        TreeLinkNode *tmp = nullptr, *nextnode = nullptr, *fathernode = pNode->next;
        if(pNode->right != nullptr)  //����������������һ�����������������������ĵ�һ�����
        {
            tmp = pNode->right;
            while(tmp->left)
            {
            	tmp = tmp->left;
            }
            nextnode = tmp;
        }
        else if(fathernode != nullptr && fathernode->left == pNode) //���丸�������ӽڵ㣬����һ����㼴�丸���
        {
            nextnode = fathernode;
        }
        else if(fathernode != nullptr && fathernode->right == pNode)  //���丸�������ӽڵ㣬����һ����㼴�佫�丸�����Ϊ����Ľ��
        {
            tmp = fathernode->next;
            while(pNode->next != nullptr && pNode->next->left != pNode)
            {
                pNode = pNode->next;
            }
            nextnode = pNode->next;
        }
        return nextnode;
    }
};











