/*
   题目：两个链表的第一个公共结点。
*/

/*
   思路：先遍历一遍两个链表，求出两个链表的长度差step，将较长的那个链表先向
        前走step步，然后开始同时遍历两个链表，每走一步比较一次，直到找到相同
        的结点。

        拓展：二叉树的最低公共父节点。
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

        int len1 = 0, len2 = 0;   //两个链表长度
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

        for(int i = 0; i < step; i++)  //较长的链表先走step步
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















