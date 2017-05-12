class Solution {
public:
/*思路：借助一个新字符串实现*/
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
