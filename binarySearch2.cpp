/*
非递归的二分查找
arrat：数组,n:数组的大小; target:查找的数据; 返回target所在数组的下标
*/
int binarySearch2(int arr[], int n, int target)
{
    int low = 0, high = n, middle = 0;
    while(low < high)
    {
        middle = low + (high - low) / 2;
        if(arr[middle] == target)
            return middle;
        else if(arr[middle] > target)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return -1;
}
