#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

/*
    ��Ŀ�����ظ��ַ�������ַ�����
*/

/*
    ˼·:�������ַ�����ÿ����һ����ĸʱ������mapȥ�Ҹ���ĸ���һ�γ�����ʲôʱ��
         �м���һ�α������ظ��ַ����ַ�����
*/
int lengthOfLongestSubstring(string str)
{
    // write your code here
    if (str.empty())
        return 0;
    int len = str.size();
    int max = 0, tmp = 0, start = 0;
    map<char, int> hash;   //char��Ӧ�ַ����е��ַ���int��Ӧ�ַ����ֵ�λ��

    for (int i = 0; i < len; i++)
    {
        if (hash[str[i]] >= start)   // ��ǰ�ַ���start֮����ֹ���start�����һ�γ��ֵ�λ��֮�����¿�ʼ
        {
            start = hash[str[i]] + 1;
            hash[str[i]] = i;   //����ǰλ�ô��ڹ�ϣ��
        }
        else
        {
            tmp = i - start + 1;  // ���ϴγ��ֵ��Ǹ��ַ������λ�����¿�ʼ���㳤��
            hash[str[i]] = i;  // ��ϣλ����Ϊ��ǰ�ַ�λ��
        }
        if (tmp > max)
            max = tmp;
    }
    return max;
}

int main()
{
    string s;
    getline(cin, s);
    int len = lengthOfLongestSubstring(s);
    cout << len;
    return 0;
}
