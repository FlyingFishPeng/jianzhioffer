/*
  题目：链表中倒数第k个结点。输入一个链表，输出该链表中倒数第k个结点。
*/

/*
  思路：一种方法是遍历一遍链表，统计出结点总数n，再从头遍历到第n-k-1个结点。
        如果要求只遍历1遍，可以设置两个均指向表头的指针，指针p2先不动，等
        指针p1移动k-1步后p2再一起移动，等p1移动到表尾时，p2所指的结点就是
        倒数第二个节点。
        需要注意的问题：输入的指针可能为空指针；k=0；k大于链表总结点数
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
       if(pListHead == nullptr || k == 0)
           return nullptr;
        ListNode *p1 = pListHead, *p2 = pListHead;
        int flag = 0;
        while(p1->next != nullptr)    //p1到达尾端后p2指向的位置即倒数第k个结点
        {
            p1 = p1->next;
            flag++;

            if(flag > k - 1)   //p2从第k步开始移动
                p2 = p2->next;
        }

        if(p1->next == nullptr && flag < k - 1)    //k大于链表总结点数时，p1走过的步数小于k-1
        	return nullptr;
        return p2;
    }
};
