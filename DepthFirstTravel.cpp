/*
  ��Ŀ��������������ȱ�����
*/

/*
  ˼·������ջʵ�֡�
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
		if(root->rchild != NULL)  //��ѹ���ҽڵ�
		{
			s.push(root->rchild);
		}
		if(root->lchild != NULL)
		{
			s.push(root->lchild);
		}

	}
}
