/*
   ��Ŀ����һ��ֻ����һ�ε��ַ�����һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)����
         ����һ��ֻ����һ�ε��ַ�,����������λ��
*/

/*
   ˼·������һ����ϣ�����ַ���ASCII����Ϊ����������һ���ַ������ڱ����Ĺ����н�ÿ���ַ�
         ��Ӧ�Ĺ�ϣ��Ĺ�ϣֵ��1��Ȼ���ٱ���һ���ַ�����������ÿ���ַ�ʱ������Ӧ�Ĺ�ϣֵ
         �Ƿ�Ϊ1�����ر������ĵ�һ����ϣֵΪ1���ַ�λ�á�

   ��Ҫע��ĵط���1��memset�������÷���
                    memset(�������� ��ʼֵ�� sizeof(������))   //��char���������ʼ��ֵֻ��Ϊ0

                   2����Ϊchar���͵�������8λ��������256���ַ��Ŀ����ԣ���˹�ϣ��Ĵ�С����
                      Ϊ256��
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty() || str.size() > 10000)
            return -1;

        const int len = 256;    //�����256���ַ�
        int hashtable[len];
        memset(hashtable, 0, sizeof(hashtable));   //��ʼ����ÿһλ����0;
        auto itr = str.begin();
        while(itr != str.end())
        {
            ++ hashtable[(*itr)];    //���ַ���ascii��ֵ��Ϊ���������Ӧ��λ��1
            ++ itr;
        }


        //�ٱ���һ���ַ������ҳ���һ��ʹ�ù�ϣֵΪ1���ַ�λ��
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
