/*
   题目：第一个只出现一次的字符。在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找
         到第一个只出现一次的字符,并返回它的位置
*/

/*
   思路：创建一个哈希表，将字符的ASCII码作为索引，遍历一遍字符串，在遍历的过程中将每个字符
         对应的哈希表的哈希值加1。然后再遍历一遍字符串，遍历到每个字符时检查其对应的哈希值
         是否为1，返回遍历到的第一个哈希值为1的字符位置。

   需要注意的地方：1、memset函数的用法：
                    memset(数组名， 初始值， sizeof(数组名))   //非char类型数组初始化值只能为0

                   2、因为char类型的数据有8位，即共有256种字符的可能性，因此哈希表的大小设置
                      为256。
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty() || str.size() > 10000)
            return -1;

        const int len = 256;    //最多有256种字符
        int hashtable[len];
        memset(hashtable, 0, sizeof(hashtable));   //初始化，每一位都置0;
        auto itr = str.begin();
        while(itr != str.end())
        {
            ++ hashtable[(*itr)];    //将字符的ascii码值作为索引，其对应的位加1
            ++ itr;
        }


        //再遍历一次字符串，找出第一个使得哈希值为1的字符位置
        int length = str.size(), index = 0;
        while(index < length)
        {
        	if(hashtable[str[index]] == 1)
                return index;
            else
                ++ index;
        }
        return -1;
    }
};
