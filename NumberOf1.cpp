/*
  ��Ŀ����������1�ĸ���������һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

/*
   ˼·1��һ�ַ���������n��Ȼ���1�����㣬���Ǵ˷�������Ӧ��n�Ǹ������������Ϊ�������ƵĹ����и�λ��ȫ����1��������ѭ��������ͨ������1�����
*/

class Solution {
public:
    int  NumberOf1(int n) {
    int countn = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
        	countn ++;
        flag = flag << 1;
    }
    return countn;
     }
};

/*
  ˼·2��ÿ����n��ȥ1������n���������㣬�����൱�ڰ�n���ұߵ�1��0�ˣ�
       �ظ������Ĳ�����ֱ����n�е�1ȫ����0����n == 0��ͳ�������Ĳ���������n��1�ĸ���
*/
class Solution {
public:
    int  NumberOf1(int n) {
    int countn = 0;
    while(n)
    {
        countn ++;
        n = (n - 1) & n;
    }

    return countn;
     }
};

