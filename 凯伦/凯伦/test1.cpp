#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// t 表示测试数据的组数，n 表示每组数据中飞机的数量，bk 为一个布尔数组，用于标记飞机是否已经被安排降落
int t = 0;
int n = 0;
int bk[15] = { 0 };

// 结构体 plane 包含 t（到达时间）、d（盘旋时间）和 l（降落时间）
struct plane {
    int t;
    int d;
    int l;

} a[15];  // 数组 a 中的元素为该结构体类型，用于存储每架飞机的信息

// dep 表示当前处理的飞机编号（从 1 开始），tim 表示当前的时间
int dfs(int dep, int tim)
{
    int i = 0;

    // 如果 dep 大于飞机总数 n，说明所有飞机都已处理完毕，则返回 1 表示成功
    if (dep > n)
    {
        return 1;
    }

    // 遍历所有飞机
    for (i = 1; i <= n; i++)
    {
        // 如果飞机 i 已经被标记为处理过（bk[i] 为真）或者飞机 i 的 t（到达时间）加 d（上盘旋时间）小于当前时间 tim（即飞机已经无法降落），则跳过这架飞机
        if (bk[i] || a[i].t + a[i].d < tim) // 降落条件
            continue;
        bk[i] = 1;

        // 计算飞机 i 降落结束后的时间 next_tim，取 tim 和飞机 i 的到达时间 a[i].t 中的较大值
        int next_tim = (tim > a[i].t) ? tim : a[i].t;

        // 更新 next_tim（为飞机 i 降落结束后的时间）
        next_tim += a[i].l;

        // 递归调用 dfs 函数处理下一架飞机，如果成功，则将当前飞机标记为未处理，并返回 1
        if (dfs(dep + 1, next_tim))
        {
            bk[i] = 0;
            return 1; // 有一个成功就返回1
        }
        // 如果当前飞机无法降落，则将其标记为未处理，并继续尝试其他飞机
        bk[i] = 0;
    }
    // 如果所有飞机都尝试过后都无法降落，则返回 0 表示失败
    return 0;
}

int main()
{
    scanf("%d", &t);    // t 为测试数据的组数 
    while (t)
    {
        scanf("%d", &n);  // n 为飞机的数量

        int i = 0;
        // 输入每架飞机的 t（到达时间）、d（盘旋时间）和 l（降落时间）
        for (i = 1; i <= n; i++)
        {
            scanf("%d %d %d", &a[i].t, &a[i].d, &a[i].l);
        }

        // 清空 bk 数组，为新的一组数据做准备
        memset(bk, 0, sizeof(bk));

        if (dfs(1, 0))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        t--;
    }
    return 0;
}
