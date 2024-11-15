#include <iostream> // C++ ǥ�� ����� ���
#include <vector> // ���� ����� ���� ��� ���� ����
#include <random> // ������ �� ������ ���� ��� ���� ����
#include <numeric> // ���� ����� ���� ��ƿ��Ƽ �Լ� ����
#include <cmath> // ���� ����� ���� ��� ���� ���� (�л� �� ǥ������ ���)

#define NUM_VALUES 10 // ������ ������ ���� ����
#define RANGE_MIN 1 // ������ ������ �ּҰ� ����
#define RANGE_MAX 100 // ������ ������ �ִ밪 ����

using namespace std;

// Ư�� ���� ������ ������ ������ �����ϴ� �Լ�
int GenRandInt(int min, int max)
{
    random_device rd; // ���� ���� ���� ��ġ
    mt19937 gen(rd()); // ���� ���� ����
    uniform_int_distribution<> distr(min, max); // ���� ���� ����
    return distr(gen); // min�� max ������ ������ ���� ��ȯ
}

// �迭�� ������ ����ϴ� �Լ�
int CalculateSum(const vector<int>& values)
{
    return accumulate(values.begin(), values.end(), 0); // ���� ��ҵ��� ��� ���Ͽ� ���� ���
}

// �迭�� ����� ����ϴ� �Լ�
double CalculateMean(int sum, int size)
{
    return static_cast<double>(sum) / size; // ������ size�� ������ ��� ���
}

// �迭�� �л��� ����ϴ� �Լ�
double CalculateVariance(const vector<int>& values, double mean)
{
    double variance = 0.0;
    for (int value : values)
    {
        variance += (value - mean) * (value - mean); // �� ��ҿ� ����� ���� ������ ����
    }
    return variance / values.size(); // �л� ���
}

// �迭�� ǥ�������� ����ϴ� �Լ�
double CalculateStdDev(double variance)
{
    return sqrt(variance); // �л��� �������� ���Ͽ� ǥ������ ���
}

int main()
{
    vector<int> values(NUM_VALUES); // �������� ������ ������ ������ ����
    int sum; // ������ ������ ����
    double mean, variance, stddev; // ���, �л�, ǥ�������� ������ ������

    // ���� 10�� ������ ���� �� ���
    cout << "�������� ������ 10���� ����: ";
    for (int i = 0; i < NUM_VALUES; i++)
    {
        values[i] = GenRandInt(RANGE_MIN, RANGE_MAX); // ������ ���� ����
        cout << values[i] << " "; // ������ ���� ���
    }
    cout << endl;

    // ���� ���
    sum = CalculateSum(values);

    // ��� ���
    mean = CalculateMean(sum, NUM_VALUES);

    // �л� ���
    variance = CalculateVariance(values, mean);

    // ǥ������ ���
    stddev = CalculateStdDev(variance);

    // ��� ���
    cout << "����: " << sum << endl;
    cout << "���: " << mean << endl;
    cout << "�л�: " << variance << endl;
    cout << "ǥ������: " << stddev << endl;

    return 0;
}
