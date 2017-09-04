/*
   题目：二叉树两个结点最低公共祖先
*/

/*
   思路1：先找到两个结点的路径，转换为求两个链表的交点。
*/

struct Node
{
    int key;
    struct Node *left, *right;
};

//找到从root到 节点值为key的路径,存储在path中。没有的话返回-1
bool findpath(Node * root, vector<int> &path, Node* pNode)
{
	if(root == NULL)
        return false;
	path.push_back(root->key);
	if(root->key == pNode->key)
        return true;
	//左子树或右子树 是否找到,找到的话当前节点就在路径中了
	bool find = ( findpath(root->left, path, pNode) || findpath(root->right, path, pNode->key) );
	if(find)
        return true;
	//该节点下未找到就弹出
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
			if(path1[i] != path2[i])   //两个数组的第一个分叉点即所求，e.g. 结点d和f的最低公共祖先为3： 1 2 3
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
    思路2：递归。从root开始遍历，如果n1和n2中的任一个和root匹配，那么root就是LCA。
           如果都不匹配，则分别递归左、右子树，如果有一个 key（n1或n2）出现在左子树，
           并且另一个key(n1或n2)出现在右子树，则root就是LCA.  如果两个key都出现在左子树，
           则说明LCA在左子树中，否则在右子树。
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

    // 只要n1 或 n2 的任一个匹配即可
    //  (注意：如果 一个节点是另一个祖先，则返回的是祖先节点。因为递归是要返回到祖先的 )
    if (root->key == pNode1->key || root->key == pNode2->key)
        return root;
    // 分别在左右子树查找
    Node *left_lca  = findLCA(root->left, pNode1, pNode2);
    Node *right_lca = findLCA(root->right, pNode1, pNode2);
    // 如果都返回非空指针 Non-NULL, 则说明两个节点分别出现了在两个子树中，则当前节点肯定为LCA
    if (left_lca && right_lca)
        return root;
    // 如果一个为空，在说明LCA在另一个子树
    return (left_lca != NULL)? left_lca: right_lca;
}
