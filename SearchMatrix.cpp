class Solution {
/*
��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
     �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�����
*/


/*
˼·�����������Ͻǿ�ʼ���ң�����������target��ֱ�ӷ���true��
     ���С��target��������һ�У����򣬽���ǰһ�С�
*/
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int row = array.size();  //����
        int volume = array[0].size();  //����
        int r = 0, v = volume - 1;
        while(r < row && v >= 0)
        {
            if(array[r][v] == target)
                return true;
            else if(array[r][v] < target)
                ++ r;
            else
                -- v;
        }
        return false;
    }
};
