/*
    ��Ŀ����ֵ�������η�������һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/

/*
    ˼·������Ŀ�����Ҫ��������1�����������ݵ���Ч�Խ����ж�����ָ��Ϊ����ʱ��������Ϊ0��
                                2���ж�����double����float�������Ƿ����ʱ����ֱ���õȺţ���Ϊ������ڱ�ʾС��ʱ
                                ������ֻ��ͨ������֮��ľ���ֵ�Ƿ��ں�С��һ����Χ�����жϣ�(num1- num2) > -0.00000001 && (num1- num2) < 0.00000001
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
            if((base - 0.0) > -0.00000001 && (base - 0.0) < 0.00000001)      //double�͵����ݲ���ֱ�Ӻ���������ֱ�����Ƚ�
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
