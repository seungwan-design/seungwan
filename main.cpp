#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEADS 0
#define TAILS 1
#define NUM_FLIPS 10000

// 시간 기반으로 난수 시드를 생성하는 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL))); // 현재 시간을 사용하여 난수 시드 설정
}

// 동전을 무작위로 던지는 함수
unsigned int CoinFlip()
{
    return rand() % 2; // 0 (앞면) 또는 1 (뒷면)을 반환
}

int main(void)
{
    char choice;
    unsigned int result;
    unsigned int headsCount = 0;
    unsigned int tailsCount = 0;

    // 난수 시드 초기화
    GenRandSeed();

    printf("동전 던지기 시뮬레이터에 오신 것을 환영합니다!\n");

    while (1)
    {
        // 사용자에게 동전을 10,000번 던질지 물어봄
        printf("동전을 10,000번 던져 확률을 계산하시겠습니까? (예/아니오): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N')
        {
            printf("동전 던지기 시뮬레이터를 종료합니다. 안녕히 가세요!\n");
            break;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            // 동전을 10,000번 던짐
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

            // 확률을 계산하고 출력
            double headsProbability = (double)headsCount / NUM_FLIPS * 100; // 앞면 확률 계산
            double tailsProbability = (double)tailsCount / NUM_FLIPS * 100; // 뒷면 확률 계산

            printf("앞면 횟수: %u, 뒷면 횟수: %u\n", headsCount, tailsCount);
            printf("앞면 확률: %.2f%%\n", headsProbability);
            printf("뒷면 확률: %.2f%%\n\n", tailsProbability);

            // 다음 실행을 위해 카운트를 초기화
            headsCount = 0;
            tailsCount = 0;
        }
        else
        {
            printf("잘못된 입력입니다. 동전을 던지려면 '예'를, 종료하려면 '아니오'를 입력하세요.\n");
        }
    }

    return 0;
}
