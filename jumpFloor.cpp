/*
  ��Ŀ��������̨�ף�һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
*/

/*
  ˼·��쳲��������У�Fib(n)=1,n=1;
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


