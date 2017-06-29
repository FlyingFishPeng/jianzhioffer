/*
��Ŀ��������ջʵ�ֶ��С�������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������
     ˵ �����е�Ԫ��Ϊint���͡�
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
            while(len > 1)    //��ջ1�е�һ��Ԫ�������Ԫ��ȫ��ѹ��ջ2
            {
                node = stack1.top();
                stack2.push(node);
                stack1.pop();
                --len;
            }
            node = stack1.top();    //��ջ1ʣ���Ǹ�Ԫ�ص���
            stack1.pop();
            return node;
        }
        else            //����ջ2ջ��Ԫ��
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
