#include <stdio.h>
int LCount, RCount = 0;
int x, y = 0;
void N(int L, int R) //�ڵ��� �� �κ��� ������ ����
{
		y++;
	printf("N����\t(%d, %d)\n", x, y);
}
void W(int L, int R) //�ڵ��� �� �κ��� ������ ����
{
		x--;
	
	printf("W����\t(%d, %d)\n", x, y);
}
void E(int L, int R) //�ڵ��� �� �κ��� �������� ����
{
	x++;
	printf("E����\t(%d, %d)\n", x, y);
}
void S(int L, int R) //�ڵ��� �� �κ��� �Ʒ����� ����
{
		y--;
	printf("S����\t(%d, %d)\n", x, y);
}
void Direction(int L, int R) // ���� ȸ�� ������ ȸ���� Ƚ���� ������ �պκ��� ������ �����ϴ� �Լ�
{
	int Left = L;
	int Right = R;
	LCount = LCount % 4;
	RCount = RCount % 4;
	if (Left - Right == 1 || Left - Right == -3)
		W(x, y);
	else if (Right - Left == 1 || Right - Left == -3)
		E(x, y);
	else if (Left - Right == 2 || Left - Right == - 2)
		S(x, y);
	else
		N(x, y);
}
int main()
{
	FILE *pFile = NULL;

	pFile = fopen("c://move.txt", "r"); // �ؽ�Ʈ ���� ��������
	if (pFile == NULL)
	{
		printf("�����Դϴ�.\n");// ���� ó��
	}
	else
	{
		char direction;

		while (!feof(pFile))
		{
			direction = fgetc(pFile);
			if (direction == 'L') // L������ ���
				Direction(++LCount, RCount);
			else if (direction == 'R') // R������ ���
				Direction(LCount, ++RCount);
			else if (direction == 'F') // F������ ���
				Direction(LCount, RCount);
		}
		printf("\n���� ��ġ: ( %d, %d )\n", x, y);
		//printf("LCount: %d \nRCount: %d \n", LCount, RCount);
		fclose(pFile);
	}

	return 0;
}