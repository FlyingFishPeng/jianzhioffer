/*
  题目：二叉树深度优先遍历。
*/

/*
  思路：借助栈实现。
*/

void DepthFirstTravel(Tree *root)
{
	stack<Tree *> s;
	s.push(root);
	while(!s.empty())
	{
		root = s.top();
		cout << root->data << " ";
		s.pop();
		if(root->rchild != NULL)  //先压入右节点
		{
			s.push(root->rchild);
		}
		if(root->lchild != NULL)
		{
			s.push(root->lchild);
		}

	}
}
