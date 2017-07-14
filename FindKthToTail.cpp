/*
  ��Ŀ�������е�����k����㡣����һ����������������е�����k����㡣
*/

/*
  ˼·��һ�ַ����Ǳ���һ������ͳ�Ƴ��������n���ٴ�ͷ��������n-k-1����㡣
        ���Ҫ��ֻ����1�飬��������������ָ���ͷ��ָ�룬ָ��p2�Ȳ�������
        ָ��p1�ƶ�k-1����p2��һ���ƶ�����p1�ƶ�����βʱ��p2��ָ�Ľ�����
        �����ڶ����ڵ㡣
        ��Ҫע������⣺�����ָ�����Ϊ��ָ�룻k=0��k���������ܽ����
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
        while(p1->next != nullptr)    //p1����β�˺�p2ָ���λ�ü�������k�����
        {
            p1 = p1->next;
            flag++;

            if(flag > k - 1)   //p2�ӵ�k����ʼ�ƶ�
                p2 = p2->next;
        }

        if(p1->next == nullptr && flag < k - 1)    //k���������ܽ����ʱ��p1�߹��Ĳ���С��k-1
        	return nullptr;
        return p2;
    }
};
