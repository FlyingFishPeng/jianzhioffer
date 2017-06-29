/*
题目：用两个栈实现队列。用两个栈来实现一个队列，完成队列的Push和Pop操作。
     说 队列中的元素为int类型。
*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            int node;
        	int len = stack1.size();
            while(len > 1)    //把栈1中第一个元素以外的元素全部压入栈2
            {
                node = stack1.top();
                stack2.push(node);
                stack1.pop();
                --len;
            }
            node = stack1.top();    //将栈1剩余那个元素弹出
            stack1.pop();
            return node;
        }
        else            //弹出栈2栈顶元素
        {
            int node = stack2.top();
            stack2.pop();
            return node;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
