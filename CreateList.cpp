/*
  ����β�巨����������
*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *pnext;
};

ListNode *CreateList(int n)  //����n���ڵ������
{
    ListNode *head = NULL, *ptmp = NULL, *pnew = NULL;
    int i = 0;
    while(i < n)
    {
        pnew = new ListNode;
        cin >> pnew->val;
        pnew->pnext = NULL;
        if(head == NULL)
            head = pnew;
        else
            ptmp->pnext = pnew;
        ptmp = pnew;
        i++;
    }
    pnew = NULL;
    delete pnew;
    return head;
}

void PrintList(ListNode *head)
{
    ListNode *p = head;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->pnext;
    }
    cout << endl;
}

int main()
{
    ListNode *head;
    int n;
    cout << "����������Ŀ��" << endl;
    cin >> n;
    head = CreateList(n);
    PrintList(head);
    return 0;
}


















