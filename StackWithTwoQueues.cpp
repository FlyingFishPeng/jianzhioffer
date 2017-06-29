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
    if(!queue1.empty())    //插入到非空的那个队列
        queue1.push(node);
    else
        queue2.push(node);
}

int Stack::pop()
{
    int node;
    if(!queue1.empty())   //把非空的队列元素中最后一个以外的元素转移到另一个空队列
    {
        int len = queue1.size();
        while(len > 1)
        {
            node = queue1.front();
            queue2.push(node);   //队列1的元素依次压入队2
            queue1.pop();   //弹出队1的元素
            --len;
        }
        node = queue1.front();
        queue1.pop();   //弹出队1的元素
        return node;
    }
    else
    {
        int len = queue2.size();
        while(len > 1)
        {
            node = queue2.front();
            queue1.push(node);   //队列1的元素依次压入队2
            queue2.pop();   //弹出队1的元素
            --len;
        }
        node = queue2.front();
        queue1.pop();   //弹出队1的元素
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

