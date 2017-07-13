/*
  题目：调整数组顺序使奇数位于偶数前面。输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
        使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，
        偶数和偶数之间的相对位置不变。
*/

/*
  思路：设置两个指针p1和p2，分别指向数组首尾。p1向后移动，p2向前移动，当p1指向偶数且p2指向奇数
        时交换指向的内存的值。重复操作，直至p2在p1前面一个位置。
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
  		if(array.empty())
            return;
        int len = array.size();
        int p1 = 0, p2 = len - 1;   //p1指向头部，p2指向尾部
        while(p2 > p1)   //两个指针一前一后时停止
        {
            while((p1 < p2) && (array[p1] % 2 != 0))  //p1向后移动，直至遇到偶数停止
				p1++;
            while((p1 < p2) && (array[p1] % 2 == 0))   //p2向前移动，直至遇到基数时停止
                p2--;
            if(p1 < p2)
            {
            	swap(array[p1], array[p2]);
            }
        }
    }
};
