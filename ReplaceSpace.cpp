class Solution {
public:
/*˼·������һ�����ַ���ʵ��*/
	void replaceSpace(char *str,int length) {
		char str2[length];
		strcpy(str2,str);
        int len=strlen(str);
        for(int i=0,j=0; i<len+1 ;i++) //length�����ַ������ȣ��Ƿ�������������ַ����Ŀռ��С������
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
