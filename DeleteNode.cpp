/*
题目：在O(1)的时间删除链表结点。
*/

/*
  思路：要求在O(1)的时间删除指定结点，如果通过从头遍历的方式肯定是行不通的。
        可以将需要删除的结点i之后那个结点j的内容复制到要删除的结点中，然后将
        要删除的结点i指向j之后的结点。需要注意的问题：如果待删结点等于头结点，
        则在删除完结点后要将头结点置为NULL；如果待删结点等于尾结点，则需要从头
        遍历链表然后删除该节点。
*/

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if(pListHead == NULL || pToBeDeleted == NULL)
        return;

    if(*pListHead == pToBeDeleted)   //要删除的结点是头指针
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    else if(pToBeDeleted->pnext == NULL )   //要删除的结点是尾指针,需要从头遍历一遍
    {
        ListNode *p = *pListHead;
        while(p->next != pToBeDeleted)   //找到尾指针之前的结点
            p = p->pnext;
        p->pnext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
    else
    {
        ListNode *p = pToBeDeleted->pnext;  //被删除结点的下一个结点
        pToBeDeleted->val = p->val;
        pToBeDeleted->pnext = p->pnext;
        delete p;
        p = NULL;
    }
}
