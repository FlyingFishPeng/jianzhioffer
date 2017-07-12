/*
思路：打印1到最大的n位数：输入数字n，按顺序打印出从1到最大的n位十进制数。
*/

/*
思路：要考虑到n很大的情况，因此即使用了long long int 也不能解决，此时可以借助字符串。
      从字符串的最高位(对应着整数的最低位)开始加1，逢10就进位，该位置0，进位符号置1.
      难点：
      1、如何判断是否达到了最大值？要对字符串的最低位进行判断，若该位加了进位位
      后为10，说明达到了最大值
      2、如何按习惯打印98，而不是098？设置一个flag辅助进行查找字符串中从左往右第一个不为
      0的位，从该位开始再打印数据。
      要注意的问题：如果需要打印1到最大的n位数，字符数组大小要设置为n+1，因为字符串最后一位为'\0'。
      将此字符数组用memset全部初始化为'0',最后一位置'\0'
*/
#include <iostream>
#include <string.h>
using namespace std;

bool Increment(char num[])
{
    int len = strlen(num);
    bool isOverFlow = false;
    int up = 0;
    for(int i = len - 1; i >= 0; i --)
    {
        int tmp = num[i] - '0' + up;
        if(i == len - 1)
            tmp ++;

        if(tmp == 10)   //加1后如果为10，则该位置0，且将进位位置1
        {
            if(i == 0)    //若该位为最高位，说明已经达到了最大值，退出
            {
                isOverFlow = true;
            }
            else
            {
                num[i] = '0';
                up = 1;     //进位符号置1
            }
        }

        else
        {
            num[i] = tmp + '0';     //目前加了进位的位没有再进位，直接退出循环
            break;
        }
    }
    return isOverFlow;
}

void PrintNumber(char num[])
{
    int len = strlen(num);
    bool flag = true;   //辅助找到第一个不为0的高位
    for(int i = 0; i < len; i++)
    {
        if(flag && num[i] != '0')
            flag = false;

        if(!flag)
            cout << num[i];
    }
    cout << endl;
}



int main()
{
    int n;
    cout << "请输入一个正整数：" << endl;
    cin >> n;
    while(n <= 0)
    {
        cout << "请重新输入一个正确的数！" << endl;
        cin >> n;
    }
    char num[n+1];    //num要设置为n+1位的，因为字符串最后一位有个'\0'
    memset(num, '0', n);
    num[n] = '\0';
    while(!Increment(num))
    {
        PrintNumber(num);
    }
    return 0;
}
