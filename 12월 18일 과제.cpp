#include <stdio.h>
#include <math.h>

// 3���� ���� ��Ÿ���� ����ü ����
typedef struct
{
    double x;
    double y;
    double z;
} Point3D;

// �� �� ������ Euclidean Distance�� ����ϴ� �Լ�
double calculateDistance(const Point3D* p1, const Point3D* p2)
{
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2) + pow(p2->z - p1->z, 2));
}

// ���� �Լ�
int main()
{
    Point3D point1, point2;

    // ù ��° ���� ��ǥ �Է�
    printf("ù ��° ���� x, y, z ��ǥ�� �Է��ϼ��� (��: 1.0 2.0 3.0): ");
    if (scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z) != 3)
    {
        printf("�Է� ������ �߸��Ǿ����ϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }

    // �� ��° ���� ��ǥ �Է�
    printf("�� ��° ���� x, y, z ��ǥ�� �Է��ϼ��� (��: 4.0 5.0 6.0): ");
    if (scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z) != 3)
    {
        printf("�Է� ������ �߸��Ǿ����ϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }

    // �Ÿ� ���
    double distance = calculateDistance(&point1, &point2);

    // ��� ���
    printf("�� �� ������ �Ÿ�: %.2f\n", distance);

    return 0;
}
