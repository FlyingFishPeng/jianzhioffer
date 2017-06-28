/*
题目：从尾到头打印链表。输入一个链表，从尾到头打印链表每个节点的值。
*/

/*
思路1：借助栈，将数据存在栈中再输出

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
思路2：递归
*/
class Solution {
public:
    vector<int> res;   //res需要设置为全局变量
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
