#include <iostream>
#include <queue>
using namespace std;

class Stack
{
public:
    void push(int node);
    int pop();
private:
    queue<int> queue1;
    queue<int> queue2;
};

void Stack::push(int node)
{
    if(!queue1.empty())    //���뵽�ǿյ��Ǹ�����
        queue1.push(node);
    else
        queue2.push(node);
}

int Stack::pop()
{
    int node;
    if(!queue1.empty())   //�ѷǿյĶ���Ԫ�������һ�������Ԫ��ת�Ƶ���һ���ն���
    {
        int len = queue1.size();
        while(len > 1)
        {
            node = queue1.front();
            queue2.push(node);   //����1��Ԫ������ѹ���2
            queue1.pop();   //������1��Ԫ��
            --len;
        }
        node = queue1.front();
        queue1.pop();   //������1��Ԫ��
        return node;
    }
    else
    {
        int len = queue2.size();
        while(len > 1)
        {
            node = queue2.front();
            queue1.push(node);   //����1��Ԫ������ѹ���2
            queue2.pop();   //������1��Ԫ��
            --len;
        }
        node = queue2.front();
        queue1.pop();   //������1��Ԫ��
        return node;
    }
}


int main()
{
    Stack stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    cout << stack1.pop() << endl;
    stack1.push(4);
    cout << stack1.pop() << endl;
    return 0;
}

