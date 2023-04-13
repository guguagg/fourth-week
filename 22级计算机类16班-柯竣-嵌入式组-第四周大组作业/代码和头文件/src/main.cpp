#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include"BST.h"



int main()
{
	int v, choice;
	BinarySortTree r;
	r.root = NULL;

	while (1)
	{
		system("cls");
		printf("1、初始化根节点；\n2、插入新节点；\n3、删除节点；\n4、查找节点；\n5、预序遍历；\n6、中序遍历；\n7、后序遍历\n0、退出\n");
		scanf("%d", &choice);
		while(getchar()!='\n');
		switch (choice)
		{
		case 1://初始化根节点
			if (BST_init(&r))
				printf("初始化成功！\n");
			else
				printf("初始化失败！\n");
			system("pause");
			break;

		case 2://插入新节点
			if (r.root == NULL)
			{
				printf("根节点不存在！\n");
				system("pause");
				break;
			}

			printf("请输入节点内容：\n");
			scanf("%d", &v);
			if (BST_insert(&r, v))
				printf("插入新节点成功！\n");
			else
				printf("插入新节点失败！\n");
			system("pause");
			break;

		case 3://删除节点
			if (r.root == NULL)
			{
				printf("根节点不存在！\n");
				system("pause");
				break;
			}

			printf("请输入想要删除的节点内容：\n");
			scanf("%d", &v);
			BST_delete(&r, v);
			system("pause");
			break;

		case 4://查找节点
			if (r.root == NULL)
			{
				printf("根节点不存在！\n");
				system("pause");
				break;
			}

			printf("请输入想要查找的节点内容：\n");
			scanf("%d", &v);
			if (BST_search(&r, v))
			{
				printf("节点存在！\n");
			}
			system("pause");
			break;

		case 5://预序遍历
			if (r.root == NULL)
			{
				printf("根节点不存在！\n");
				system("pause");
				break;
			}

			BST_preorderR(&r, Tprint);
			system("pause");
			break;

		case 6://中序遍历
			if (r.root == NULL)
			{
				printf("根节点不存在！\n");
				system("pause");
				break;
			}

			BST_inorderR(&r, Tprint);
			system("pause");
			break;

		case 7://后序遍历
			if (r.root == NULL)
			{
				printf("根节点不存在！\n");
				system("pause");
				break;
			}

			BST_postorderR(&r, Tprint);
			system("pause");
			break;

		case 0://退出
			printf("即将退出系统！\n");
			system("pause");
			return 0;

		default:
			printf("输入错误！\n请重新输入！\n");
			system("pause");
			break;
		}

	}

	return 0;
}
