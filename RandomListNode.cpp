/*
  ��Ŀ����������ĸ��ơ�����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ��
        ��һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
        ��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/

/*˼·���ȸ��Ƶ�ǰ������ÿ����㸴�ƺ�Ľ������������棬�γ�AABBCC����ʽ��
       ���½ڵ��randomָ�븳ֵ����ָ��ɽ���randmomָ��ָ��Ľ�����һ����㣻
       ��ֽ�㣺��ͷ��㿪ʼ����ǰָ��ָ�����¸���㣬Ȼ������һ�������µ�ǰ���
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;

        RandomListNode *tmpNode = nullptr, *indexNode = pHead;
        //�˲������ÿ�����ĸ��ƣ���ÿ�����ĸ�����㴮�������
        while(indexNode != nullptr)
        {
        	tmpNode = new RandomListNode(0);
            tmpNode->label = indexNode->label;    //����ֵ

            tmpNode->next = indexNode->next;   //���½�㴮�ڵ�ǰ������
            indexNode->next = tmpNode;

            indexNode = tmpNode->next;   //�����������
        }
        tmpNode = nullptr;
        delete tmpNode;     //�ͷ��ڴ�

        //�˲������½���randomָ��ָ��
        indexNode = pHead;
        while(indexNode != nullptr)
        {
            if(indexNode->random != nullptr)
            	indexNode->next->random = indexNode->random->next;  //�½������ָ��ָ��Ľ����ԭ������ָ��ָ��Ľ�����һ�����
            indexNode = indexNode->next->next;  //���½��
        }

        //�˲������������
    	RandomListNode *newHead = pHead->next;
        indexNode = newHead;
        pHead->next = pHead->next->next;      //�������ͷָ���ָ��Ҫ�ı䣡
    	while(indexNode->next != nullptr)
        {
            tmpNode = indexNode->next;
            indexNode->next = tmpNode->next;
            indexNode = tmpNode;
        }
    	return newHead;
    }
};
