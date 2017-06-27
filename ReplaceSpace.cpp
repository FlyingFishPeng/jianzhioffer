/*
题目：请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.
     则经过替换之后的字符串为We%20Are%20Happy。
*/

/*
思路1：重新开辟一个空间，空间复杂度和时间复杂度均为O(n)
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
		char str2[length];
		strcpy(str2,str);
        int len=strlen(str);
        for(int i=0,j=0; i<len+1 ;i++) //length不是字符串长度！是分配给传进来的字符串的空间大小！！！
    	{
        if(str2[i]==' ')
        {
            str[j++]='%';
            str[j++]='2';
            str[j++]='0';
        }
        else
            str[j++]=str2[i];

    }
   }

};



/*
思路2：在不申请多余空间的情况下，在原字符串上做修改。先统计空格个数，然后计算出替换空格后
     的字符串长度，利用两个指针从后往前遍历和替换，时间复杂度O（n）.
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(str == nullptr)
            return;
        int len = strlen(str);
        int numspace = 0;
        for(int i = 0; i < len; i++)
        {
            if(str[i] == ' ')
                ++ numspace;
        }
        int newlen = len + 2 * numspace;  //替换空格后的字符串长度
        int index1 = len, index2 = newlen;
        while(index1 >= 0)
        {
            if(str[index1] == ' ')
            {
                str[index2 --] = '0';
                str[index2 --] = '2';
                str[index2 --] = '%';
            }
            else
                str[index2 --] = str[index1];
            -- index1;
        }
   }

};
