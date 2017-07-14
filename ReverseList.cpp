/*
  ��Ŀ����ת��������һ������ͷ��㣬��ת�����������ת�������ͷ��㡣
*/

/*
  ˼·1������һ��ջ�������ӽ��ѹ�룬Ȼ�������ε������һ��������ʱ�临�ӶȺ�
         �ռ临�Ӷȶ���O(n)��
  ˼·2����������ָ�룬�ֱ�ָ��ǰһ����㣬��ǰ��㣬�ͺ�һ����㡣��������˳��
          ���з�ת��
          ���º�һ����㣻
          ��ǰ���ָ��ǰһ����㣻
          �õ�ǰ������ǰһ����㣻
          �ú�һ�������µ�ǰ��㡣
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
        while(p != nullptr)  //�Ȱ�����ѹ��ջ�������ε������������
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
       pnew = nullptr;    //��ֹ��ΪҰָ��
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
