#include <iostream> // C++ 표준 입출력 사용
#include <vector> // 벡터 사용을 위한 헤더 파일 포함
#include <random> // 무작위 수 생성을 위한 헤더 파일 포함
#include <numeric> // 총합 계산을 위한 유틸리티 함수 포함
#include <cmath> // 수학 계산을 위한 헤더 파일 포함 (분산 및 표준편차 계산)

#define NUM_VALUES 10 // 생성할 정수의 개수 정의
#define RANGE_MIN 1 // 무작위 정수의 최소값 정의
#define RANGE_MAX 100 // 무작위 정수의 최대값 정의

using namespace std;

// 특정 범위 내에서 무작위 정수를 생성하는 함수
int GenRandInt(int min, int max)
{
    random_device rd; // 실제 난수 생성 장치
    mt19937 gen(rd()); // 난수 생성 엔진
    uniform_int_distribution<> distr(min, max); // 균일 분포 정의
    return distr(gen); // min과 max 사이의 무작위 정수 반환
}

// 배열의 총합을 계산하는 함수
int CalculateSum(const vector<int>& values)
{
    return accumulate(values.begin(), values.end(), 0); // 벡터 요소들을 모두 더하여 총합 계산
}

// 배열의 평균을 계산하는 함수
double CalculateMean(int sum, int size)
{
    return static_cast<double>(sum) / size; // 총합을 size로 나눠서 평균 계산
}

// 배열의 분산을 계산하는 함수
double CalculateVariance(const vector<int>& values, double mean)
{
    double variance = 0.0;
    for (int value : values)
    {
        variance += (value - mean) * (value - mean); // 각 요소와 평균의 차의 제곱을 누적
    }
    return variance / values.size(); // 분산 계산
}

// 배열의 표준편차를 계산하는 함수
double CalculateStdDev(double variance)
{
    return sqrt(variance); // 분산의 제곱근을 구하여 표준편차 계산
}

int main()
{
    vector<int> values(NUM_VALUES); // 무작위로 생성된 정수를 저장할 벡터
    int sum; // 총합을 저장할 변수
    double mean, variance, stddev; // 평균, 분산, 표준편차를 저장할 변수들

    // 정수 10개 무작위 생성 및 출력
    cout << "무작위로 생성된 10개의 정수: ";
    for (int i = 0; i < NUM_VALUES; i++)
    {
        values[i] = GenRandInt(RANGE_MIN, RANGE_MAX); // 무작위 정수 생성
        cout << values[i] << " "; // 생성된 정수 출력
    }
    cout << endl;

    // 총합 계산
    sum = CalculateSum(values);

    // 평균 계산
    mean = CalculateMean(sum, NUM_VALUES);

    // 분산 계산
    variance = CalculateVariance(values, mean);

    // 표준편차 계산
    stddev = CalculateStdDev(variance);

    // 결과 출력
    cout << "총합: " << sum << endl;
    cout << "평균: " << mean << endl;
    cout << "분산: " << variance << endl;
    cout << "표준편차: " << stddev << endl;

    return 0;
}
