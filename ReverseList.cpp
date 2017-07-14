/*
  题目：反转链表。输入一个链表头结点，反转该链表并输出反转后链表的头结点。
*/

/*
  思路1：利用一个栈，把链接结点压入，然后再依次弹出组成一个新链表。时间复杂度和
         空间复杂度都是O(n)。
  思路2：利用三个指针，分别指向前一个结点，当前结点，和后一个结点。利用如下顺序
          进行反转：
          更新后一个结点；
          当前结点指向前一个结点；
          用当前结点更新前一个结点；
          用后一个结点更新当前结点。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == nullptr)
            return nullptr;
        stack<int> tmp;
        ListNode *p = pHead;
        while(p != nullptr)  //先把链表压入栈，再依次弹出组成新链表
        {
            tmp.push(p->val);
            p = p->next;
        }
       ListNode *newhead = nullptr, *ptmp = nullptr, *pnew = nullptr;
       while(!tmp.empty())
       {
           pnew = new ListNode(0);
           pnew->val = tmp.top();
           pnew->next = nullptr;
           if(newhead == nullptr)
           {
               newhead = pnew;
           }
           else
           {
               ptmp->next = pnew;
           }
           ptmp = pnew;
		   tmp.pop();
       }
       pnew = nullptr;    //防止成为野指针
       delete pnew;
       return newhead;
    }
};
*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead == nullptr)
            return nullptr;
        ListNode *pCur = pHead, *pPre = nullptr, *pNext = nullptr, *newhead;
        while(pCur != nullptr)
        {
            pNext = pCur->next;
            if(pNext == nullptr)
                newhead = pCur;

            pCur->next = pPre;
            pPre = pCur;
            pCur = pNext;
        }

        return newhead;



    }
};
