/*
  题目：最小的K个数。输入n个整数，找出其中最小的K个数。
        例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

/*
  思路：利用大顶堆的思路，在堆中存储k个数，然后在向后遍历的过程中依次跟
        堆顶数据对比，如果小于堆顶数据，就用该数据代替。利用multiset实现
        大顶堆。
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k <= 0 || input.size() < k)
            return res;

        multiset<int, greater<int>> tmp;    //用multiset的greater实现大顶堆
        int len = input.size();
        int max;
        for(int i = 0; i < len; i++)
        {
            if(tmp.size() < k)
            {
                tmp.insert(input[i]);    //先向tmp插入k个数据
            }
            else
            {
                max = *tmp.begin();  //求出tmp的最大值
            	if(input[i] < max)   //如果当前值于大tmp的最小值，则将最小值删去并将当前值插入
            	{
                	tmp.erase(max);
                	tmp.insert(input[i]);
            	}
            }

        }

        multiset<int>::iterator itr = tmp.begin();
        for(; itr != tmp.end(); itr++)
        {
            res.push_back(*itr);
        }
        return res;
    }
};
