/*
题目：二叉树的下一个结点。给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下
一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
/*思路：（1） 若该节点存在右子树：则下一个节点为右子树最左子节点
	   （2） 若该节点不存在右子树：这时分两种情况：
         2.1 该节点为父节点的左子节点，则下一个节点为其父节点
         2.2 该节点为父节点的右子节点，则沿着父节点向上遍历，知道找到一个节点的父节点的左子节点为该节点，则该节点的父节点下一个节点
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)
            return nullptr;
        TreeLinkNode *tmp = nullptr, *nextnode = nullptr, *fathernode = pNode->next;
        if(pNode->right != nullptr)  //存在右子树，则下一个结点是右子树的中序遍历的第一个结点
        {
            tmp = pNode->right;
            while(tmp->left)
            {
            	tmp = tmp->left;
            }
            nextnode = tmp;
        }
        else if(fathernode != nullptr && fathernode->left == pNode) //是其父结点的左子节点，则下一个结点即其父结点
        {
            nextnode = fathernode;
        }
        else if(fathernode != nullptr && fathernode->right == pNode)  //是其父结点的右子节点，则下一个结点即其将其父结点作为左结点的结点
        {
            tmp = fathernode->next;
            while(pNode->next != nullptr && pNode->next->left != pNode)
            {
                pNode = pNode->next;
            }
            nextnode = pNode->next;
        }
        return nextnode;
    }
};











