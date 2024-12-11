#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 배열 통계 계산 (총합, 평균, 분산)
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

    // 초기 배열 크기 입력 및 메모리 할당
    printf("배열 크기: ");
    scanf_s("%d", &size);
    arr = (int*)malloc(size * sizeof(int));

    // 배열 값 입력
    printf("값 입력: ");
    for (int i = 0; i < size; i++) scanf_s("%d", &arr[i]);

    // 초기 배열 통계 계산 및 출력
    calculate(arr, size, &mean, &variance);
    printf("합: %.0f, 평균: %.2f, 분산: %.2f, 표준편차: %.2f\n", mean * size, mean, variance, sqrt(variance));

    // 추가 크기 입력 및 배열 확장
    printf("추가 크기: ");
    scanf_s("%d", &new_size);
    arr = (int*)realloc(arr, (size + new_size) * sizeof(int));
    printf("추가 값 입력: ");
    for (int i = size; i < size + new_size; i++) scanf_s("%d", &arr[i]);

    // 확장된 배열 통계 계산 및 출력
    calculate(arr, size + new_size, &mean, &variance);
    printf("합: %.0f, 평균: %.2f, 분산: %.2f, 표준편차: %.2f\n", mean * (size + new_size), mean, variance, sqrt(variance));

    // 메모리 해제
    free(arr);
    return 0;
}
