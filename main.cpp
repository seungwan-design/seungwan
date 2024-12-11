#include <stdio.h>
#include <string.h>

// �ܾ ������ �Լ�
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
    char input[100]; // �Է� ���ڿ� ����

    // ���ڿ� �Է�
    printf("���ڿ��� �Է��ϼ���: ");
    fgets(input, sizeof(input), stdin);

    // '\n' ����
    input[strcspn(input, "\n")] = '\0';

    char* start = input; // �ܾ� ���� ��ġ
    for (char* cur = input; ; cur++)
    {
        if (*cur == ' ' || *cur == '\0') { // ���� �Ǵ� ���ڿ� ��
            reverse_word(start, (*cur == '\0') ? cur - 1 : cur - 1);
            if (*cur == '\0') break; // ���ڿ� ���̸� ����
            start = cur + 1;         // ���� �ܾ�� �̵�
        }
    }

    // ��� ���
    printf("������ ���: %s\n", input);
    return 0;
}
