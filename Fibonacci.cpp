/*
   쳲��������У������n���ֵ��n<39.
*/

/*
   ˼·���ݹ����ѭ�����ݹ�ʱ�临�Ӷȸߣ�ѭ����ʱ�临�Ӷ�O(n)
*/

/*
//�ݹ�
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


//ѭ��
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
