#include <stdio.h>
#include <stdlib.h>
typedef int BTDataType;
typedef struct BTreeNode
{
	BTDataType data;
	struct BTreeNode* left;
	struct BTreeNode* right;
}BTNode;
BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc");
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
BTNode* CreatBTree()
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(3);
	BTNode* n4 = BuyNode(4);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);
	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n4->left = n5;
	n4->right = n6;
	return n1;
}
void Preorder(BTNode *node)//ǰ�����
{
	if (node == NULL)
	{
		printf("NULL ");
		return;
	}
	
	printf("%d ", node->data);
	Preorder(node->left);
	Preorder(node->right);
}
void Inorder(BTNode* node)//�������
{
	if (node == NULL)
	{
		printf("NULL ");
		return;
	}
	Inorder(node->left);
	printf("%d ", node->data);
	Inorder(node->right);
}
void Postorder(BTNode* node)//�������
{
	if (node == NULL)
	{
		printf("NULL ");
		return;
	}
	Postorder(node->left);
	Postorder(node->right);
	printf("%d ", node->data);
}
int TreeSize(BTNode* node)//�������������
{
	if (node == 0)
		return 0;
	else
		return TreeSize(node->left) + TreeSize(node->right) + 1;
}
int TreeHeight(BTNode* node)//��������ȣ��߶�
{
	if (node == NULL)
		return 0;
	else
	{
		int leftHeigh = TreeHeight(node->left);
		int rightHeight = TreeHeight(node->right);
		return leftHeigh > rightHeight ? leftHeigh + 1 : rightHeight + 1;
	}
}
int LevelK(BTNode* node, int k)//���K�� ������
{
	if (node == NULL)
		return 0;
	if (k == 1)
		return 1;
	int leftlevel = LevelK(node->left,k-1);
	int rightlevl = LevelK(node->right, k - 1);
	return leftlevel + rightlevl;
}

int main()
{
	BTNode* node = CreatBTree();
	Preorder(node);//ǰ�����
	printf("\n");
	Inorder(node);//�������
	printf("\n");
	Postorder(node); // �������
	printf("\n");
	printf("Size:%d\n", TreeSize(node));

	printf("Height:%d",TreeHeight(node) );
	return 0;
}
