/*
  题目：二叉搜索树的后序遍历序列。输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
        如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

/*
  思路：后续遍历序列的特点是：序列中最后一个位置的值为根结点，序列前面有一部分的值全部小于根结点，
        这部分是根的左子树；有一部分的值全部大于根结点,这一部分是根的右子树。则思路就是找到这两部
        分值的分界点，分别判断分界点前后部分的值是否全部大于或小于根结点，若不满足，则不是后序序列。
        若满足，则递归判断左子树和右子树是否满足条件
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.empty())
       		return false;
        return JudgeTree(sequence, 0, sequence.size());
    }

    bool JudgeTree(const vector<int> &arr, int start, int end)  //参数传递使用const引用提高效率和防止修改
    {
        if(start == end)
       		return true;

        int i = start;
        int rootval = arr[end - 1];   //根结点即arr[end - 1]

        while(i < end && arr[i] < rootval)     //从头开始遍历找到第一个大于根节点的位置
        	i++;

        int end_temp = i;

        for(; i < end; i++)   //从第一个大于根结点的位置向后遍历，查看是否每个元素都是大于根结点的，若出现小于根结点的值，则该序列不是后序遍历序列
        {
            if(arr[i] < rootval)
                return false;
        }

        return (JudgeTree(arr, start, end_temp) && JudgeTree(arr, end_temp, end - 1));  //递归判断左子树和右子树
    }
};
