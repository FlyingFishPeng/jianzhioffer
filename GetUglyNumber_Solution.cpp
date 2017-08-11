/*
  ��Ŀ����������ֻ��������2��3��5��������������Ugly Number��������6��8���ǳ�������14���ǣ���Ϊ����������7��
        ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
*/

/*
  ˼·�����ö�̬�滮��˼�룬�µĳ�����Ȼ��ǰ��ĳ�������2,3,5��õ�����Сֵ����������2,3,5��Ӧ������ָ��
         �ֱ�Ϊindex2,index3,index5,��ʼֵ��Ϊ0��ÿ��ѭ��ʱ��������ָ���Ӧ��ֵ������Ӧ�����Ӻ�õ�����Сֵ��
         ������Ϊ�µĳ����洢��ͬʱ�ҳ�����ָ���Ӧ��ֵ��ʹ������Զ�Ӧ�����Ӻ�����³�����ָ�룬�������1���´�
         ѭ���У��������ӽ�����һ�ֵ�ָ���Ӧ��ֵ�������³�����
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if(index == 0)
            return 0;

        int *uglynum = new int[index];
        uglynum[0] = 1;

        int i = 1, index2 = 0, index3 = 0, index5 = 0;
        while(i < index)
        {
        	uglynum[i] = min(2 * uglynum[index2], min(3 * uglynum[index3], 5 * uglynum[index5]));

            while(2 * uglynum[index2] == uglynum[i])   //�ҵ�����������ʹ�ø�λ�õ�ֵ���Զ�Ӧ��ֵ������Сֵ������,��������������ƶ�һλ
                ++ index2;

            while(3 * uglynum[index3] == uglynum[i])
                ++ index3;

            while(5 * uglynum[index5] == uglynum[i])
                ++ index5;
            ++i;
        }
        return uglynum[index - 1];
    }
};
