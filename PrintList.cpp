/*
��Ŀ����β��ͷ��ӡ��������һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
*/

/*
˼·1������ջ�������ݴ���ջ�������

*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == nullptr)
            return res;
        stack<ListNode *> tmp;
        ListNode* node = head;
        while(node != nullptr)
        {
            tmp.push(node);
            node = node->next;
        }

        while(!tmp.empty())
        {
        	res.push_back(tmp.top()->val);
            tmp.pop();
        }
        return res;
    }
};


/*
˼·2���ݹ�
*/
class Solution {
public:
    vector<int> res;   //res��Ҫ����Ϊȫ�ֱ���
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head == nullptr)
            return res;
        ListNode* node = head;
        if(node->next != nullptr)
        	printListFromTailToHead(node->next);
        res.push_back(node->val);
        return res;
    }
};
