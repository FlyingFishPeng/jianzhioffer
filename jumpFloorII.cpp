/*
  ��Ŀ����̬��̨�ף�һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
        �����������һ��n����̨���ܹ��ж�����������
*/

/*
  ˼·������������һ��쳲��������У�
      Fib(n) = Fib(n-1)+Fib(n-2)+Fib(n-3)+..........+Fib(n-n)=Fib(0)+Fib(1)+Fib(2)+.......+Fib(n-1)
      ����ΪFib(n-1)=Fib(0)+Fib(1)+Fib(2)+.......+Fib(n-2)
      ��ʽ����ã�Fib(n)-Fib(n-1)=Fib(n-1)  =====��Fib(n)=1,n=1
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

