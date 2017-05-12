#include <iostream>
using namespace std;

/*题目:二维数组中的查找，在一个二维维数组中，每一行都按照从左到右递增的顺序
  排序，每一列都按照从上到下递增的顺序排序，完成一个函数，输入一个这样的二维
  数组和一个整数，判断数组中是否含有该整数
*/

/*思路：从数组左上角开始寻找，若左上角的数大于目标值，则删除该数所在列，若小于
  该值，则删除该数所在行。
*/
int main()
{
    int array[4][4]= {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    int target;
    cout<<"输入一个整数："<<endl;
    cin>> target;
    int i, j, row = 4, column = 4, index = -1, flag = 0;
    if(array != NULL && row>0 && column>0)
    {
        i=0;
        j=column-1;
        while(i <= row-1 && j >= 0)
        {
            if(array[i][j] > target)
                j--;    //删除列
            else if(array[i][j] == target)
            {
                flag = 1;
                break;
            }
            else
                i++;  //删除行
        }
    }
    if(flag == 0)
        cout << "false" << endl;
    else
        cout << "true" << endl;
    return 0;
}
