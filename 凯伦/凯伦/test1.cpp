#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000   // 表示数组的最大大小
#define MAXA 1000000  // 表示 a[i] 的最大值

long long f[MAXN];    // 数组 f 用于存入斐波那契数列
long long a[MAXN];    // 数组 a 用于存入输入的整数序列
int bot[MAXA];        // 数组 bot 用于统计 a[i] / f[i] 的出现次数

int main()
{
    int n = 0;           // 表示输入的整数序列的长度
    scanf("%d", &n);

    long long az = -1;   // az 用于记录 a[i] 的最大值
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > az)
        {
            az = a[i];  // 更新 az
        }
    }

    // 初始化斐波那契数列
    f[1] = f[2] = 1;
    int m = 0;       // m 表示第一个 <= 1e6 的 f[i] 的位置
    for (i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2]; // 计算斐波那契数列
        if (f[i] > 1000000)
        {
            // 如果 f[i] 超过 1e6
            m = i - 1;              // 记录 m 的位置
            break;
        }
    }

    // 如果 m 没有改变，说明 f[n] <= 1e6，直接赋值为 n
    if (m == 0)
    {
        m = n;
    }

    // 统计 a[i] / f[i] 的出现次数
    for (i = 1; i <= m; i++)
    {
        if (a[i] % f[i] == 0)
        {
            // 如果 a[i] 能被 f[i] 整除
            bot[a[i] / f[i]]++;     // 统计 a[i] / f[i] 的出现次数
        }
    }

    // 找到 bot 数组中的最大值
    int maxc = -1;
    for (i = 1; i <= az; i++)
    {
        if (bot[i] > maxc)
        {
            maxc = bot[i];   // 更新 maxc
        }
    }

    printf("%d\n", n - maxc);

    return 0;
}
