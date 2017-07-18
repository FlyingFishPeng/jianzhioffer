/*
  题目：栈的压入、弹出序列。输入两个整数序列，第一个序列表示栈的压入顺序，
        请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
        例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
        但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

/*
  思路：设置一个辅助栈，用两个指针分别指向输入序列和输出序列，依次将输入序列的元素压入辅助栈，
        直至栈顶元素等于输出序列指针指向的元素，然后将辅助栈栈顶元素弹出，输出序列指针后移。
        检查下一个元素时对比辅助栈栈顶元素是否与当前元素相等，不想等的话继续将输入序列剩余的元素
        压入辅助栈，直至栈顶元素等于输出序列指针指向的元素。如此重复，若将输入序列元素全部压入后
        栈顶元素仍然不等于指针指向的元素，返回false。
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
  		if(pushV.empty() || popV.empty())
            return false;

        if(pushV.size() != popV.size())  //两个序列长度不同，直接返false
            return false;
        int len = popV.size();

        stack<int> tmp;
        int index = 0;    //指向输入序列
        for(int i = 0; i < len; i++)
        {
                while(tmp.empty() || ((tmp.top() != popV[i]) && index < len)) // popV[j]和栈顶元素不相等时向栈压入元素，直到相等，或者PushV的元素压完
                    tmp.push(pushV[index++]);

                if(tmp.top() == popV[i])   //如果辅助栈栈顶元素等于当前指针指向的输出序列元素，辅助栈弹出栈顶元素，指针后移
            	{
                	tmp.pop();
            	}
                else
                    return false;

        }
        return true;
    }
};
