/*
  题目：数组中出现次数超过一半的数字。数组中有一个数字出现的次数超过数组长度的一半，
        请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数
        组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

/*
  思路1：设置两个变量，一个保存数字，一个保存出现的次数，依次往后遍历。如果当前值和
         保存的数字相等，则计数器加1，否则减1。若计数器为0，则将当前数字存入，且计数器
         置1，最后让计数器置1的数就是所求值。需要再遍历一次数组进行验证。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.empty())
            return 0;

        int res = numbers[0], sum = 1, len = numbers.size();
        for(int i = 1; i < len; i++)
        {
            if(numbers[i] == res)    //当前值和res中的值相等，则将sum加1
                 ++sum;
            else
            	--sum;
	    if(sum == 0)     //如果sum为0,res存入新数字之后将sum置1
            {
            	res = numbers[i];
                sum = 1;
            }
        }
        //最后把res设置为1的置就是所求的值，此时还需要进一步检验
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
  思路2：按照快排的思想，出现次数最多的那个数在排序的过程中必然位于中间位置，
         可以根据每次排序的结果来判断下次排序的区间，如果返回的索引位置大于
         middle，说明中位数在前半段，在前半段知行partition，否则在后半段执行。
         递归思想。
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
        	 if(index > middle)   //中间的点在左边，在左半边寻找
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
            while((end > start) && numbers[start] >= base)   //头指针左移，直到找到比base小的数
            	-- end;
        	swap(numbers[start], numbers[end]);

        	while((start < end) && numbers[end] <= base)
            	++ start;
            swap(numbers[start], numbers[end]);
        }
        return start;
    }
};
