/*
   ��Ŀ������������С�
*/

/*
    ˼·����̬�滮��L[i]�ļ��㷽��Ϊ����ǰi-1�������ҳ�����a[j]<a[i]��1<=j<i������������L[j]��L[i]����L[j]+1��
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1007],dp[1007],n;

int LIS(int *a)
{
    int i,j,ans,m;
    dp[1] = 1;
    ans = 1;
    for(i = 2; i <= n; i++)
    {
        m = 0;
        for(j = 1; j < i; j++)
        {
            if(dp[j]>m && a[j]<a[i])
				m = dp[j];
        }
        dp[i] = m+1;
        if(dp[i]>ans)
			ans = dp[i];
    }
    return ans;
}
