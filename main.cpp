#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define UNUSED -1

//함수 선언
void CalcEvenOddArray(int* arr, int size, int* evenArr, int* oddArrr, int* evenCount, int* oddCount);
void PrintArray(int* arr, int size, const char* message);

int main()
{
	int arr[ARRAY_SIZE];
	int evenArr[ARRAY_SIZE] = { UNUSED }; // 짝수 배열 초기화
	int oddArr[ARRAY_SIZE] = { UNUSED }; // 홀수 배열 초기화
	int evenCount = 0, oddCount = 0;

	srand(time(0)); //랜덤 시드 설정

	// 배열에 랜덤 값 생성하기 (0 ~ 100 범위 정수)
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		arr[i] = rand() % 101; // 0 ~ 100 범위 생성
	}

	//랜덤 생성 상태 출력
	PrintArray(arr, ARRAY_SIZE, "Initial Random Array");
	{
		//짝수 / 홀수 분리 처리
		CalcEvenOddArray(arr, ARRAY_SIZE, evenArr, oddArr, &evenCount, &oddCount);
		PrintArray(evenArr, evenCount, "Even Numbers Array");
		PrintArray(oddArr, oddCount, "Odd Numners Array");
	}
	return 0;
}
// 배열 짝수 / 홀수 분리 함수
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
// 배열 출력 함수
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