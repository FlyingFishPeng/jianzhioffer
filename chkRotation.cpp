/*
    ��Ŀ���ַ�������ת�ʡ�����A="12345",A����ת����"12345","23451","34512","45123"��"51234"��
          ���������ַ���A��B�����ж�A��B�Ƿ�Ϊ��ת�ʡ�
*/

/*
    ˼·����A�������ٴ�һ����A�õ�C=A+A��Ȼ����A�в����Ƿ����B���������ң�����find����������KMP�㷨��
*/

//�������ҷ�
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


//STL find����
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
