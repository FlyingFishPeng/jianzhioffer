/*
  ��Ŀ�������е������
*/

/*˼·�����չ鲢�����˼·�������黮��Ϊ���������֣������������ֵ�ĩβ�ֱ���ǰ��������
		��ߵ�ֵ�����ұߵ�ֵʱ˵����������ԣ����ұߵ�ָ���ʱָ���λ��֮ǰ����������
        ���ʱ���ָ��ָ������γ�����ԣ���sum��ֵ������Щ���ĸ�����������ߵ�ֵ����
        tmp�����У�tmp����Ҳ�ǴӺ���ǰ���ã��൱���������򣬷�ֹ�����ٶ��жϹ��������
        �����жϣ������򣬽��ұߵ�������tmp��
*/
class Solution {
public:
    long int sum = 0;  //��ֹsum���������������Ϊ������
    int InversePairs(vector<int> data) {
        if(data.size() == 0)
            return sum;
        merge(data, 0, data.size() - 1);
        return sum % 1000000007;
    }

    void merge(vector<int> &arr, int begin, int end)
    {
    	int mid = (begin + end)/2;
        if(begin < end)
        {
        	merge(arr, begin, mid);
            merge(arr, mid + 1, end);
            mergesort(arr, begin, mid, end);
        }
    }

    void mergesort(vector<int> &arr, int begin, int mid, int end)
    {
    	int p1 = mid, p2 = end, n = end - begin + 1;
        int tmp[n], p3 = n - 1;
        while(p1 >= begin && p2 >= mid + 1)
        {
        	if(arr[p1] > arr[p2])
            {
            	int num = p2 - mid;    //�Ұ��������p2��ָԪ��ǰ���Ԫ�ظ���p2-(mid+1)+1
                sum += num;
                tmp[p3--] = arr[p1--];   //p1�������鲢��ָ��ǰ��
            }
            else
            {
            	tmp[p3--] = arr[p2--];
            }
        }

        while(p1 >= begin)
            tmp[p3--] = arr[p1--];

        while(p2 >= mid + 1)
            tmp[p3--] = arr[p2--];

        for(int j = 0; j < n; j++)
            arr[begin+j] = tmp[j];   //���ź�����������ԭ����
    }

};










