/*
  题目：顺时针打印矩阵。输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
        例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16，
        则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/*
  思路：先计算圈数：行数和列数中较小的那个值减1除2再加1。然后依次打印每圈，打印的时候先
        从左往右打印最上面一行，再从上打印最右边一列。。。。需要注意的是从右往左和从下
        网上打印的时候需要判断一下该圈是否只有一行或者一列。
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
		if(matrix.empty())
            return res;

        int row = matrix.size(), column = matrix[0].size();
        int steps = ((row < column ? row : column) - 1)/2 + 1;   //计算总圈数
        for(int i = 0; i < steps; i ++)
        {
        	for(int c1 = i; c1 < column - i; c1++)   //从左往右
                res.push_back(matrix[i][c1]);

            for(int r1 = i + 1; r1 < row - i; r1++)         //从上往下
                res.push_back(matrix[r1][column - i - 1]);

            for(int c2 = column - i - 2; (c2 >= i) && (row - i - 1) != i; c2--)       //从右往左,判断此圈是否只有一行
                res.push_back(matrix[row - i - 1][c2]);

            for(int r2 = row - i - 2; (r2 > i) && i != (column - i - 1); r2--)    //从下到上，判断此圈是否只有一列
                res.push_back(matrix[r2][i]);
        }
        return res;

    }
};
