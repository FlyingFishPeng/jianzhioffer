/*
  ��Ŀ���������ų���С����������һ�����������飬����������������ƴ�������ų�һ��������ӡ
        ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ����������������
        �ɵ���С����Ϊ321323��
*/

/*˼·�� �������е��������������ʽ�������򣬼�����ab >ba, �� a > b; ���� a < b��
		������������ִ���һ���ַ������������Ҫע����ǣ��Ƚ�������Ҫ����Ϊstatic���ͣ�
        ��Ϊ����Ϊ��ĳ�Ա����ʱ��Ĭ��ӵ��һ��thisָ�룬������sort��������Ҫʹ�õ�����
        �����Ͳ�һ�����ᱨ��
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
    	string res;
        if(numbers.empty())
            return res;
        sort(numbers.begin(), numbers.end(), cmp);

        for(auto & s : numbers)
        {
        	res += to_string(s);
        }
        return res;
    }

    static bool cmp(int a, int b)
    {
        //�Ƚ�a��b��ϳ�ab��ba
        string str1 = to_string(a) + to_string(b);
        string str2 = to_string(b) + to_string(a);
        int ab = stoi(str1);   //ת��Ϊ����
        int ba = stoi(str2);
        return ab < ba;
    }
};

