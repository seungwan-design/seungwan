#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// 함수 선언
void CalcSortArray(float* arr, int size, int ascending);
void PrintArray(float* arr, int size, const char* message);

int main()
{
    float arr[ARRAY_SIZE];
    srand(time(0)); // 랜덤 시드 설정

    // 배열에 랜덤 값 생성하기 (-100.0 ~ +100.0 범위의 실수)
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = ((float)rand() / RAND_MAX) * 200.0 - 100.0; // -100.0 ~ +100.0 범위 생성
    }

    // 랜덤 생성 상태 출력
    PrintArray(arr, ARRAY_SIZE, "Initial Random Array");

    // 오름차순 정렬
    CalcSortArray(arr, ARRAY_SIZE, 1);
    PrintArray(arr, ARRAY_SIZE, "Sorted Array (Ascending)");

    // 내림차순 정렬
    CalcSortArray(arr, ARRAY_SIZE, 0);
    PrintArray(arr, ARRAY_SIZE, "Sorted Array (Descending)");

    return 0;
}

// 배열 정렬 함수 (오름차순/내림차순 선택 가능)
void CalcSortArray(float* arr, int size, int ascending)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j]))
            {
                // 값 교환 (오름차순 또는 내림차순에 따라)
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 배열 출력 함수
void PrintArray(float* arr, int size, const char* message)
{
    printf("%s:\n", message);
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
}