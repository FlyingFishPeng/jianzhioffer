/*
��Ŀ����ת�������С���֡���һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
 ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}
 ��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

/*
˼·�����ö��ֲ��ҵ�˼�룬��������ָ��ֱ�ָ����β������Ԫ�ش�С��������ָ�롣
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
    	if(rotateArray.empty())
            return 0;
        int len = rotateArray.size();
        int start = 0, end = len - 1;
        int min = 0;
        while(rotateArray[start] >= rotateArray[end])
        {
            if(end == start + 1)   //����ָ�뿿��һ��
            {
                min = end;
                break;
            }

            int mid = start + (end - start)/2;
            if(rotateArray[end] == rotateArray[start] == rotateArray[mid])   //����1 0 1 1 1�����������
        	{
            	min = start;
            	for(int i = start + 1 ; i < end ; i++)
           	    {
                	if(rotateArray[i] < rotateArray[min])
                        min = i;
           		}
                break;
            }
            if(rotateArray[mid] >= rotateArray[start])  //�м��Ԫ�ش�����Ԫ�أ�˵����СԪ���ں�벿��
                start = mid;
            else if(rotateArray[mid] <= rotateArray[end])   //�м�Ԫ��С��βԪ�أ�˵����СԪ����ǰ�벿��
                end = mid;
        }
        return rotateArray[min];
    }
};







