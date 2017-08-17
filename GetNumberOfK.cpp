/*
  ��Ŀ�����������������г��ֵĴ�����
*/

/*
  ˼·�����ö��ֲ��ҵ�˼·���ҵ�k����Ҫ�ж���ǰ��ͺ���������Ƿ����k��
        �Ӷ���һ�����ö����ҵ���һ�������һ��k��λ�á��ɷֱ����õݹ��ѭ��
        ʵ�֡�
*/

//�ݹ�

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int k_start = GetFirestK(data, 0, data.size() - 1, k);
        int k_end = GetLastK(data, 0, data.size() - 1, k);
        int len = 0;
        if(k_start > -1 && k_end > -1)
            len = k_end - k_start + 1;
        return len;
    }

    int  GetFirestK(const vector<int> & data, int low, int high, int k)
    {
		if(low > high)
            return -1;
        int mid = (low + high) / 2;
        if(data[mid] == k)
        {
            if(data[mid - 1] != k|| mid == 0)    //ǰһ����������k����ǰλ����k��һ�γ��ֵ�λ��
                return mid;
            else        //ǰһ��������k����k��һ�γ��ֵ�λ����ǰ���
                high = mid - 1;
            }

        else if(data[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;

        return GetFirestK(data, low, high, k);
    }

    int  GetLastK(const vector<int> & data, int low, int high, int k)
    {
		if(low > high)
            return -1;
        int mid = (low + high) / 2;
        if(data[mid] == k)
        {
            if(data[mid + 1] != k || mid == data.size() - 1)    //��һ����������k����ǰλ����k���һ�γ��ֵ�λ��
                return mid;
            else                  //��һ��������k����k���һ�γ��ֵ�λ���ں���
                low = mid + 1;
        }

        else if(data[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;

        return  GetLastK(data, low, high, k);
    }
};










