/*
  题目：青蛙跳台阶：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
  思路：斐波那契数列：Fib(n)=1,n=1;
                    Fib(n)=2,n=2;
                    Fib(n)=Fib(n-1)+Fib(n-2),n>2.
*/

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0)
            return 0;
        if(number == 1)
            return 1;
        else if(number == 2)
            return 2;
        int tmp1 = 1, tmp2 = 2, tmp;
        for(int i = 3; i <= number; i ++)
        {
            tmp = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = tmp;
        }
        return tmp2;
    }
};


