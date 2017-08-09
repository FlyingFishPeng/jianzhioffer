/*
  题目：把数组排成最小的数。输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印
        能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排
        成的最小数字为321323。
*/

/*思路： 将数组中的数按定义的排序方式进行排序，即：若ab >ba, 则 a > b; 否则 a < b；
		将排完序的数字串成一个字符串输出即所求。要注意的是，比较器函数要定义为static类型，
        因为其作为类的成员函数时，默认拥有一个this指针，这样和sort函数所需要使用的排序函
        数类型不一样，会报错。
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
    	string res;
        if(numbers.empty())
            return res;
        sort(numbers.begin(), numbers.end(), cmp);

        for(auto & s : numbers)
        {
        	res += to_string(s);
        }
        return res;
    }

    static bool cmp(int a, int b)
    {
        //先将a和b组合成ab和ba
        string str1 = to_string(a) + to_string(b);
        string str2 = to_string(b) + to_string(a);
        int ab = stoi(str1);   //转换为整数
        int ba = stoi(str2);
        return ab < ba;
    }
};

