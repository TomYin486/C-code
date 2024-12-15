#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 定义数组 a 和 sum 的最大大小，以确保能够存储足够多的整数
#define MAXN 200005

int n = 0;
int a[MAXN] = { 0 };   // 存储输入的整数
long long sum[MAXN] = { 0 };   // 用来计算前缀和
long long ans = 0;     // 用来存储最终的两两相乘的和

int main()
{
    scanf("%d", &n);
    int i = 0;

    // 读取输入的每个整数并存储在数组 a 的相应位置
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        // 计算前缀和 sum[i]，它是 sum[i-1]（前一个元素的前缀和）加上当前元素 a[i]
        sum[i] = sum[i - 1] + a[i];
    }

    // 计算两两相乘的和
    for (i = 1; i <= n - 1; i++)
    {
        // 计算 a[i] 与除了它以外的所有其他数的乘积之和，并将结果累加到 ans 中
        // sum[n] - sum[i] 表示除了 a[i] 以外的所有数的和
        ans += a[i] * (sum[n] - sum[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
