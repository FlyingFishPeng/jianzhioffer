/*
   ��Ŀ����������������͡�

/*
   ˼·���ӵ�һ��Ԫ�ؿ�ʼ�ۼӣ��жϵ�ǰsum�Ƿ����maxsum��������������maxsum;�����ǰsumΪ������sum���㣬
         ����һ������ʼ�ۼӣ��Դ����Ƽ��ɡ������֪�������е������յ㣬����ÿ�ν�tmpsum����ʱ����������Ϊ��
         һ��startֵ��ÿ�θ���sumʱ����ʱ��start����Ϊ�յ㡣

         ����˼��Ͷ�̬�滮���ƣ�
          sum(i) = array[i]  ----��� i=0 ���� sum(i-1)<0
                   sum(i-1)+array[i]  ----��� sum(i-1)>0
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {

        if(array.empty())
            return 0;

        int sum = 0, maxsum = -1000,len = array.size();
        for(int i = 0; i < len; i++)
        {
        	sum += array[i];
            if(sum > maxsum)         //���sumֵ�����ϴα����maxsum�������maxsum
                maxsum = sum;

            else if(sum <= 0)    //sumС��0����sum���¸�����ʼ�ۼ�
                sum = 0;
        }
        return maxsum;
    }
};
