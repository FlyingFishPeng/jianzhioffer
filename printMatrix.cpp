/*
  ��Ŀ��˳ʱ���ӡ��������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
        ���磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16��
        �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/*
  ˼·���ȼ���Ȧ���������������н�С���Ǹ�ֵ��1��2�ټ�1��Ȼ�����δ�ӡÿȦ����ӡ��ʱ����
        �������Ҵ�ӡ������һ�У��ٴ��ϴ�ӡ���ұ�һ�С���������Ҫע����Ǵ�������ʹ���
        ���ϴ�ӡ��ʱ����Ҫ�ж�һ�¸�Ȧ�Ƿ�ֻ��һ�л���һ�С�
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
		if(matrix.empty())
            return res;

        int row = matrix.size(), column = matrix[0].size();
        int steps = ((row < column ? row : column) - 1)/2 + 1;   //������Ȧ��
        for(int i = 0; i < steps; i ++)
        {
        	for(int c1 = i; c1 < column - i; c1++)   //��������
                res.push_back(matrix[i][c1]);

            for(int r1 = i + 1; r1 < row - i; r1++)         //��������
                res.push_back(matrix[r1][column - i - 1]);

            for(int c2 = column - i - 2; (c2 >= i) && (row - i - 1) != i; c2--)       //��������,�жϴ�Ȧ�Ƿ�ֻ��һ��
                res.push_back(matrix[row - i - 1][c2]);

            for(int r2 = row - i - 2; (r2 > i) && i != (column - i - 1); r2--)    //���µ��ϣ��жϴ�Ȧ�Ƿ�ֻ��һ��
                res.push_back(matrix[r2][i]);
        }
        return res;

    }
};
