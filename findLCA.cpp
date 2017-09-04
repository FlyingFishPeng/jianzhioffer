/*
   ��Ŀ�����������������͹�������
*/

/*
   ˼·1�����ҵ���������·����ת��Ϊ����������Ľ��㡣
*/

struct Node
{
    int key;
    struct Node *left, *right;
};

//�ҵ���root�� �ڵ�ֵΪkey��·��,�洢��path�С�û�еĻ�����-1
bool findpath(Node * root, vector<int> &path, Node* pNode)
{
	if(root == NULL)
        return false;
	path.push_back(root->key);
	if(root->key == pNode->key)
        return true;
	//�������������� �Ƿ��ҵ�,�ҵ��Ļ���ǰ�ڵ����·������
	bool find = ( findpath(root->left, path, pNode) || findpath(root->right, path, pNode->key) );
	if(find)
        return true;
	//�ýڵ���δ�ҵ��͵���
	path.pop_back();
	return false;
}

int findLCA(Node * root, Node* pNode1, Node* pNode2){
	vector<int> path1, path2;
	bool find1 = findpath(root, path1, pNode1);
	bool find2 = findpath(root, path2, pNode2);
	if(find1 && find2)
	{
		int ans ;
		for(int i=0; i<path1.size(); i++)
		{                                                                                                      a b c d
			if(path1[i] != path2[i])   //��������ĵ�һ���ֲ�㼴����e.g. ���d��f����͹�������Ϊ3�� 1 2 3
			{                                                                                                  e f
				break;
			}
			else
				ans = path1[i];
		}
		return ans;
	}
	return -1;
}

/*
    ˼·2���ݹ顣��root��ʼ���������n1��n2�е���һ����rootƥ�䣬��ôroot����LCA��
           �������ƥ�䣬��ֱ�ݹ����������������һ�� key��n1��n2����������������
           ������һ��key(n1��n2)����������������root����LCA.  �������key����������������
           ��˵��LCA���������У���������������
*/
struct Node
{
    struct Node *left, *right;
    int key;
};

struct Node *findLCA(struct Node* root, Node* pNode1, Node* pNode2)
{
    if (root == NULL)
        return NULL;

    // ֻҪn1 �� n2 ����һ��ƥ�伴��
    //  (ע�⣺��� һ���ڵ�����һ�����ȣ��򷵻ص������Ƚڵ㡣��Ϊ�ݹ���Ҫ���ص����ȵ� )
    if (root->key == pNode1->key || root->key == pNode2->key)
        return root;
    // �ֱ���������������
    Node *left_lca  = findLCA(root->left, pNode1, pNode2);
    Node *right_lca = findLCA(root->right, pNode1, pNode2);
    // ��������طǿ�ָ�� Non-NULL, ��˵�������ڵ�ֱ�����������������У���ǰ�ڵ�϶�ΪLCA
    if (left_lca && right_lca)
        return root;
    // ���һ��Ϊ�գ���˵��LCA����һ������
    return (left_lca != NULL)? left_lca: right_lca;
}
