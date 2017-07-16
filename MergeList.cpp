/*
  ��Ŀ���ϲ�����������������������������������������������ϳɺ������
        ��Ȼ������Ҫ�ϳɺ���������㵥����������
*/

/*
  ˼·���������ָ�룬�ֱ�ָ���������ϵ������ͷ���Ա�����ָ��ָ��Ľ���ֵ��
        ��ֵ��С�Ľ���ֵ��ֵ����������½ڵ㣬Ȼ��ָ��˽���ָ������ƶ���
        ֱ������ָ����ƶ����˱�β��
  ��Ҫע������⣻��δ�����һ��ָ���ȵ����β�������
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr && pHead2 == nullptr)
            return nullptr;

        ListNode *newhead = nullptr, *p1 = pHead1, *p2 = pHead2, *ptmp = nullptr, *pnew = nullptr;
        while(p1 != nullptr || p2 != nullptr)
        {
            pnew = new ListNode(0);
            if(p1 != nullptr && p2 != nullptr)
            {
                if(p1->val < p2->val)
                {
                    pnew->val = p1->val;
                    p1 = p1->next;
                }

                else if(p1->val == p2->val)
                {
                    pnew->val = p1->val;
                    p1 = p1->next;
                }
                else
                {
                    pnew->val = p2->val;
                    p2 = p2->next;
                }
            }
            else if(p1 != nullptr)   //p1��Ϊ�գ�p2Ϊ��
            {
                pnew->val = p1->val;
                p1 = p1->next;
            }
            else         //p1Ϊ�գ�p2��Ϊ��
            {
                pnew->val = p2->val;
                p2 = p2->next;
            }

            if(newhead == nullptr)
                newhead = pnew;
            else
                ptmp->next = pnew;
            ptmp = pnew;
        }
        pnew = nullptr;
        delete pnew;
        return newhead;
    }
};

