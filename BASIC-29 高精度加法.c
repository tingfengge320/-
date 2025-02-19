#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

// 反转字符串
void reverse(char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// 高精度加法
void add(char *a, char *b, char *result) {
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    int carry = 0; // 进位

    // 反转字符串，方便从最低位开始计算
    reverse(a, lenA);
    reverse(b, lenB);

    for (int i = 0; i < maxLen; i++) {
        int sum = carry; // 加上进位
        if (i < lenA) {
            sum += a[i] - '0'; // 加上a的当前位
        }
        if (i < lenB) {
            sum += b[i] - '0'; // 加上b的当前位
        }
        carry = sum / 10; // 更新进位
        result[i] = (sum % 10) + '0'; // 计算当前位的结果
    }

    if (carry > 0) {
        result[maxLen] = carry + '0'; // 如果还有进位，添加到结果中
    }
    result[maxLen + 1] = '\0'; // 字符串结束符

    // 反转回正常顺序
    reverse(result, maxLen + (carry > 0 ? 1 : 0));
}

int main() {
    char a[MAX_LEN], b[MAX_LEN], result[MAX_LEN + 2]; // +2 为了存储可能的进位和字符串结束符

    scanf("%s", a);
    scanf("%s", b);

    add(a, b, result);

    printf("%s\n", result);

    return 0;
}
