#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int a[1000];    // 数组 a 用于存储数字的每一位
int B = 2;      // B 是乘数，这里设置为 2
int n = 0;      // n 是数组 a 中已经存储的数字的位数

// 用于将数组 a 中的数字乘以 2
void gj(int a[], int len)
{
    int i = 0;
    int t = 0; // 用于存储进位
    for (i = 0; i < len; i++)
    {
        // 将数组 a 的当前位乘以 B（2），再加上之前计算的进位 t
        a[i] = (a[i] * B) + t;

        // 计算新的进位，让当前位乘以 B 加上进位后除以 10 的商
        t = a[i] / 10;

        // 更新数组 a 的当前位，进行取余数
        a[i] %= 10;
    }
    // 如果有进位，则将进位值存储在数组 a 的下一位
    if (t != 0)
    {
        a[len] = t;
        n++;
    }
}

int main()
{
    int i = 0;
    int N = 0;        // N 表示为需要乘以的次数
    scanf("%d", &N);
    char str[1000];   // 用于存储浮点数字符串长度
    scanf("%s", str);

    int flag = 0;     // 用于标记小数点的位置
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == '.')
        {
            // 记录小数点的位置
            flag = strlen(str) - 1 - i;
            continue;
        }
        else
        {
            // 将字符转换为对应的整数值，并存储到数组 a 中，然后增加 n
            a[n] = (str[i] - '0');
            n++;
        }
    }

    while (N--)
    {
        // 执行乘法操作
        gj(a, n);
    }

    // 判断是否需要进行四舍五入
    if (a[flag - 1] >= 5)
    {
        int t = 1; // 末尾 +1，注意 i = flag
        for (i = flag; i < n; i++)
        {
            // 对数组 a 的每一位加 1 ，并处理进位
            a[i] = a[i] + t;
            t = a[i] / 10;
            a[i] %= 10;
        }
        // 如果最后还有进位，将其添加到数组 a 的末尾，并增加 n
        if (t != 0)
        {
            a[n] = t;
            n++;
        }
    }

    // 直接打印
    for (i = n - 1; i >= flag; i--)
    {
        printf("%d", a[i]);
    }
    return 0;
}
