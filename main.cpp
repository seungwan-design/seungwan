#include <stdio.h>
#include <string.h>

// 단어를 뒤집는 함수
void reverse_word(char* start, char* end)
{
    while (start < end)
    {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

int main() {
    char input[100]; // 입력 문자열 저장

    // 문자열 입력
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    // '\n' 제거
    input[strcspn(input, "\n")] = '\0';

    char* start = input; // 단어 시작 위치
    for (char* cur = input; ; cur++)
    {
        if (*cur == ' ' || *cur == '\0') { // 공백 또는 문자열 끝
            reverse_word(start, (*cur == '\0') ? cur - 1 : cur - 1);
            if (*cur == '\0') break; // 문자열 끝이면 종료
            start = cur + 1;         // 다음 단어로 이동
        }
    }

    // 결과 출력
    printf("뒤집힌 결과: %s\n", input);
    return 0;
}
