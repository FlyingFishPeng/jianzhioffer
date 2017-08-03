/*
   题目：连续子数组的最大和。

/*
   思路：从第一个元素开始累加，判断当前sum是否大于maxsum，如果大于则更新maxsum;如果当前sum为负，则将sum置零，
         从下一个数开始累加，以此类推即可。如果想知道子序列的起点和终点，则在每次将tmpsum置零时更新起点变量为下
         一个start值，每次更新sum时将当时的start更新为终点。

         这种思想和动态规划类似：
          sum(i) = array[i]  ----如果 i=0 或者 sum(i-1)<0
                   sum(i-1)+array[i]  ----如果 sum(i-1)>0
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {

        if(array.empty())
            return 0;

        int sum = 0, maxsum = -1000,len = array.size();
        for(int i = 0; i < len; i++)
        {
        	sum += array[i];
            if(sum > maxsum)         //如果sum值大于上次保存的maxsum，则更新maxsum
                maxsum = sum;

            else if(sum <= 0)    //sum小于0，则sum从下个数开始累加
                sum = 0;
        }
        return maxsum;
    }
};
