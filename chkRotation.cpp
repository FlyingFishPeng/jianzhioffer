/*
    题目：字符串的旋转词。比如A="12345",A的旋转词有"12345","23451","34512","45123"和"51234"。
          对于两个字符串A和B，请判断A和B是否互为旋转词。
*/

/*
    思路：将A串后面再串一个串A得到C=A+A，然后在A中查找是否存在B。暴力查找，或者find函数，或者KMP算法。
*/

//暴力查找法
class Rotation {
public:
    bool chkRotation(string A, int lena, string B, int lenb) {
        // write code here
        A = A.append(A);
        int i = 0, j = 0;
        while (i < A.length() - B.length()+1){
            if (A[i+j] == B[j]){
                j++;
                if (j == B.length() - 1)
                    return true;
            }
            else{
                i++;
                j = 0;
            }
        }
        return false;
    }
};


//STL find函数
class Rotation {
public:
    bool chkRotation(string A, int lena, string B, int lenb) {
        // write code here
        if(lena!=lenb)
            return false;
        string str1=A+A;
        if(str1.find(B)!=-1)
            {return true;}
        else{
            return false;
        }
    }
};
