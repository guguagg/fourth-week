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
		printf("1����ʼ�����ڵ㣻\n2�������½ڵ㣻\n3��ɾ���ڵ㣻\n4�����ҽڵ㣻\n5��Ԥ�������\n6�����������\n7���������\n0���˳�\n");
		scanf("%d", &choice);
		while(getchar()!='\n');
		switch (choice)
		{
		case 1://��ʼ�����ڵ�
			if (BST_init(&r))
				printf("��ʼ���ɹ���\n");
			else
				printf("��ʼ��ʧ�ܣ�\n");
			system("pause");
			break;

		case 2://�����½ڵ�
			if (r.root == NULL)
			{
				printf("���ڵ㲻���ڣ�\n");
				system("pause");
				break;
			}

			printf("������ڵ����ݣ�\n");
			scanf("%d", &v);
			if (BST_insert(&r, v))
				printf("�����½ڵ�ɹ���\n");
			else
				printf("�����½ڵ�ʧ�ܣ�\n");
			system("pause");
			break;

		case 3://ɾ���ڵ�
			if (r.root == NULL)
			{
				printf("���ڵ㲻���ڣ�\n");
				system("pause");
				break;
			}

			printf("��������Ҫɾ���Ľڵ����ݣ�\n");
			scanf("%d", &v);
			BST_delete(&r, v);
			system("pause");
			break;

		case 4://���ҽڵ�
			if (r.root == NULL)
			{
				printf("���ڵ㲻���ڣ�\n");
				system("pause");
				break;
			}

			printf("��������Ҫ���ҵĽڵ����ݣ�\n");
			scanf("%d", &v);
			if (BST_search(&r, v))
			{
				printf("�ڵ���ڣ�\n");
			}
			system("pause");
			break;

		case 5://Ԥ�����
			if (r.root == NULL)
			{
				printf("���ڵ㲻���ڣ�\n");
				system("pause");
				break;
			}

			BST_preorderR(&r, Tprint);
			system("pause");
			break;

		case 6://�������
			if (r.root == NULL)
			{
				printf("���ڵ㲻���ڣ�\n");
				system("pause");
				break;
			}

			BST_inorderR(&r, Tprint);
			system("pause");
			break;

		case 7://�������
			if (r.root == NULL)
			{
				printf("���ڵ㲻���ڣ�\n");
				system("pause");
				break;
			}

			BST_postorderR(&r, Tprint);
			system("pause");
			break;

		case 0://�˳�
			printf("�����˳�ϵͳ��\n");
			system("pause");
			return 0;

		default:
			printf("�������\n���������룡\n");
			system("pause");
			break;
		}

	}

	return 0;
}
