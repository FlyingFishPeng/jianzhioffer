/*
  题目：最长回文子串。对于一个字符串，请设计一个高效算法，计算其中最长回文子串的长度。
        给定字符串A以及它的长度n，请返回最长回文子串的长度。
*/

/*
  思路：利用动态规划的思想。构造一个dp[n][n]的矩阵，dp[i][j]表示下标i到j的子串是否为回文
        子串(i<j)。如果dp[i+1][j-1]为回文子串且A[i] == A[j]，则dp[i][j]为回文串。从长度为
        len = max_len + 1的子串开始判断，直到len为n，每种长度的子串均从i = 0开始向后遍历
*/

class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        if(n <= 0)
            return 0;

        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int max_len = 1, max_start = 0;    //最长回文子串的长度初始化为1,max_start为最长回文串的起点
        for(int i = 0; i < n; i++)        //初始化,对角线上和相邻的均为true
        {
            dp[i][i] = true;
            if(A[i] == A[i+1])
            {
                dp[i][i+1] = true;
                max_len = 2;
                max_start = i;
            }
        }

        for(int len = max_len + 1; len <= n; len ++)  //求不同长度下的回文子串，最长的回文子串可能为n
        {
            for(int i = 0; i <= n - len; i++)   //每种长度均从i=1开始往后遍历
            {
                int j = i + len - 1;
                if((dp[i+1][j-1] == true) && (A[i] == A[j]))   //如果dp[i+1][j-1]为回文子串且A[i] == A[j]，则dp[i][j]为回文串
                {
                    dp[i][j] = true;
                    max_len = len;
                    max_start = i;
                }
            }
        }
        return max_len;
    }
};
