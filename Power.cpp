/*
    题目：数值的整数次方：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

/*
    思路：本题的考点主要有两个：1、对输入数据的有效性进行判读，即指数为负数时底数不能为0；
                                2、判断两个double或者float型数据是否相等时不能直接用等号，因为计算机内表示小数时
                                都有误差，只能通过他们之差的绝对值是否在很小的一个范围内来判断：(num1- num2) > -0.00000001 && (num1- num2) < 0.00000001
*/
class Solution {
public:
    double Power(double base, int exponent) {
		if(exponent == 0)
            return 1.0;

        double res = base;
        if(exponent > 0)
        {
        	 for(int i = 1; i < exponent; i++)
                res *= base;
        }

        if(exponent < 0)
        {
            if((base - 0.0) > -0.00000001 && (base - 0.0) < 0.00000001)      //double型的数据不能直接和整型数据直接做比较
            	return 1.0;
            else
            {
            	for(int i = 1; i < -exponent; i++)
                	res *= base;
                res = 1.0 / res;
            }
        }
        return res;
    }
};
