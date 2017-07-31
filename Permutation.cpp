/*
  ��Ŀ���ַ��������С�����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
        ���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
        ����һ���ַ���,���Ȳ�����9(�������ַ��ظ�),�ַ�ֻ������Сд��ĸ��
*/

/*
  ˼·���Ȱѵ�һ���ַ���֮��������ַ�������Ȼ��̶���һ���ַ���������ַ���ȫ�����С�
        ������ַ�Ҳ��������˼�����С��ܽ��������ݹ顣��ĿҪ�����ֵ������У���������֮��
        ��Ҫʹ��STL��sort��unique��erase��������������޼���
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.length() > 9 || str.length() < 1)
            return res;

        int len = str.size();
        PermutationHelp(str, res, 0, len);
        sort(res.begin(), res.end());      //����������unique���ظ��ַ����ƶ�����������棬�����eraseɾ�������
        auto itr = unique(res.begin(), res.end());
        res.erase(itr, res.end());
        return res;
    }

    void PermutationHelp(string &tmpstr, vector<string> &res, int begin, int len)
    {

        for(int i = begin; i < len; i++)
        {
             res.push_back(tmpstr);
             swap(tmpstr[begin], tmpstr[i]);   //������һ��Ԫ�غ͵�i��Ԫ��
        	 PermutationHelp(tmpstr, res, begin + 1, len);
             swap(tmpstr[begin], tmpstr[i]);   //���������������������ִ�е���һ��i��ʱ���൱�����ڴ˴ν����Ļ����Ͻ�����I�͵�begin��Ԫ�أ��ظ�
        }
    }
};
