/*
  ��Ŀ��������������ǰ�к��������
*/


struct BiTree
{
	struct BiTree *leftChild;
	struct BiTree *rightChild;
	char data;
};

void createBiTree(BiTree* &T)   //����������
{
	char c;
	cin >> c;
	if('#' == c)
		T = NULL;
	else
	{
		T = new BiTree;
		T->data = c;
		createBiTree(T->leftChild);
		createBiTree(T->rightChild);
	}
}

void PreOrder(BiTree *T)//����ݹ����
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void SqlPreOrder(BiTree T)//����ǵݹ����
{
    stack<BiTree*> s;
    BiTree *p = T;
    while(p || !s.empty())
    {
        if(p)
        {
            cout << p->data << " ";
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.top();
            p=p->rchild;
            s.pop();
        }
    }
}



void InOrder(BiTree *T)//����ݹ����
{
    if(T!=NULL)
    {
        InOrder(T->lchild);
        cout<<T->data<<" ";
        InOrder(T->rchild);
    }
}
void SqInOrder(BiTree *T)//����ǵݹ����
{
    stack<BiTree*> s;
    BiTree * p = T;
    while(p || !s.empty())
        if(p)
        {
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.top();
            cout<<p->data<<" ";
            s.pop();
            p=p->rchild;
        }
}



void PostOrder(BiTree *T)//����ݹ����
{
    if(T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout<<T->data<<" ";
    }
}

//����ǵݹ����1˼·����Ϊ����ǵݹ������������˳�����ȷ������������ٷ��ʺ����������
//���ʸ���㡣���ö�ջ���洢��㣬������巵�ظ����ʱ���Ǵ����������صģ����Ǵ�������
//���صġ����ԣ�ʹ�ø���ָ��r����ָ��������ʹ��Ľ�㡣
void SqlPostOrder1(BiTree T)//����ǵݹ����1
{
    stack<BiTree> s;
    BiTree p=T,r;
    while(p || !s.empty())
    {
        if(p)                             //�ߵ������
        {
            s.push(p);
            p=p->lchild;
        }
        else                             //����
        {
            p=s.top();//ȡջ�����
            if(p->rchild && p->rchild!=r)//������������ڣ���δ�����ʹ�
            {
                p=p->rchild;
                s.push(p);
                p=p->lchild;             //���ߵ�����
            }
            else                         //���򣬷���ջ����㲢����
            {
                cout<<p->data<<" ";
                r=p;                     //��¼�ý��
                s.pop();
                p=NULL;                     //�������������pָ��
            }
        }
    }
}
//˼·2���ڽ�������ӱ�־�򣬼�¼�Ƿ��ѱ����ʡ�
void SqlPostOrder2(BiTree T)//����ǵݹ����2
{
    stack<BiTree> s;
    BiTree p=T;
    while(p || !s.empty())
    {
        if(p && p->lvisited==0)                     //���ߣ���������δ������
        {
            p->lvisited=1;
            s.push(p);
            p=p->lchild;
        }
        else
        {
            p=s.top();
            if(p->rchild!=NULL && p->rvisited==0)//������δ�����ʣ�����һ��
            {
                p->rvisited=1;
                p=p->rchild;
            }
            else                                 //����ջ��Ԫ�ز���ջ
            {
                cout<<p->data<<" ";
                s.pop();
                if(!s.empty())
                    p=s.top();
                else                             //�����һ��Ԫ�ص�ջ��ȥ�󣬽���
                    return ;
            }
        }
    }
}
