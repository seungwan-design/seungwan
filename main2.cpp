#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �迭 ��� ��� (����, ���, �л�)
void calculate(int* arr, int size, double* mean, double* variance) {
    int sum = 0;
    *variance = 0.0;

    for (int i = 0; i < size; i++) sum += arr[i];
    *mean = (double)sum / size;

    for (int i = 0; i < size; i++) *variance += (arr[i] - *mean) * (arr[i] - *mean);
    *variance /= size;
}

int main() {
    int size, new_size, * arr;
    double mean, variance;

    // �ʱ� �迭 ũ�� �Է� �� �޸� �Ҵ�
    printf("�迭 ũ��: ");
    scanf_s("%d", &size);
    arr = (int*)malloc(size * sizeof(int));

    // �迭 �� �Է�
    printf("�� �Է�: ");
    for (int i = 0; i < size; i++) scanf_s("%d", &arr[i]);

    // �ʱ� �迭 ��� ��� �� ���
    calculate(arr, size, &mean, &variance);
    printf("��: %.0f, ���: %.2f, �л�: %.2f, ǥ������: %.2f\n", mean * size, mean, variance, sqrt(variance));

    // �߰� ũ�� �Է� �� �迭 Ȯ��
    printf("�߰� ũ��: ");
    scanf_s("%d", &new_size);
    arr = (int*)realloc(arr, (size + new_size) * sizeof(int));
    printf("�߰� �� �Է�: ");
    for (int i = size; i < size + new_size; i++) scanf_s("%d", &arr[i]);

    // Ȯ��� �迭 ��� ��� �� ���
    calculate(arr, size + new_size, &mean, &variance);
    printf("��: %.0f, ���: %.2f, �л�: %.2f, ǥ������: %.2f\n", mean * (size + new_size), mean, variance, sqrt(variance));

    // �޸� ����
    free(arr);
    return 0;
}
