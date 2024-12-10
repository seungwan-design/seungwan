#include <iostream>
#include <array>

using namespace std;

// �Լ� ����
array<double, 3> crossProduct(const array<double, 3>& vec1, const array<double, 3>& vec2);
double dotProduct(const array<double, 3>& vec1, const array<double, 3>& vec2);

int main() {
    // 3���� ���� �Է�
    array<double, 3> vec1, vec2;

    cout << "ù ��° ���� (3����)�� �� ������ �Է��ϼ��� (��: x y z): ";
    cin >> vec1[0] >> vec1[1] >> vec1[2];

    cout << "�� ��° ���� (3����)�� �� ������ �Է��ϼ��� (��: x y z): ";
    cin >> vec2[0] >> vec2[1] >> vec2[2];

    // ���� ���
    double dot = dotProduct(vec1, vec2);
    // ���� ���
    array<double, 3> cross = crossProduct(vec1, vec2);

    // ��� ���
    cout << "\n���� ���: " << dot << endl;
    cout << "���� ���: (" << cross[0] << ", " << cross[1] << ", " << cross[2] << ")" << endl;

    return 0;
}

// ���� ��� �Լ�
double dotProduct(const array<double, 3>& vec1, const array<double, 3>& vec2) {
    // �� ������ ���� ����: vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2]
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

// ���� ��� �Լ�
array<double, 3> crossProduct(const array<double, 3>& vec1, const array<double, 3>& vec2) {
    array<double, 3> result;
    // ���� ��� ����:
    // x = vec1[1]*vec2[2] - vec1[2]*vec2[1]
    // y = vec1[2]*vec2[0] - vec1[0]*vec2[2]
    // z = vec1[0]*vec2[1] - vec1[1]*vec2[0]
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
    return result;
}
