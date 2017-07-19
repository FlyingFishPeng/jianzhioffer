/*
  ��Ŀ�������������ĺ���������С�����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
        ����������Yes,�������No���������������������������ֶ�������ͬ��
*/

/*
  ˼·�������������е��ص��ǣ����������һ��λ�õ�ֵΪ����㣬����ǰ����һ���ֵ�ֵȫ��С�ڸ���㣬
        �ⲿ���Ǹ�������������һ���ֵ�ֵȫ�����ڸ����,��һ�����Ǹ�������������˼·�����ҵ�������
        ��ֵ�ķֽ�㣬�ֱ��жϷֽ��ǰ�󲿷ֵ�ֵ�Ƿ�ȫ�����ڻ�С�ڸ���㣬�������㣬���Ǻ������С�
        �����㣬��ݹ��ж����������������Ƿ���������
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.empty())
       		return false;
        return JudgeTree(sequence, 0, sequence.size());
    }

    bool JudgeTree(const vector<int> &arr, int start, int end)  //��������ʹ��const�������Ч�ʺͷ�ֹ�޸�
    {
        if(start == end)
       		return true;

        int i = start;
        int rootval = arr[end - 1];   //����㼴arr[end - 1]

        while(i < end && arr[i] < rootval)     //��ͷ��ʼ�����ҵ���һ�����ڸ��ڵ��λ��
        	i++;

        int end_temp = i;

        for(; i < end; i++)   //�ӵ�һ�����ڸ�����λ�����������鿴�Ƿ�ÿ��Ԫ�ض��Ǵ��ڸ����ģ�������С�ڸ�����ֵ��������в��Ǻ����������
        {
            if(arr[i] < rootval)
                return false;
        }

        return (JudgeTree(arr, start, end_temp) && JudgeTree(arr, end_temp, end - 1));  //�ݹ��ж���������������
    }
};
