/*
  ��Ŀ��������Ӵ�������һ���ַ����������һ����Ч�㷨����������������Ӵ��ĳ��ȡ�
        �����ַ���A�Լ����ĳ���n���뷵��������Ӵ��ĳ��ȡ�
*/

/*
  ˼·�����ö�̬�滮��˼�롣����һ��dp[n][n]�ľ���dp[i][j]��ʾ�±�i��j���Ӵ��Ƿ�Ϊ����
        �Ӵ�(i<j)�����dp[i+1][j-1]Ϊ�����Ӵ���A[i] == A[j]����dp[i][j]Ϊ���Ĵ����ӳ���Ϊ
        len = max_len + 1���Ӵ���ʼ�жϣ�ֱ��lenΪn��ÿ�ֳ��ȵ��Ӵ�����i = 0��ʼ������
*/

class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        if(n <= 0)
            return 0;

        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int max_len = 1, max_start = 0;    //������Ӵ��ĳ��ȳ�ʼ��Ϊ1,max_startΪ����Ĵ������
        for(int i = 0; i < n; i++)        //��ʼ��,�Խ����Ϻ����ڵľ�Ϊtrue
        {
            dp[i][i] = true;
            if(A[i] == A[i+1])
            {
                dp[i][i+1] = true;
                max_len = 2;
                max_start = i;
            }
        }

        for(int len = max_len + 1; len <= n; len ++)  //��ͬ�����µĻ����Ӵ�����Ļ����Ӵ�����Ϊn
        {
            for(int i = 0; i <= n - len; i++)   //ÿ�ֳ��Ⱦ���i=1��ʼ�������
            {
                int j = i + len - 1;
                if((dp[i+1][j-1] == true) && (A[i] == A[j]))   //���dp[i+1][j-1]Ϊ�����Ӵ���A[i] == A[j]����dp[i][j]Ϊ���Ĵ�
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
