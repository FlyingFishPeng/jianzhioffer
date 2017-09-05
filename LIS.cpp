/*
   题目：最长上升子序列。
*/

/*
    思路：动态规划。L[i]的计算方法为：从前i-1个数中找出满足a[j]<a[i]（1<=j<i）条件的最大的L[j]，L[i]等于L[j]+1。
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
