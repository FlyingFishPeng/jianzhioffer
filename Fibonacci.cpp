/*
   斐波那契数列：输出第n项的值，n<39.
*/

/*
   思路：递归或者循环，递归时间复杂度高，循环的时间复杂度O(n)
*/

/*
//递归
class Solution {
public:
    int Fibonacci(int n) {
		if(n > 39 || n < 0)
            return 0;
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else
            return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};
*/


//循环
class Solution {
public:
    int Fibonacci(int n) {
		if(n > 39 || n < 0)
            return 0;
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        int tmp1 = 0, tmp2 = 1, tmp;
        for(int i = 2; i <= n; i ++)
        {
            tmp = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = tmp;
        }
        return tmp2;
    }
};
