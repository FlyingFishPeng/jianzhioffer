/*��Ŀ: ��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
        Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}��
        ��ô��Ӧ��������ظ�������2����3��*/

/*˼·1���������飬�����Ƕ����ԷŻ������Լ���λ�á��жϵ�i��λ�õ�Ԫ��tmp�Ƿ��i��ȣ���������������һ��Ԫ�أ�
		�����ж�tmp��num[tmp]�Ƿ���ȣ������˵�����Ӧ��λ���Ѿ����ڸ����֣��ظ���return���������򽻻�����Ԫ�ء�
		ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1����
*/
    bool duplicate(int numbers[], int length, int* duplication) {
        bool res = false;
        * duplication = -1;
        if(length < 2)
            return res;
        int tmp;
        for(int i = 0; i < length; i++)
        {
            if(numbers[i] > length - 1)  //����Ԫ����Ч���ж�
                break;
            tmp = numbers[i];
        	if(i == tmp)  //�±�ֵ�Ͷ�Ӧ��ֵ��ȣ��������һ����
                continue;
            if(numbers[tmp] == tmp)  //�����ǰֵm��num[m]��ȣ�˵������Ϊ�ظ�����
            {
                *duplication = tmp;
                res = true;
                break;
            }
            else   //���򽻻�
            {
                swap(numbers[i], numbers[tmp]);
            }
        }
        return res;
    }

};

/*˼·2��˼·2�����ù�ϣ����˼·Ҳ�������Ϊ�������򣩡�����һ������Ϊlength�Ĺ�ϣ��ÿ��Ԫ��ֵΪ0��
        ����������Ԫ���ڶ�Ӧλ���ϳ��ֵĴ������������飬���ڵ�i���������hash(nuimbers[i])Ϊ0����
        ��λ��1������˵������Ϊ�ظ�����ֱ��return��ʱ��Ϳռ临�ӶȾ�ΪO��n����
*/

bool duplicate(int numbers[], int length, int* duplication) {
         bool res = false;
         if(length < 2)
             return res;
         vector<int> hash(length, 0); //����Ϊlength����ÿ��Ԫ��ֵΪ0
         int tmp = 0;
         for(int i = 0; i < length; i++)
         {
            tmp = numbers[i];
         	if(hash[tmp] == 0)
                hash[tmp]++;
             else
             {
                *duplication = tmp;
             	res = true;
             	break;
             }
         }
         return res;
     }
