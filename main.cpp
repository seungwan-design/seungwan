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

    // ���� ���� �Է�
    cout << "������ ������ ������ ������ �Է��ϼ��� (��: �ּ� �ִ�): ";
    cin >> lower >> upper;

    // ���� ����
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(lower, upper);

    for (int& num : numbers) 
    {
        num = dist(gen);
    }

    cout << "\n������ 100���� ����: ";
    for (const int& num : numbers) cout << num << " ";
    cout << endl;

    // ���� �����Ͽ� ���� ����
    cout << "\n������ ������ �Է��ϼ��� (��: ���� ����): ";
    cin >> rangeStart >> rangeEnd;

    for (const int& num : numbers) 
    {
        if (num >= rangeStart && num <= rangeEnd && extracted.size() < 10) 
        {
            extracted.push_back(num);
        }
    }

    cout << "\n����� ����: ";
    for (const int& num : extracted) cout << num << " ";
    cout << endl;

    // ��� ���
    double sum = 0;
    for (const int& num : extracted) sum += num;
    double mean = sum / extracted.size();

    double variance = 0;
    for (const int& num : extracted) variance += pow(num - mean, 2);
    variance /= extracted.size();

    double standardDeviation = sqrt(variance);

    // ��� ���
    cout << "\n��: " << sum << endl;
    cout << "���: " << mean << endl;
    cout << "�л�: " << variance << endl;
    cout << "ǥ������: " << standardDeviation << endl;

    return 0;
}
