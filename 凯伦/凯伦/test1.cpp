#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005   // 表示数组的最大大小

int main()
{
    // n，m 分别表示两个数组的长度
    int n = 0;
    int m = 0;

    // a，b 用于表示输入的两个数组
    int a[MAX_SIZE];
    int b[MAX_SIZE];

    // front1，front2 用于表示两个数组的当前处理位置（队列的前端）
    int front1 = 0;
    int front2 = 0;

    // rear1，rear2 用于表示两个数组的末尾位置（队列的后端）
    int rear1;
    int rear2;

    // sum 表示合并操作的次数
    long long sum = 0;

    scanf("%d %d", &n, &m);

    rear1 = n;    // 表示 a 数组的末尾位置
    rear2 = m;    // 表示 b 数组的末尾位置

    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    // 通过合并操作使数组 a 和 b 变得完全相同
    while (front1 < rear1 && front2 < rear2)
    {
        // 如果 a 和 b 当前处理的元素相等，则直接移动到下一个元素
        if (a[front1] == b[front2])
        {
            front1++;
            front2++;
        }
        // 如果 a 当前元素大于 b 当前元素，则将 b 当前元素与下一个元素合并，并增加合并次数
        else if (a[front1] > b[front2])
        {
            a[front2 + 1] += b[front2];
            front2++;
            sum++;
        }
        // 如果 a 当前元素小于 b 当前元素，则将 a 当前元素与下一个元素合并，并增加合并次数
        else
        {
            a[front1 + 1] += a[front1];
            front1++;
            sum++;
        }
    }

    printf("%lld\n", sum);
    return 0;
}
