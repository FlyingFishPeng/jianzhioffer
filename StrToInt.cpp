#include <iostream>
#include <cstring>
using namespace std;
/*
    实现atoi函数。
    主要考虑的问题：输入字符串为空，子串前面、中间和后面有空格，第一个字符为+或者-，子串中有非数字字符，溢出。
    如果异常情况和字符串“0”均使结果为0，要加一个全局变量进行判断。
    输入测试用例：
    空串、正数、负数、0、带特殊符号的数、最大的正整数和最小的负整数、前后有空格

*/

bool flag = 1;   //全局变量用于判断输出0的原因，如果是因为字符串为空或者有特殊符号而输出0，则flag=1，其它原因flag=0
int StrToInt(string str)
{
    if(str.empty())
    {
        flag = 1;
        return 0;
    }

    int len = str.length();
    bool minus = false;   //判断正负号
    long long int res = 0;

    int index = 0;
    for(; index < len; index ++)  //跳过最前面的空格
    {
        if(str[index] != ' ')
            break;
    }

    if(str[index] == '-')   //判断正负号
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
                if((minus == true && (-1)*res < (signed int)0x80000000) || (minus == false && res > 0x7FFFFFFF))   //判断溢出
                {
                    res = 0;
                    break;
                }
                index++;
            }
            else         //有特殊符号
            {
                //res = 0;
                break;
            }
        }
    }
    if(minus)
        res = -1 * res;
    if(str[index] != '\0')     //处理子串后面全为空格的情况（正常输出res），以及有特殊字符的情况（输出0）
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
    if(str[index] == '\0')     //如果此时str[index]为'\0',说明前面的字符都是合法的，不是异常情况导致res为0
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



