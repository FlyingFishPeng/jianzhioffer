/*
  ��Ŀ��������1���ֵĴ�������1��n������1���ֵĴ�������
*/

/*˼·���ο�CSDN���͵ķ������̣�weightΪ��ǰҪͳ�Ƶ�λ��round�ǵ�ǰλ��λ������ֵ��former�ǵ�ǰλ��λ����ֵ
	��weightΪ0����1���ִ���Ϊround*base
	��weightΪ1����1���ִ���Ϊround*base+former+1
	��weight����1����1���ִ���Ϊrount*base+base
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
            round = tmp / 10;    //��ǰλ�ĸ�λ
            weight = tmp % 10;   //��ǰλ
            former = n % base;    //��ǰλ�ĵ�λ
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






