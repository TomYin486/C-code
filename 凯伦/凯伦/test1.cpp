#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 所有大于 2 的偶数都是合数，当 1 + 3 > 2 时，任何两个具有相同奇偶性的数相加都会得到一个合数
// 现在需要找到一个奇数和一个偶数，让它们的和是一个合数
// 可以验证在 n <= 4 时不存在这样的数对，但在 n = 5 ，存在 4 和 5，它们的和为 9，是合数

int main()
{
    int t = 0;
    int n = 0;
    int i = 0;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        if (n < 5)
        {
            printf("-1\n");
            continue;
        }

        // 输出所有偶数，除了 4
        for (i = 2; i <= n; i += 2)
        {
            if (i != 4)
            {
                printf("%d ", i);
            }
        }

        // 输出 4 和 5
        printf("4 5 ");

        // 输出所有奇数，除了 5
        for (i = 1; i <= n; i += 2)
        {
            if (i != 5)
            {
                printf("%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}
