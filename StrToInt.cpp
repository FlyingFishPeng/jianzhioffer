#include <iostream>
#include <cstring>
using namespace std;
/*
    ʵ��atoi������
    ��Ҫ���ǵ����⣺�����ַ���Ϊ�գ��Ӵ�ǰ�桢�м�ͺ����пո񣬵�һ���ַ�Ϊ+����-���Ӵ����з������ַ��������
    ����쳣������ַ�����0����ʹ���Ϊ0��Ҫ��һ��ȫ�ֱ��������жϡ�
    �������������
    �մ���������������0����������ŵ�������������������С�ĸ�������ǰ���пո�

*/

bool flag = 1;   //ȫ�ֱ��������ж����0��ԭ���������Ϊ�ַ���Ϊ�ջ�����������Ŷ����0����flag=1������ԭ��flag=0
int StrToInt(string str)
{
    if(str.empty())
    {
        flag = 1;
        return 0;
    }

    int len = str.length();
    bool minus = false;   //�ж�������
    long long int res = 0;

    int index = 0;
    for(; index < len; index ++)  //������ǰ��Ŀո�
    {
        if(str[index] != ' ')
            break;
    }

    if(str[index] == '-')   //�ж�������
    {
        minus = true;
        index ++;
    }
    else if(str[index] == '+')
        index++;

    if(str[index] != '\0')
    {
        while(str[index] != '\0')
        {
            if(str[index] >= '0' && str[index] <= '9')
            {
                res = 10*res + str[index] - '0';
                if((minus == true && (-1)*res < (signed int)0x80000000) || (minus == false && res > 0x7FFFFFFF))   //�ж����
                {
                    res = 0;
                    break;
                }
                index++;
            }
            else         //���������
            {
                //res = 0;
                break;
            }
        }
    }
    if(minus)
        res = -1 * res;
    if(str[index] != '\0')     //�����Ӵ�����ȫΪ�ո��������������res�����Լ��������ַ�����������0��
    {
        while(str[index] != '\0')
        {
            if(str[index] == ' ')
            {
                index++;
            }
            else
            {
                res = 0;
                flag = 0;
                break;
            }
        }
    }
    if(str[index] == '\0')     //�����ʱstr[index]Ϊ'\0',˵��ǰ����ַ����ǺϷ��ģ������쳣�������resΪ0
    {
        flag= 0;
    }
    return (int)res;
}

int main()
{
    string s;
    getline(cin, s);
    int res = StrToInt(s);
    cout << res;
    return 0;
}



