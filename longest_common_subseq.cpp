/*
   题目：最长公共子序列
*/

/*
   思路：动态规划
*/


#include <iostream>
#include <string>
using namespace std;
#define MAXSIZE 100

int max(int num1, int num2)
{
    return num1>num2?num1:num2;
}

int main()
{
    char strA[MAXSIZE];
    char strB[MAXSIZE];
    int maxLen[MAXSIZE][MAXSIZE] = {0};
    int i;
    int j;
    cin >> strA;
    cin >> strB;
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    //递推公式：A[i-1] == B[j-1],则maxLen[i][j] = maxLen[i-1][j-1] + 1；否则maxLen[i][j] = max(maxLen[i-1][j], maxLen[i][j-1]);
    for (i=1; i<=lenA; i++)
        for (j=1; j<=lenB; j++)       
        {
            if (strA[i-1] == strB[j-1])
                maxLen[i][j] = maxLen[i-1][j-1] + 1;
            else
                maxLen[i][j] = max(maxLen[i-1][j], maxLen[i][j-1]);
        }
    cout << maxLen[lenA][lenB] << endl;
    return 0;
}
