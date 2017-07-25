/*
  题目：复杂链表的复制。输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向
        下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
        （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*思路：先复制当前链表，将每个结点复制后的结点连接在其后面，形成AABBCC的形式；
       给新节点的random指针赋值，其指向旧结点的randmom指针指向的结点的下一个结点；
       拆分结点：从头结点开始，当前指针指向下下个结点，然后用下一个结点更新当前结点
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
        //此步骤完成每个结点的复制，将每个结点的副本结点串在其后面
        while(indexNode != nullptr)
        {
        	tmpNode = new RandomListNode(0);
            tmpNode->label = indexNode->label;    //复制值

            tmpNode->next = indexNode->next;   //将新结点串在当前结点后面
            indexNode->next = tmpNode;

            indexNode = tmpNode->next;   //更新索引结点
        }
        tmpNode = nullptr;
        delete tmpNode;     //释放内存

        //此步设置新结点的random指针指向
        indexNode = pHead;
        while(indexNode != nullptr)
        {
            if(indexNode->random != nullptr)
            	indexNode->next->random = indexNode->random->next;  //新结点的随机指针指向的结点是原结点随机指针指向的结点的下一个结点
            indexNode = indexNode->next->next;  //更新结点
        }

        //此步骤分离新链表
    	RandomListNode *newHead = pHead->next;
        indexNode = newHead;
        pHead->next = pHead->next->next;      //旧链表的头指针的指向要改变！
    	while(indexNode->next != nullptr)
        {
            tmpNode = indexNode->next;
            indexNode->next = tmpNode->next;
            indexNode = tmpNode;
        }
    	return newHead;
    }
};
