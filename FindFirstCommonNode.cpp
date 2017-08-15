/*
   ��Ŀ����������ĵ�һ��������㡣
*/

/*
   ˼·���ȱ���һ���������������������ĳ��Ȳ�step�����ϳ����Ǹ���������
        ǰ��step����Ȼ��ʼͬʱ������������ÿ��һ���Ƚ�һ�Σ�ֱ���ҵ���ͬ
        �Ľ�㡣

        ��չ������������͹������ڵ㡣
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *cNode(0);
        if(pHead1 == nullptr || pHead2 == nullptr)
            return cNode;

        int len1 = 0, len2 = 0;   //����������
        ListNode *p1 = pHead1, *p2 = pHead2;
        while(p1->next)
        {
            ++ len1;
            p1 = p1->next;
        }

        while(p2->next)
        {
        	++ len2;
            p2 = p2->next;
        }
        ListNode* pLong(0);
        ListNode* pShort(0);
        int step = 0;

        if(len1 >= len2)
        {
            pLong = pHead1;
            pShort = pHead2;
            step = len1 - len2;
        }
        else
        {
            pLong = pHead2;
            pShort = pHead1;
            step = len2 - len1;
        }

        for(int i = 0; i < step; i++)  //�ϳ�����������step��
            pLong = pLong->next;

        while(pLong != nullptr && pShort != nullptr)
        {
        	if(pLong == pShort)
                break;
            else
            {
                pLong = pLong->next;
                pShort = pShort->next;
            }
        }
        cNode = pLong;
        return cNode;
    }
};















