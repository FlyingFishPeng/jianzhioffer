#include <iostream>
using namespace std;

/*��Ŀ:��ά�����еĲ��ң���һ����άά�����У�ÿһ�ж����մ����ҵ�����˳��
  ����ÿһ�ж����մ��ϵ��µ�����˳���������һ������������һ�������Ķ�ά
  �����һ���������ж��������Ƿ��и�����
*/

/*˼·�����������Ͻǿ�ʼѰ�ң������Ͻǵ�������Ŀ��ֵ����ɾ�����������У���С��
  ��ֵ����ɾ�����������С�
*/
int main()
{
    int array[4][4]= {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    int target;
    cout<<"����һ��������"<<endl;
    cin>> target;
    int i, j, row = 4, column = 4, index = -1, flag = 0;
    if(array != NULL && row>0 && column>0)
    {
        i=0;
        j=column-1;
        while(i <= row-1 && j >= 0)
        {
            if(array[i][j] > target)
                j--;    //ɾ����
            else if(array[i][j] == target)
            {
                flag = 1;
                break;
            }
            else
                i++;  //ɾ����
        }
    }
    if(flag == 0)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    return 0;
}
