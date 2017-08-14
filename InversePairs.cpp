/*
  题目：数组中的逆序对
*/

/*思路：按照归并排序的思路，将数组划分为左右两部分，从左右两部分的末尾分别向前遍历，当
		左边的值大于右边的值时说明存在逆序对，则右边的指针此时指向的位置之前的数均可以
        与此时左边指针指向的数形成逆序对，将sum的值加上这些数的个数，并将左边的值放入
        tmp数组中（tmp数组也是从后往前放置，相当于升序排序，防止后期再对判断过的逆序对
        进行判断）。否则，将右边的数放入tmp。
*/
class Solution {
public:
    long int sum = 0;  //防止sum过大溢出，将其设为长整型
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
            	int num = p2 - mid;    //右半边序列中p2所指元素前面的元素个数p2-(mid+1)+1
                sum += num;
                tmp[p3--] = arr[p1--];   //p1存入数组并将指针前移
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
            arr[begin+j] = tmp[j];   //用排好序的数组更新原数组
    }

};










