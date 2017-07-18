/*
  ��Ŀ������min������ջ������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
*/

/*
  ˼·������һ������ջ��ÿ����ջ��ѹ����ʱ�����������븨��ջջ�����ݶԱȣ���������С�ڸ���ջ
        ջ�����ݣ��ͽ�������ѹ�븨��ջ�����򽫸���ջջ��Ԫ��ѹ�롣
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
