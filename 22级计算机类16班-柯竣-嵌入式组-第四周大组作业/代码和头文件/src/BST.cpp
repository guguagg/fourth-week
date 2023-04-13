#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>

#include "BST.h"


//初始化根节点
Status BST_init(BinarySortTreePtr r)
{
	NodePtr p;
	int v;
	p = (NodePtr)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("内存分配失败！\n");
		system("pause");
		return failed;
	}

	r->root = p;

	p->left = NULL;
	p->right = NULL;

	printf("请输入根节点的内容：\n");
	scanf("%d", &v);
	p->value = v;

	return succeed;

}



//插入新节点
Status BST_insert(BinarySortTreePtr r, ElemType v)
{
	if (r->root == NULL)
	{
		printf("根节点不存在！\n");
		system("pause");
		return failed;
	}

	NodePtr temp = r->root;
	
	//初始化节点内容
	NodePtr p;
	p = (NodePtr)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("内存分配失败！\n");
		system("pause");
		return failed;
	}
	p->left = NULL;
	p->right = NULL;
	p->value = v;


	while (temp != NULL)
	{
		if (v > temp->value)
		{
			if (temp->right == NULL)
			{
				temp->right = p;
				return succeed;
			}
			else
			{
				temp = temp->right;
				continue;
			}
		}
		else if (v <= temp->value)
		{
			if (temp->left == NULL)
			{
				temp->left = p;
				return succeed;
			}
			else
			{
				temp = temp->left;
				continue;
			}
		}
	}
	return failed;
}


//查找节点，并返回节点
NodePtr search(NodePtr n, ElemType v)
{
	if (n == NULL)
		return NULL;
	if (n->value > v)
		return search(n->left, v);
	else if (n->value < v)
		return search(n->right, v);
	else
		return n;
}


//查找节点
Status BST_search(BinarySortTreePtr r, ElemType v)
{
	if (r->root == NULL)
	{
		printf("根节点不存在！\n");
		system("pause");
		return failed;
	}

	NodePtr temp = r->root;
	NodePtr p = search(temp, v);
	if (p == NULL || p->value != v)
	{
		printf("目标节点不存在！\n");
		return failed;
	}

	Tprint(p);
	return succeed;
}


//获取最大值节点
NodePtr MaxNode(NodePtr n)
{
	if (n == NULL)
		return NULL;
	NodePtr temp = n;
	while (temp->right)
		temp = temp->right;
	return temp;
}

//查找某节点的父节点
NodePtr ParentNode(NodePtr n,BinarySortTreePtr r)
{
	if (n == NULL || r->root == NULL)
		return NULL;
	NodePtr temp = r->root;
	NodePtr par = temp;
	while (temp != NULL && temp->value != n->value)
	{
		par = temp;
		if (n->value > temp->value)
			temp = temp->right;
		else
			temp = temp->left;
	}
	if (temp == NULL)
	{
		return NULL;
	}

	return par;

}


//删除节点
Status BST_delete(BinarySortTreePtr r, ElemType v)
{
	if (r->root == NULL)
	{
		printf("根节点不存在！\n");
		system("pause");
		return failed;
	}

	NodePtr temp = r->root;                  //存放根节点
	NodePtr p = search(temp, v);             //删除节点
	NodePtr par = ParentNode(p, r);          //删除节点的父节点

	if (p == NULL)
	{
		printf("目标节点不存在！\n");
		return failed;
	}

	if (p != temp && par == NULL)
	{
		printf("查找错误！\n");
		return failed;
	}
	if (p->left == NULL && p->right == NULL)   //1、若删除节点为叶节点
	{
		if (temp == p) //若为根节点
		{
			r->root = NULL;
			return succeed;
		}
		if (par->left != NULL && par->left->value == v)
			par->left = NULL;
		else if (par->right->value == v )
			par->right = NULL;
	}
	else if (p->left == NULL || p->right == NULL)  //2、若删除节点只有左子树或右子树
	{
		if (temp == p)  //若为根节点
		{
			if (temp->left != NULL)
				r->root = temp->left;
			else if (temp->right != NULL)
				r->root = temp->right;
		}
		else if (p->left != NULL)//删除节点只有左子树
		{
			if (par->left == p)
				par->left = p->left;
			if (par->right == p)
				par->right = p->left;
		}
		else if (p->right != NULL)//删除节点只有右子树
		{
			if (par->left == p)
				par->left = p->right;
			if (par->right == p)
				par->right = p->right;
		}
	}
	else if (p->left != NULL || p->right != NULL)//3、若删除节点具有左子树和右子树   存在BUG
	{
		NodePtr replaceNode = MaxNode(p);//找到替代节点
		NodePtr parreplaceNode = ParentNode(replaceNode,r);//找到替代节点的父节点
		if (temp == p)
		{
			parreplaceNode->right = replaceNode->left;
			replaceNode->left = temp->left;
			replaceNode->right = temp->right;
			r->root = replaceNode;
		}
		else if (par->left == p)
		{
			par->left = replaceNode;
			replaceNode->left = p->left;
			if (parreplaceNode != p)
			{
				replaceNode->right = p->right;
				parreplaceNode->right = replaceNode->left;
			}
			else if (parreplaceNode == p)
				replaceNode->right = p->right->left;
		}
		else if (par->right = p)
		{
			par->right = replaceNode;
			replaceNode->right = p->right;
			if (parreplaceNode != p)
			{
				replaceNode->left = p->left;
				parreplaceNode->right = replaceNode->left;
			}
			else if (parreplaceNode == p)
			{
				replaceNode->left = replaceNode->left->left;
			}
		}



	}

	free(p);

	return succeed;
}


//输出节点内容
void Tprint(NodePtr n)
{
	printf("%d->", n->value);
}


//预序遍历  递归
void preorder(NodePtr n, void (*visit)(NodePtr))
{
	if (n)
	{
		visit(n);
		preorder(n->left, Tprint);
		preorder(n->right, Tprint);
	}
}

//预序遍历  递归
Status BST_preorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (r->root == NULL)
	{
		printf("根节点不存在！\n");
		system("pause");
		return failed;
	}

	NodePtr n;
	n = r->root;
	
	preorder(n, Tprint);
	return succeed;
}

//中序遍历   递归
void inorder(NodePtr n, void(*visit)(NodePtr))
{
	if (n)
	{
		inorder(n->left,Tprint);
		visit(n);
		inorder(n->right, Tprint);
	}
}


//中序遍历   递归
Status BST_inorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (r->root == NULL)
	{
		printf("根节点不存在！\n");
		system("pause");
		return failed;
	}

	NodePtr n;
	n = r->root;

	inorder(n, Tprint);
	return succeed;

}

//后序遍历  递归
void postorder(NodePtr n, void(*visit)(NodePtr))
{
	if (n)
	{
		postorder(n->left, Tprint);
		postorder(n->right, Tprint);
		visit(n);
	}
}


//后序遍历  递归
Status BST_postorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (r->root == NULL)
	{
		printf("根节点不存在！\n");
		system("pause");
		return failed;
	}

	NodePtr n;
	n = r->root;

	postorder(n, Tprint);
	return succeed;

}
