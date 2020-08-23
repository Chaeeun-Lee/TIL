#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;
BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;

	return nd;
}
BTData GetData(BTreeNode * bt)
{
	return bt->data;
}
void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}
BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;

}
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}
void InorderTraverse(BTreeNode * bt)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left);
	printf("%d ", bt->data);
	InorderTraverse(bt->right);
}
void PostorderTraverse(BTreeNode * bt)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d ", bt->data);
}
void PreorderTraverse(BTreeNode * bt)
{
	if (bt == NULL)
		return;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

int main()
{
	BTreeNode * A = MakeBTreeNode();
	BTreeNode * B = MakeBTreeNode();
	BTreeNode * C = MakeBTreeNode();
	BTreeNode * D = MakeBTreeNode();
	BTreeNode * E = MakeBTreeNode();
	BTreeNode * F = MakeBTreeNode();
	BTreeNode * G = MakeBTreeNode();
	BTreeNode * H = MakeBTreeNode();

	SetData(A, 1);
	SetData(B, 2);
	SetData(C, 3);
	SetData(D, 4);
	SetData(E, 5);
	SetData(F, 6);
	SetData(G, 7);
	SetData(H, 8);

	MakeLeftSubTree(A, B);
	MakeRightSubTree(A, C);
	MakeLeftSubTree(B, D);
	MakeRightSubTree(B, E);
	MakeLeftSubTree(C, F);
	MakeRightSubTree(C, G);
	MakeLeftSubTree(D, H);

	// ��ȭ����Ʈ�� ����ȭ�ؼ� ���
	printf("%6d\n", GetData(A));
	printf("%4d", GetData(B));
	printf("%5d\n", GetData(C));
	printf("%2d ", GetData(D));
	printf("%2d ", GetData(E));
	printf("%2d ", GetData(F));
	printf("%2d \n", GetData(G));
	printf("%d\n", GetData(H));

	// ���� ��ȸ�� ������ ���
	printf("\n���� ��ȸ�� ������ ���\n");
	InorderTraverse(A);
	printf("\n");

	// ���� ��ȸ�� ������ ���
	printf("\n���� ��ȸ�� ������ ���\n");
	PostorderTraverse(A);
	printf("\n");

	// ���� ��ȸ�� ������ ���
	printf("\n���� ��ȸ�� ������ ���\n");
	PreorderTraverse(A);
	printf("\n");

	//// ��Ʈ ������ ������ �����ʿ� �ִ� ���鸸 ���
	//printf("\n%d\n", GetData(A));
	//printf("%d\n", GetData(GetRightSubTree(A)));
	//printf("%d\n", GetData(GetRightSubTree(GetRightSubTree(A))));
}