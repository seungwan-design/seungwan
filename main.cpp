#include <iostream>
#include <array>

using namespace std;

// 함수 선언
array<double, 3> crossProduct(const array<double, 3>& vec1, const array<double, 3>& vec2);
double dotProduct(const array<double, 3>& vec1, const array<double, 3>& vec2);

int main() {
    // 3차원 벡터 입력
    array<double, 3> vec1, vec2;

    cout << "첫 번째 벡터 (3차원)의 각 성분을 입력하세요 (예: x y z): ";
    cin >> vec1[0] >> vec1[1] >> vec1[2];

    cout << "두 번째 벡터 (3차원)의 각 성분을 입력하세요 (예: x y z): ";
    cin >> vec2[0] >> vec2[1] >> vec2[2];

    // 내적 계산
    double dot = dotProduct(vec1, vec2);
    // 외적 계산
    array<double, 3> cross = crossProduct(vec1, vec2);

    // 결과 출력
    cout << "\n내적 결과: " << dot << endl;
    cout << "외적 결과: (" << cross[0] << ", " << cross[1] << ", " << cross[2] << ")" << endl;

    return 0;
}

// 내적 계산 함수
double dotProduct(const array<double, 3>& vec1, const array<double, 3>& vec2) {
    // 두 벡터의 내적 공식: vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2]
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

// 외적 계산 함수
array<double, 3> crossProduct(const array<double, 3>& vec1, const array<double, 3>& vec2) {
    array<double, 3> result;
    // 외적 계산 공식:
    // x = vec1[1]*vec2[2] - vec1[2]*vec2[1]
    // y = vec1[2]*vec2[0] - vec1[0]*vec2[2]
    // z = vec1[0]*vec2[1] - vec1[1]*vec2[0]
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
    return result;
}
