#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

// ��ת�ַ���
void reverse(char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// �߾��ȼӷ�
void add(char *a, char *b, char *result) {
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    int carry = 0; // ��λ

    // ��ת�ַ�������������λ��ʼ����
    reverse(a, lenA);
    reverse(b, lenB);

    for (int i = 0; i < maxLen; i++) {
        int sum = carry; // ���Ͻ�λ
        if (i < lenA) {
            sum += a[i] - '0'; // ����a�ĵ�ǰλ
        }
        if (i < lenB) {
            sum += b[i] - '0'; // ����b�ĵ�ǰλ
        }
        carry = sum / 10; // ���½�λ
        result[i] = (sum % 10) + '0'; // ���㵱ǰλ�Ľ��
    }

    if (carry > 0) {
        result[maxLen] = carry + '0'; // ������н�λ����ӵ������
    }
    result[maxLen + 1] = '\0'; // �ַ���������

    // ��ת������˳��
    reverse(result, maxLen + (carry > 0 ? 1 : 0));
}

int main() {
    char a[MAX_LEN], b[MAX_LEN], result[MAX_LEN + 2]; // +2 Ϊ�˴洢���ܵĽ�λ���ַ���������

    scanf("%s", a);
    scanf("%s", b);

    add(a, b, result);

    printf("%s\n", result);

    return 0;
}
