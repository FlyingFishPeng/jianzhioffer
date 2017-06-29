/*
题目：旋转数组的最小数字。把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}
 的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

/*
思路：利用二分查找的思想，设置两个指针分别指向首尾，根据元素大小更新这俩指针。
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
            if(end == start + 1)   //两个指针靠在一起
            {
                min = end;
                break;
            }

            int mid = start + (end - start)/2;
            if(rotateArray[end] == rotateArray[start] == rotateArray[mid])   //处理1 0 1 1 1这种特殊情况
        	{
            	min = start;
            	for(int i = start + 1 ; i < end ; i++)
           	    {
                	if(rotateArray[i] < rotateArray[min])
                        min = i;
           		}
                break;
            }
            if(rotateArray[mid] >= rotateArray[start])  //中间的元素大于首元素，说明最小元素在后半部分
                start = mid;
            else if(rotateArray[mid] <= rotateArray[end])   //中间元素小于尾元素，说明最小元素在前半部分
                end = mid;
        }
        return rotateArray[min];
    }
};







