/*
��Ŀ����ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.
     �򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

/*
˼·1�����¿���һ���ռ䣬�ռ临�ӶȺ�ʱ�临�ӶȾ�ΪO(n)
*/

class Solution {
public:
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



/*
˼·2���ڲ��������ռ������£���ԭ�ַ��������޸ġ���ͳ�ƿո������Ȼ�������滻�ո��
     ���ַ������ȣ���������ָ��Ӻ���ǰ�������滻��ʱ�临�Ӷ�O��n��.
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
        int newlen = len + 2 * numspace;  //�滻�ո����ַ�������
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
