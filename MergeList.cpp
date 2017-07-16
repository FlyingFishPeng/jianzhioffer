/*
  题目：合并两个排序的链表。输入两个单调递增的链表，输出两个链表合成后的链表，
        当然我们需要合成后的链表满足单调不减规则
*/

/*
  思路：设计两个指针，分别指向两个待合的链表表头，对比两个指针指向的结点的值，
        将值较小的结点的值赋值给新链表的新节点，然后将指向此结点的指针向后移动，
        直至两个指针均移动到了表尾。
  需要注意的问题；如何处理有一个指针先到达表尾的情况。
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
            else if(p1 != nullptr)   //p1不为空，p2为空
            {
                pnew->val = p1->val;
                p1 = p1->next;
            }
            else         //p1为空，p2不为空
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

