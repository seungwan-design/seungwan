#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define UNUSED -1

//�Լ� ����
void CalcEvenOddArray(int* arr, int size, int* evenArr, int* oddArrr, int* evenCount, int* oddCount);
void PrintArray(int* arr, int size, const char* message);

int main()
{
	int arr[ARRAY_SIZE];
	int evenArr[ARRAY_SIZE] = { UNUSED }; // ¦�� �迭 �ʱ�ȭ
	int oddArr[ARRAY_SIZE] = { UNUSED }; // Ȧ�� �迭 �ʱ�ȭ
	int evenCount = 0, oddCount = 0;

	srand(time(0)); //���� �õ� ����

	// �迭�� ���� �� �����ϱ� (0 ~ 100 ���� ����)
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = rand() % 101; // 0 ~ 100 ���� ����
	}

	//���� ���� ���� ���
	PrintArray(arr, ARRAY_SIZE, "Initial Random Array");
	{
		//¦�� / Ȧ�� �и� ó��
		CalcEvenOddArray(arr, ARRAY_SIZE, evenArr, oddArr, &evenCount, &oddCount);
		PrintArray(evenArr, evenCount, "Even Numbers Array");
		PrintArray(oddArr, oddCount, "Odd Numners Array");
	}
	return 0;
}
// �迭 ¦�� / Ȧ�� �и� �Լ�
void CalcEvenOddArray(int* arr, int size, int* evenArr, int* oddArr, int* evenCount, int* oddCount)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			evenArr[*evenCount] = arr[i];
			(*evenCount)++;
		}
		else
		{
			oddArr[*evenCount] = arr[i];
			(*oddCount)++;
		}
	}
}
// �迭 ��� �Լ�
void PrintArray(int* arr, int size, const char* message)
{
	printf("%s:\n", message);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != UNUSED)
		{
			printf("%d", arr[i]);
		}
	}
	printf("\n\n");
}