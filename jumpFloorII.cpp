/*
  题目：变态跳台阶：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
        求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
  思路：此问题仍是一个斐波那契数列：
      Fib(n) = Fib(n-1)+Fib(n-2)+Fib(n-3)+..........+Fib(n-n)=Fib(0)+Fib(1)+Fib(2)+.......+Fib(n-1)
      又因为Fib(n-1)=Fib(0)+Fib(1)+Fib(2)+.......+Fib(n-2)
      两式相减得：Fib(n)-Fib(n-1)=Fib(n-1)  =====》Fib(n)=1,n=1
                                                   Fib(n) = 2*Fib(n-1),n >= 2
*/

class Solution {
public:
    int jumpFloorII(int number) {
		 if(number <= 0)
            return 0;
        if(number == 1)
            return 1;
        int tmp = 1;
        for(int i = 2; i <= number; i ++)
        {
            tmp *=2;
        }
        return tmp;
    }
};

