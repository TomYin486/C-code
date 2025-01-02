#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long n = 0;    // n 表示 01 串的长度
long long t = 0;    // t 表示变换的次数
int x = 1;          // 用于计算循环周期
char s[10005];      // 存储 01 串的字符数组

int main()
{
    scanf("%lld %lld", &n, &t);
    scanf("%s", s);

    // 计算 x 的最小值（这个值用于确定变换的周期），使得 x >= n
    while (x < n)
    {
        // 通过左移操作找到大于或等于 n 的最小的 2 的幂次方值
        x <<= 1;
    }

    // 减少不必要的重复计算
    t = t % x;

    // 进行 t 次操作
    int i = 0;
    for (int i = 0; i < t; i++)
    {
        int j = 0;
        // 对当前字符和前一个字符进行异或操作
        for (j = n - 1; j >= 1; j--)
        {
            // s[j] - '0' 表示将字符转换为数字（0 或 1）, + '0' 表示将结果转换回字符形式
            s[j] = ((s[j] - '0') ^ (s[j - 1] - '0')) + '0';
        }
    }

    printf("%s\n", s);

    return 0;
}
