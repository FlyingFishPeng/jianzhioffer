/*
  ��Ŀ����������K��������
*/

/*
   ˼·�����K����ĸ���Ҳ�����õݹ���ʵ�֣�

        ����������Ϊ�ջ���KС��0������0

        ����K����0����0�������������ֻ��һ��������1

        ����K����0�������������е�K-1������� ���� �������е�K-1����ĸ���

        ��Ϊ����K���㣬����ڸ��������� �� ������ ���ԣ����ǵ�K-1����

�ݹ�Ļ�׼����ֻ��������

    1) k==0 ���ݹ鵽K==0ʱ��˵������K�����н���

    ) root==null  ���ݹ鵽root==nullʱ��˵������K��û�н��
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/

// �������е�K����ĸ���(��λ�ڵ�0��)

int getNodeNum(TreeNode * T, int k){
    if (!T || k < 1){
        return 0;
    }
    if (k == 1){
        return 1;
    }
    return getNodeNum(T->left, k-1) + getNodeNum(T->right, k-1);
}
