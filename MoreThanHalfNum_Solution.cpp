/*
  ��Ŀ�������г��ִ�������һ������֡���������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬
        ���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2����
        ���г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/

/*
  ˼·1����������������һ���������֣�һ��������ֵĴ�����������������������ǰֵ��
         �����������ȣ����������1�������1����������Ϊ0���򽫵�ǰ���ִ��룬�Ҽ�����
         ��1������ü�������1������������ֵ����Ҫ�ٱ���һ�����������֤��
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.empty())
            return 0;

        int res = numbers[0], sum = 1, len = numbers.size();
        for(int i = 1; i < len; i++)
        {
            if(numbers[i] == res)    //��ǰֵ��res�е�ֵ��ȣ���sum��1
                 ++sum;
            else
            	--sum;
			if(sum == 0)     //���sumΪ0,res����������֮��sum��1
            {
            	res = numbers[i];
                sum = 1;
            }
        }
        //����res����Ϊ1���þ��������ֵ����ʱ����Ҫ��һ������
        int times = 0;
        for(int i = 0; i < len; i++)
        {
            if(numbers[i] == res)
                ++times;
        }
        if(2 * times > len)
            return res;
        return 0;
    }
};

/*
  ˼·2�����տ��ŵ�˼�룬���ִ��������Ǹ���������Ĺ����б�Ȼλ���м�λ�ã�
         ���Ը���ÿ������Ľ�����ж��´���������䣬������ص�����λ�ô���
         middle��˵����λ����ǰ��Σ���ǰ���֪��partition�������ں���ִ�С�
         �ݹ�˼�롣
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.empty())
            return 0;

        int len = numbers.size();
        int middle = len >> 1;
        int start = 0, end = len - 1, n = 0;
        int index = partition(numbers, start, end);
        while(index != middle)
        {
        	 if(index > middle)   //�м�ĵ�����ߣ�������Ѱ��
             {
                 end = index - 1;
                 index = partition(numbers, start, end);
             }
             else
             {
             	start = index + 1;
                index = partition(numbers, start, end);
             }
        }

        int res = numbers[middle];
        int times = 0;
        for(int i = 0; i < len; i++)
        {
            if(numbers[i] == res)
                ++times;
        }
        if(2 * times > len)
            return res;
        return 0;
    }

    int partition(vector<int> &numbers, int start, int end)
    {
    	int base = numbers[start];
        while(start < end)
        {
            while((end > start) && numbers[start] >= base)   //ͷָ�����ƣ�ֱ���ҵ���baseС����
            	-- end;
        	swap(numbers[start], numbers[end]);

        	while((start < end) && numbers[end] <= base)
            	++ start;
            swap(numbers[start], numbers[end]);
        }
        return start;
    }
};
