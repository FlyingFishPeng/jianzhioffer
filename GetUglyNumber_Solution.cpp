/*
  题目：丑数。把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
        习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

/*
  思路：利用动态规划的思想，新的丑数必然是前面的丑数乘以2,3,5后得到的最小值。设置因子2,3,5对应的三个指针
         分别为index2,index3,index5,初始值均为0。每次循环时，求三个指针对应的值乘以相应的因子后得到的最小值，
         将其作为新的丑数存储，同时找出三个指针对应的值中使得其乘以对应的因子后等于新丑数的指针，并将其加1，下次
         循环中，三个因子将与上一轮的指针对应的值相乘求出新丑数。
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if(index == 0)
            return 0;

        int *uglynum = new int[index];
        uglynum[0] = 1;

        int i = 1, index2 = 0, index3 = 0, index5 = 0;
        while(i < index)
        {
        	uglynum[i] = min(2 * uglynum[index2], min(3 * uglynum[index3], 5 * uglynum[index5]));

            while(2 * uglynum[index2] == uglynum[i])   //找到三个索引中使得该位置的值乘以对应的值等于最小值的索引,并将该索引向后移动一位
                ++ index2;

            while(3 * uglynum[index3] == uglynum[i])
                ++ index3;

            while(5 * uglynum[index5] == uglynum[i])
                ++ index5;
            ++i;
        }
        return uglynum[index - 1];
    }
};
