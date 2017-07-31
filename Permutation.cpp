/*
  题目：字符串的排列。输入一个字符串,按字典序打印出该字符串中字符的所有排列。
        例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
        输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

/*
  思路：先把第一个字符和之后的所有字符交换，然后固定第一个字符，求后面字符的全部排列。
        后面的字符也按照这种思想排列。总结下来：递归。题目要求按照字典序排列，则排列完之后
        需要使用STL的sort、unique和erase函数进行排序和修剪。
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.length() > 9 || str.length() < 1)
            return res;

        int len = str.size();
        PermutationHelp(str, res, 0, len);
        sort(res.begin(), res.end());      //先排序，再用unique把重复字符串移动到容器最后面，最后用erase删除多余的
        auto itr = unique(res.begin(), res.end());
        res.erase(itr, res.end());
        return res;
    }

    void PermutationHelp(string &tmpstr, vector<string> &res, int begin, int len)
    {

        for(int i = begin; i < len; i++)
        {
             res.push_back(tmpstr);
             swap(tmpstr[begin], tmpstr[i]);   //交换第一个元素和第i个元素
        	 PermutationHelp(tmpstr, res, begin + 1, len);
             swap(tmpstr[begin], tmpstr[i]);   //换回来，如果不换回来，执行到下一个i的时候相当于是在此次交换的基础上交换第I和第begin个元素，重复
        }
    }
};
