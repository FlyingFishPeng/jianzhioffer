/*题目: 在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
        也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
        那么对应的输出是重复的数字2或者3。*/

/*思路1：遍历数组，将它们都各自放回属于自己的位置。判断第i个位置的元素tmp是否和i相等，相等则继续遍历下一个元素；
		否则，判断tmp和num[tmp]是否相等，相等则说明其对应的位置已经存在该数字，重复，return该数；否则交换两个元素。
		时间复杂度O（n），空间复杂度O（1）。
*/
    bool duplicate(int numbers[], int length, int* duplication) {
        bool res = false;
        * duplication = -1;
        if(length < 2)
            return res;
        int tmp;
        for(int i = 0; i < length; i++)
        {
            if(numbers[i] > length - 1)  //数组元素有效性判断
                break;
            tmp = numbers[i];
        	if(i == tmp)  //下标值和对应的值相等，则遍历下一个数
                continue;
            if(numbers[tmp] == tmp)  //如果当前值m和num[m]相等，说明此数为重复的数
            {
                *duplication = tmp;
                res = true;
                break;
            }
            else   //否则交换
            {
                swap(numbers[i], numbers[tmp]);
            }
        }
        return res;
    }

};

/*思路2：思路2：利用哈希表（此思路也可以理解为计数排序）。建立一个长度为length的哈希，每个元素值为0，
        代表数组中元素在对应位置上出现的次数。遍历数组，对于第i个数，如果hash(nuimbers[i])为0，则将
        该位加1，否则说明该数为重复数，直接return。时间和空间复杂度均为O（n）。
*/

bool duplicate(int numbers[], int length, int* duplication) {
         bool res = false;
         if(length < 2)
             return res;
         vector<int> hash(length, 0); //长度为length，且每个元素值为0
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
