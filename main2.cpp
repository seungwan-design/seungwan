#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// �Լ� ����
void CalcSortArray(float* arr, int size, int ascending);
void PrintArray(float* arr, int size, const char* message);

int main()
{
    float arr[ARRAY_SIZE];
    srand(time(0)); // ���� �õ� ����

    // �迭�� ���� �� �����ϱ� (-100.0 ~ +100.0 ������ �Ǽ�)
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = ((float)rand() / RAND_MAX) * 200.0 - 100.0; // -100.0 ~ +100.0 ���� ����
    }

    // ���� ���� ���� ���
    PrintArray(arr, ARRAY_SIZE, "Initial Random Array");

    // �������� ����
    CalcSortArray(arr, ARRAY_SIZE, 1);
    PrintArray(arr, ARRAY_SIZE, "Sorted Array (Ascending)");

    // �������� ����
    CalcSortArray(arr, ARRAY_SIZE, 0);
    PrintArray(arr, ARRAY_SIZE, "Sorted Array (Descending)");

    return 0;
}

// �迭 ���� �Լ� (��������/�������� ���� ����)
void CalcSortArray(float* arr, int size, int ascending)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((ascending && arr[i] > arr[j]) || (!ascending && arr[i] < arr[j]))
            {
                // �� ��ȯ (�������� �Ǵ� ���������� ����)
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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