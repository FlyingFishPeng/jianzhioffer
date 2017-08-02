/*
  ��Ŀ����С��K����������n���������ҳ�������С��K������
        ��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/

/*
  ˼·�����ô󶥶ѵ�˼·���ڶ��д洢k������Ȼ�����������Ĺ��������θ�
        �Ѷ����ݶԱȣ����С�ڶѶ����ݣ����ø����ݴ��档����multisetʵ��
        �󶥶ѡ�
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k <= 0 || input.size() < k)
            return res;

        multiset<int, greater<int>> tmp;    //��multiset��greaterʵ�ִ󶥶�
        int len = input.size();
        int max;
        for(int i = 0; i < len; i++)
        {
            if(tmp.size() < k)
            {
                tmp.insert(input[i]);    //����tmp����k������
            }
            else
            {
                max = *tmp.begin();  //���tmp�����ֵ
            	if(input[i] < max)   //�����ǰֵ�ڴ�tmp����Сֵ������Сֵɾȥ������ǰֵ����
            	{
                	tmp.erase(max);
                	tmp.insert(input[i]);
            	}
            }

        }

        multiset<int>::iterator itr = tmp.begin();
        for(; itr != tmp.end(); itr++)
        {
            res.push_back(*itr);
        }
        return res;
    }
};
