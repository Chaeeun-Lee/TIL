#include <stdio.h>

typedef struct _scoreTable {
	char name[10];
	char subject1[10];
	char subject2[10];
	char score1[2];
	char score2[2];
} scoreTable;

int main()
{
	scoreTable student[3];
	int selectMenu, selectClassNum;

	while (1)
	{
		printf("%s | %s | %s �� ", "�� ���� �Է�", "�� ���� ���", "�� ����");
		scanf("%d", &selectMenu);

		printf("\n");

		if (selectMenu == 1) 
		{
			printf("�й� �Է� (1~3): ");
			scanf("%d", &selectClassNum);

			while (1)
			{
				if (selectClassNum != 1 && selectClassNum != 2 && selectClassNum != 3)
				{
					printf("�ٽ� �Է�: ");
					scanf("%d", &selectClassNum);
				}
				else
					break;
			}

			--selectClassNum;

			printf("\n");

			printf("�̸�: ");
			scanf("%s", student[selectClassNum].name);
			printf("����: ");
			scanf("%s", student[selectClassNum].subject1);
			printf("����(������ A~C or F): ");
			scanf("%s", student[selectClassNum].score1);
			printf("����: ");
			scanf("%s", student[selectClassNum].subject2);
			printf("����(������ A~C or F): ");
			scanf("%s", student[selectClassNum].score2);
		}
		else if (selectMenu == 2)
		{
			printf("�й� �Է� (1~3): ");
			scanf("%d", &selectClassNum);

			while (1)
			{
				if (selectClassNum != 1 && selectClassNum != 2 && selectClassNum != 3)
				{
					printf("�ٽ� �Է�: ");
					scanf("%d", &selectClassNum);
				}
				else
					break;
			}

			--selectClassNum;

			printf("�̸�: %s\n", student[selectClassNum].name);
			printf("%s ������ ���� %s\n", student[selectClassNum].subject1, student[selectClassNum].score1);
			printf("%s ������ ���� %s\n", student[selectClassNum].subject2, student[selectClassNum].score2);
			printf("��������������������������������������������\n");
		}
		else if (selectMenu == 3)
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else
		{
			printf("�ٽ� ������ �ּ���.");
			scanf("%d", &selectMenu);
		}
		printf("\n");
	}
}