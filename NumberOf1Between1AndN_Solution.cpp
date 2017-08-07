/*
  题目：整数中1出现的次数（从1到n整数中1出现的次数）。
*/

/*思路：参考CSDN博客的分析过程，weight为当前要统计的位，round是当前位高位的所有值，former是当前位低位所有值
	若weight为0，则1出现次数为round*base
	若weight为1，则1出现次数为round*base+former+1
	若weight大于1，则1出现次数为rount*base+base
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if(n <= 0)
            return 0;
  		int weight = 0, round = 0, former = 0, base = 1, tmp = n, sum = 0;
        while(tmp)
        {
            round = tmp / 10;    //当前位的高位
            weight = tmp % 10;   //当前位
            former = n % base;    //当前位的低位
            if(weight == 0)
                sum += round * base;
            else if(weight == 1)
                sum += round * base + former + 1;
            else
                sum += round * base + base;
            base *= 10;
            tmp /= 10;
        }
        return sum;
    }
};






