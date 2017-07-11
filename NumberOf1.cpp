/*
  题目：二进制中1的个数：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

/*
   思路1：一种方法是右移n，然后和1与运算，但是此方法不能应对n是负数的情况，因为负数右移的过程中高位会全部补1，陷入死循环，可以通过左移1来解决
*/

class Solution {
public:
    int  NumberOf1(int n) {
    int countn = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n & flag)
        	countn ++;
        flag = flag << 1;
    }
    return countn;
     }
};

/*
  思路2：每次让n减去1后再与n进行与运算，这样相当于把n最右边的1置0了，
       重复这样的操作，直至将n中的1全部置0，即n == 0，统计这样的操作次数即n中1的个数
*/
class Solution {
public:
    int  NumberOf1(int n) {
    int countn = 0;
    while(n)
    {
        countn ++;
        n = (n - 1) & n;
    }

    return countn;
     }
};

