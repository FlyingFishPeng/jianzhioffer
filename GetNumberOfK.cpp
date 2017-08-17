/*
  题目：数字在排序数组中出现的次数。
*/

/*
  思路：利用二分查找的思路。找到k后，需要判断其前面和后面的数字是否等于k，
        从而进一步利用二分找到第一个和最后一个k的位置。可分别利用递归和循环
        实现。
*/

//递归

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
            if(data[mid - 1] != k|| mid == 0)    //前一个数不等于k，则当前位置是k第一次出现的位置
                return mid;
            else        //前一个数等于k，则k第一次出现的位置在前半段
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
            if(data[mid + 1] != k || mid == data.size() - 1)    //后一个数不等于k，则当前位置是k最后一次出现的位置
                return mid;
            else                  //后一个数等于k，则k最后一次出现的位置在后半段
                low = mid + 1;
        }

        else if(data[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;

        return  GetLastK(data, low, high, k);
    }
};










