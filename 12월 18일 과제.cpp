#include <stdio.h>
#include <math.h>

// 3차원 점을 나타내는 구조체 선언
typedef struct
{
    double x;
    double y;
    double z;
} Point3D;

// 두 점 사이의 Euclidean Distance를 계산하는 함수
double calculateDistance(const Point3D* p1, const Point3D* p2)
{
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
}

// 메인 함수
int main()
{
    Point3D point1, point2;

    // 첫 번째 점의 좌표 입력
    printf("첫 번째 점의 x, y, z 좌표를 입력하세요 (예: 1.0 2.0 3.0): ");
    if (scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z) != 3)
    {
        printf("입력 형식이 잘못되었습니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    // 두 번째 점의 좌표 입력
    printf("두 번째 점의 x, y, z 좌표를 입력하세요 (예: 4.0 5.0 6.0): ");
    if (scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z) != 3)
    {
        printf("입력 형식이 잘못되었습니다. 프로그램을 종료합니다.\n");
        return 1;
    }

    // 거리 계산
    double distance = calculateDistance(&point1, &point2);

    // 결과 출력
    printf("두 점 사이의 거리: %.2f\n", distance);

    return 0;
}
