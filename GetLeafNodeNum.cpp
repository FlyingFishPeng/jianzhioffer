/*
    ��Ŀ��������Ҷ�ӽڵ������
*/

/*
   ˼·����1�����������Ϊ�գ�����0
         ��2�������������Ϊ������������Ϊ�գ�����1
         ��3�������������Ϊ�գ�������������ͬʱΪ�գ�������������Ҷ�ӽڵ����������������Ҷ�ӽڵ����
*/

int GetLeafNodeNum(BTree* root)
{
	if(root == NULL)
		return 0;
	if(root->m_pLeft == NULL && root->m_pRight == NULL)
		return 1;

	int LeafNumOfLeft = GetLeafNodeNum(root->m_pLeft);
	int LeafNumOfRight = GetLeafNodeNum(root->m_pRight);

	int ret = LeafNumOfLeft + LeafNumOfRight;

	return ret;

}
