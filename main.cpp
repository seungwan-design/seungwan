#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

int main() 
{
    vector<int> numbers(100);
    vector<int> extracted;
    int lower, upper, rangeStart, rangeEnd;

    // 난수 범위 입력
    cout << "무작위 정수를 생성할 범위를 입력하세요 (예: 최소 최대): ";
    cin >> lower >> upper;

    // 난수 생성
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(lower, upper);

    for (int& num : numbers) 
    {
        num = dist(gen);
    }

    cout << "\n생성된 100개의 난수: ";
    for (const int& num : numbers) cout << num << " ";
    cout << endl;

    // 범위 지정하여 숫자 추출
    cout << "\n추출할 범위를 입력하세요 (예: 시작 종료): ";
    cin >> rangeStart >> rangeEnd;

    for (const int& num : numbers) 
    {
        if (num >= rangeStart && num <= rangeEnd && extracted.size() < 10) 
        {
            extracted.push_back(num);
        }
    }

    cout << "\n추출된 숫자: ";
    for (const int& num : extracted) cout << num << " ";
    cout << endl;

    // 통계 계산
    double sum = 0;
    for (const int& num : extracted) sum += num;
    double mean = sum / extracted.size();

    double variance = 0;
    for (const int& num : extracted) variance += pow(num - mean, 2);
    variance /= extracted.size();

    double standardDeviation = sqrt(variance);

    // 결과 출력
    cout << "\n합: " << sum << endl;
    cout << "평균: " << mean << endl;
    cout << "분산: " << variance << endl;
    cout << "표준편차: " << standardDeviation << endl;

    return 0;
}
