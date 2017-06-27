class Solution {
/*
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
     请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
*/


/*
思路：从数组右上角开始查找，若该数等于target，直接返回true；
     如果小于target，进入下一行；否则，进入前一列。
*/
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int row = array.size();  //行数
        int volume = array[0].size();  //列数
        int r = 0, v = volume - 1;
        while(r < row && v >= 0)
        {
            if(array[r][v] == target)
                return true;
            else if(array[r][v] < target)
                ++ r;
            else
                -- v;
        }
        return false;
    }
};
