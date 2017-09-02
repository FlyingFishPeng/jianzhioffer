#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

/*
    题目：无重复字符的最长子字符串。
*/

/*
    思路:遍历该字符串，每遍历一个字母时，利用map去找该字母最近一次出现是什么时候，
         中间这一段便是无重复字符的字符串。
*/
int lengthOfLongestSubstring(string str)
{
    // write your code here
    if (str.empty())
        return 0;
    int len = str.size();
    int max = 0, tmp = 0, start = 0;
    map<char, int> hash;   //char对应字符串中的字符，int对应字符出现的位置

    for (int i = 0; i < len; i++)
    {
        if (hash[str[i]] >= start)   // 当前字符在start之后出现过，start从最近一次出现的位置之后重新开始
        {
            start = hash[str[i]] + 1;
            hash[str[i]] = i;   //将当前位置存在哈希中
        }
        else
        {
            tmp = i - start + 1;  // 从上次出现的那个字符后面的位置重新开始计算长度
            hash[str[i]] = i;  // 哈希位置置为当前字符位置
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
