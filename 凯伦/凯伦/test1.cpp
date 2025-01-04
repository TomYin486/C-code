#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))  // 用于返回两个数中的较小值

char S[1005], T[1005];   // 用于表示输入字符串的字符数组
int dp[1005][1005];

int main()
{
    scanf("%s %s", S, T);
    int i = 0;
    int j = 0;

    // ls 和 lt 分别表示 S 和 T 的长度
    int ls = strlen(S);
    int lt = strlen(T);

    // 初始化 dp 数组
    for (i = 0; i <= ls; i++)
    {
        for (j = 0; j <= lt; j++)
        {
            // 将 dp 数组初始化为一个很大的数（0x3f3f3f3f）
            dp[i][j] = 0x3f3f3f3f;
        }
    }

    // 当 T 为空字符串时，dp[i][0] 设置为0，因为不需要任何修改
    for (i = 0; i <= ls; i++)
    {
        dp[i][0] = 0;
    }

    // 将字符串 S 和 T 的字符向后移动一位，并在开头添加一个空格
    for (i = ls; i >= 1; i--)
    {
        S[i] = S[i - 1];
    }
    S[0] = ' ';

    for (i = lt; i >= 1; i--)
    {
        T[i] = T[i - 1];
    }
    T[0] = ' ';

    // 填充动态规划表
    for (i = 1; i <= ls; i++)
    {
        for (j = 1; j <= lt; j++)
        {
            if (S[i] == T[j])
            {
                // 不需要修改 S[i]
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // 可以选择修改 S[i] 为 T[j]，则 dp[i][j] = dp[i-1][j-1] + 1
                // 或者选择不匹配 T[j]，则 dp[i][j] = dp[i - 1][j]
                // 取这两种情况的最小值
                dp[i][j] = MIN(dp[i][j], MIN(dp[i - 1][j], dp[i - 1][j - 1] + 1));
            }
        }
    }

    printf("%d\n", dp[ls][lt]);
    return 0;
}
