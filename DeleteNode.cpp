/*
��Ŀ����O(1)��ʱ��ɾ�������㡣
*/

/*
  ˼·��Ҫ����O(1)��ʱ��ɾ��ָ����㣬���ͨ����ͷ�����ķ�ʽ�϶����в�ͨ�ġ�
        ���Խ���Ҫɾ���Ľ��i֮���Ǹ����j�����ݸ��Ƶ�Ҫɾ���Ľ���У�Ȼ��
        Ҫɾ���Ľ��iָ��j֮��Ľ�㡣��Ҫע������⣺�����ɾ������ͷ��㣬
        ����ɾ�������Ҫ��ͷ�����ΪNULL�������ɾ������β��㣬����Ҫ��ͷ
        ��������Ȼ��ɾ���ýڵ㡣
*/

void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if(pListHead == NULL || pToBeDeleted == NULL)
        return;

    if(*pListHead == pToBeDeleted)   //Ҫɾ���Ľ����ͷָ��
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    else if(pToBeDeleted->pnext == NULL )   //Ҫɾ���Ľ����βָ��,��Ҫ��ͷ����һ��
    {
        ListNode *p = *pListHead;
        while(p->next != pToBeDeleted)   //�ҵ�βָ��֮ǰ�Ľ��
            p = p->pnext;
        p->pnext = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
    else
    {
        ListNode *p = pToBeDeleted->pnext;  //��ɾ��������һ�����
        pToBeDeleted->val = p->val;
        pToBeDeleted->pnext = p->pnext;
        delete p;
        p = NULL;
    }
}
