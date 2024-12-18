#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 将十进制数转换为 n 进制数
void func1(int num, int base)
{
    // 假设数组足够大，可以存储转换后的数字
    char result[100];
    int index = 0;

    // 如果数字为 0，直接返回
    if (num == 0)
    {
        printf("0");
        return;
    }


    while (num > 0)
    {
        // 取余数
        int remainder = num % base;

        if (remainder < 10)
        {
            // 转换为字符并存储
            result[index++] = '0' + remainder;
        }
        else
        {
            // 使用大写字母表示 10 以上的数字
            result[index++] = 'A' + remainder - 10;
        }
        // 更新 num 为 num/base 的整数部分
        num /= base;
    }

    int i = 0;
    // 结果是反向存储的，要反向打印
    for (i = index - 1; i >= 0; i--)
    {
        printf("%c", result[i]);
    }
}

int main()
{
    int i = 0;
    int j = 0;
    int n = 0;
    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            int product = i * j;
            func1(i, n);   // 输出第一个乘数
            printf("*");
            func1(j, n);   // 输出第二个乘数
            printf("=");
            func1(product, n); // 输出乘积
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
