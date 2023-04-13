#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>

#include "BST.h"


//��ʼ�����ڵ�
Status BST_init(BinarySortTreePtr r)
{
	NodePtr p;
	int v;
	p = (NodePtr)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		system("pause");
		return failed;
	}

	r->root = p;

	p->left = NULL;
	p->right = NULL;

	printf("��������ڵ�����ݣ�\n");
	scanf("%d", &v);
	p->value = v;

	return succeed;

}



//�����½ڵ�
Status BST_insert(BinarySortTreePtr r, ElemType v)
{
	if (r->root == NULL)
	{
		printf("���ڵ㲻���ڣ�\n");
		system("pause");
		return failed;
	}

	NodePtr temp = r->root;
	
	//��ʼ���ڵ�����
	NodePtr p;
	p = (NodePtr)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
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


//���ҽڵ㣬�����ؽڵ�
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


//���ҽڵ�
Status BST_search(BinarySortTreePtr r, ElemType v)
{
	if (r->root == NULL)
	{
		printf("���ڵ㲻���ڣ�\n");
		system("pause");
		return failed;
	}

	NodePtr temp = r->root;
	NodePtr p = search(temp, v);
	if (p == NULL || p->value != v)
	{
		printf("Ŀ��ڵ㲻���ڣ�\n");
		return failed;
	}

	Tprint(p);
	return succeed;
}


//��ȡ���ֵ�ڵ�
NodePtr MaxNode(NodePtr n)
{
	if (n == NULL)
		return NULL;
	NodePtr temp = n;
	while (temp->right)
		temp = temp->right;
	return temp;
}

//����ĳ�ڵ�ĸ��ڵ�
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


//ɾ���ڵ�
Status BST_delete(BinarySortTreePtr r, ElemType v)
{
	if (r->root == NULL)
	{
		printf("���ڵ㲻���ڣ�\n");
		system("pause");
		return failed;
	}

	NodePtr temp = r->root;                  //��Ÿ��ڵ�
	NodePtr p = search(temp, v);             //ɾ���ڵ�
	NodePtr par = ParentNode(p, r);          //ɾ���ڵ�ĸ��ڵ�

	if (p == NULL)
	{
		printf("Ŀ��ڵ㲻���ڣ�\n");
		return failed;
	}

	if (p != temp && par == NULL)
	{
		printf("���Ҵ���\n");
		return failed;
	}
	if (p->left == NULL && p->right == NULL)   //1����ɾ���ڵ�ΪҶ�ڵ�
	{
		if (temp == p) //��Ϊ���ڵ�
		{
			r->root = NULL;
			return succeed;
		}
		if (par->left != NULL && par->left->value == v)
			par->left = NULL;
		else if (par->right->value == v )
			par->right = NULL;
	}
	else if (p->left == NULL || p->right == NULL)  //2����ɾ���ڵ�ֻ����������������
	{
		if (temp == p)  //��Ϊ���ڵ�
		{
			if (temp->left != NULL)
				r->root = temp->left;
			else if (temp->right != NULL)
				r->root = temp->right;
		}
		else if (p->left != NULL)//ɾ���ڵ�ֻ��������
		{
			if (par->left == p)
				par->left = p->left;
			if (par->right == p)
				par->right = p->left;
		}
		else if (p->right != NULL)//ɾ���ڵ�ֻ��������
		{
			if (par->left == p)
				par->left = p->right;
			if (par->right == p)
				par->right = p->right;
		}
	}
	else if (p->left != NULL || p->right != NULL)//3����ɾ���ڵ������������������   ����BUG
	{
		NodePtr replaceNode = MaxNode(p);//�ҵ�����ڵ�
		NodePtr parreplaceNode = ParentNode(replaceNode,r);//�ҵ�����ڵ�ĸ��ڵ�
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


//����ڵ�����
void Tprint(NodePtr n)
{
	printf("%d->", n->value);
}


//Ԥ�����  �ݹ�
void preorder(NodePtr n, void (*visit)(NodePtr))
{
	if (n)
	{
		visit(n);
		preorder(n->left, Tprint);
		preorder(n->right, Tprint);
	}
}

//Ԥ�����  �ݹ�
Status BST_preorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (r->root == NULL)
	{
		printf("���ڵ㲻���ڣ�\n");
		system("pause");
		return failed;
	}

	NodePtr n;
	n = r->root;
	
	preorder(n, Tprint);
	return succeed;
}

//�������   �ݹ�
void inorder(NodePtr n, void(*visit)(NodePtr))
{
	if (n)
	{
		inorder(n->left,Tprint);
		visit(n);
		inorder(n->right, Tprint);
	}
}


//�������   �ݹ�
Status BST_inorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (r->root == NULL)
	{
		printf("���ڵ㲻���ڣ�\n");
		system("pause");
		return failed;
	}

	NodePtr n;
	n = r->root;

	inorder(n, Tprint);
	return succeed;

}

//�������  �ݹ�
void postorder(NodePtr n, void(*visit)(NodePtr))
{
	if (n)
	{
		postorder(n->left, Tprint);
		postorder(n->right, Tprint);
		visit(n);
	}
}


//�������  �ݹ�
Status BST_postorderR(BinarySortTreePtr r, void (*visit)(NodePtr))
{
	if (r->root == NULL)
	{
		printf("���ڵ㲻���ڣ�\n");
		system("pause");
		return failed;
	}

	NodePtr n;
	n = r->root;

	postorder(n, Tprint);
	return succeed;

}
