/*
  题目：包含min函数的栈。定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

/*
  思路：设置一个辅助栈，每次往栈中压数据时，将此数据与辅助栈栈顶数据对比，若此数据小于辅助栈
        栈顶数据，就将此数据压入辅助栈，否则将辅助栈栈顶元素压入。
*/

class Solution {
public:
    stack<int> Stack, MinTmp;
    void push(int value) {
        Stack.push(value);
        if(MinTmp.empty() ||value < MinTmp.top())
            MinTmp.push(value);
        else
            MinTmp.push(MinTmp.top());
    }

    void pop() {
        if(!Stack.empty())
        {
            Stack.pop();
       	    MinTmp.pop();
        }
        return;

    }

    int top() {
        return this->top();
    }

    int min() {
        return MinTmp.top();
    }
};
