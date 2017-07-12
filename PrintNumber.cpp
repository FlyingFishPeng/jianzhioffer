/*
˼·����ӡ1������nλ������������n����˳���ӡ����1������nλʮ��������
*/

/*
˼·��Ҫ���ǵ�n�ܴ���������˼�ʹ����long long int Ҳ���ܽ������ʱ���Խ����ַ�����
      ���ַ��������λ(��Ӧ�����������λ)��ʼ��1����10�ͽ�λ����λ��0����λ������1.
      �ѵ㣺
      1������ж��Ƿ�ﵽ�����ֵ��Ҫ���ַ��������λ�����жϣ�����λ���˽�λλ
      ��Ϊ10��˵���ﵽ�����ֵ
      2����ΰ�ϰ�ߴ�ӡ98��������098������һ��flag�������в����ַ����д������ҵ�һ����Ϊ
      0��λ���Ӹ�λ��ʼ�ٴ�ӡ���ݡ�
      Ҫע������⣺�����Ҫ��ӡ1������nλ�����ַ������СҪ����Ϊn+1����Ϊ�ַ������һλΪ'\0'��
      �����ַ�������memsetȫ����ʼ��Ϊ'0',���һλ��'\0'
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

        if(tmp == 10)   //��1�����Ϊ10�����λ��0���ҽ���λλ��1
        {
            if(i == 0)    //����λΪ���λ��˵���Ѿ��ﵽ�����ֵ���˳�
            {
                isOverFlow = true;
            }
            else
            {
                num[i] = '0';
                up = 1;     //��λ������1
            }
        }

        else
        {
            num[i] = tmp + '0';     //Ŀǰ���˽�λ��λû���ٽ�λ��ֱ���˳�ѭ��
            break;
        }
    }
    return isOverFlow;
}

void PrintNumber(char num[])
{
    int len = strlen(num);
    bool flag = true;   //�����ҵ���һ����Ϊ0�ĸ�λ
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
    cout << "������һ����������" << endl;
    cin >> n;
    while(n <= 0)
    {
        cout << "����������һ����ȷ������" << endl;
        cin >> n;
    }
    char num[n+1];    //numҪ����Ϊn+1λ�ģ���Ϊ�ַ������һλ�и�'\0'
    memset(num, '0', n);
    num[n] = '\0';
    while(!Increment(num))
    {
        PrintNumber(num);
    }
    return 0;
}
