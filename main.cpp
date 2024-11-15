#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEADS 0
#define TAILS 1
#define NUM_FLIPS 10000

// �ð� ������� ���� �õ带 �����ϴ� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL))); // ���� �ð��� ����Ͽ� ���� �õ� ����
}

// ������ �������� ������ �Լ�
unsigned int CoinFlip()
{
    return rand() % 2; // 0 (�ո�) �Ǵ� 1 (�޸�)�� ��ȯ
}

int main(void)
{
    char choice;
    unsigned int result;
    unsigned int headsCount = 0;
    unsigned int tailsCount = 0;

    // ���� �õ� �ʱ�ȭ
    GenRandSeed();

    printf("���� ������ �ùķ����Ϳ� ���� ���� ȯ���մϴ�!\n");

    while (1)
    {
        // ����ڿ��� ������ 10,000�� ������ ���
        printf("������ 10,000�� ���� Ȯ���� ����Ͻðڽ��ϱ�? (��/�ƴϿ�): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N')
        {
            printf("���� ������ �ùķ����͸� �����մϴ�. �ȳ��� ������!\n");
            break;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            // ������ 10,000�� ����
            for (int i = 0; i < NUM_FLIPS; i++)
            {
                result = CoinFlip();
                if (result == HEADS)
                {
                    headsCount++;
                }
                else
                {
                    tailsCount++;
                }
            }

            // Ȯ���� ����ϰ� ���
            double headsProbability = (double)headsCount / NUM_FLIPS * 100; // �ո� Ȯ�� ���
            double tailsProbability = (double)tailsCount / NUM_FLIPS * 100; // �޸� Ȯ�� ���

            printf("�ո� Ƚ��: %u, �޸� Ƚ��: %u\n", headsCount, tailsCount);
            printf("�ո� Ȯ��: %.2f%%\n", headsProbability);
            printf("�޸� Ȯ��: %.2f%%\n\n", tailsProbability);

            // ���� ������ ���� ī��Ʈ�� �ʱ�ȭ
            headsCount = 0;
            tailsCount = 0;
        }
        else
        {
            printf("�߸��� �Է��Դϴ�. ������ �������� '��'��, �����Ϸ��� '�ƴϿ�'�� �Է��ϼ���.\n");
        }
    }

    return 0;
}
