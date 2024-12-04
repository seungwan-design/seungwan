#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// �Լ� ����
void CalcInverseArray(float* arr, int size);
void PrintArray(float* arr, int size, const char* message);

int main()
{
    float arr[ARRAY_SIZE];
    srand(time(0)); // ���� �õ� ����

    // �迭�� ���� �� �����ϱ� (-100.0 ~ +100.0 ������ �Ǽ�)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = ((float)rand() / RAND_MAX) * 200.0 - 100.0; // -100.0 ~ +100.0 ���� ����
    }

    // ���� ���� ���� ���
    PrintArray(arr, ARRAY_SIZE, "Initial Random Array");

    // �迭 ���� ó��
    CalcInverseArray(arr, ARRAY_SIZE);
    PrintArray(arr, ARRAY_SIZE, "Reversed Array");

    return 0;
}

// �迭 ���� ó�� �Լ�
void CalcInverseArray(float* arr, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        // �հ� ���� ���� ��ȯ
        float temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// �迭 ��� �Լ�
void PrintArray(float* arr, int size, const char* message)
{
    printf("%s:\n", message);
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n\n");
}