#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// 함수 선언
void CalcInverseArray(float* arr, int size);
void PrintArray(float* arr, int size, const char* message);

int main()
{
    float arr[ARRAY_SIZE];
    srand(time(0)); // 랜덤 시드 설정

    // 배열에 랜덤 값 생성하기 (-100.0 ~ +100.0 범위의 실수)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = ((float)rand() / RAND_MAX) * 200.0 - 100.0; // -100.0 ~ +100.0 범위 생성
    }

    // 랜덤 생성 상태 출력
    PrintArray(arr, ARRAY_SIZE, "Initial Random Array");

    // 배열 역순 처리
    CalcInverseArray(arr, ARRAY_SIZE);
    PrintArray(arr, ARRAY_SIZE, "Reversed Array");

    return 0;
}

// 배열 역순 처리 함수
void CalcInverseArray(float* arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        // 앞과 뒤의 값을 교환
        float temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
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