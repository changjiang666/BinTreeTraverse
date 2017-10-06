#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;
typedef struct BinTNode
{
	TElemType data;
	struct BinTNode *lchild, *rchild;
}BinTNode, *BinTree;

void CreateBinTree(BinTree *T)
{
	TElemType ch;
	scanf_s("%c", &ch);
	if ('#' == ch)
		*T = NULL;
	else
	{
		*T = (BinTree)malloc(sizeof(BinTNode));
		if (!*T)
			exit(0);
		(*T)->data = ch;
		CreateBinTree(&((*T)->lchild));
		CreateBinTree(&((*T)->rchild));
	}
}

void visit(BinTree T, int level)
{
	printf("%c is %d level\n", T->data, level);
}

void PreOrderTraverse(BinTree T, int level)
{
	if (!T)
		return;
	visit(T, level);
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
}

void InOrderTraverse(BinTree T, int level)
{
	if (!T)
		return;
	InOrderTraverse(T->lchild, level + 1 );
	visit(T, level);
	InOrderTraverse(T->rchild, level + 1);
}

void PostOrderTraverse(BinTree T, int level)
{
	if (!T)
		return;
	PostOrderTraverse(T->lchild, level + 1);
	PostOrderTraverse(T->rchild, level + 1);
	visit(T, level);
}


main(void)
{
	int level = 1;
	printf("please input the nodes:\n");
	BinTree T = NULL;
	CreateBinTree(&T);
	PreOrderTraverse(T, level);
	printf("\n\n\n");
	InOrderTraverse(T, level);
	printf("\n\n\n");
	PostOrderTraverse(T, level);
	system("pause");
	return 0;
}