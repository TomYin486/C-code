#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))  // ���ڷ����������еĽ�Сֵ

char S[1005], T[1005];   // ���ڱ�ʾ�����ַ������ַ�����
int dp[1005][1005];

int main()
{
    scanf("%s %s", S, T);
    int i = 0;
    int j = 0;

    // ls �� lt �ֱ��ʾ S �� T �ĳ���
    int ls = strlen(S);
    int lt = strlen(T);

    // ��ʼ�� dp ����
    for (i = 0; i <= ls; i++)
    {
        for (j = 0; j <= lt; j++)
        {
            // �� dp �����ʼ��Ϊһ���ܴ������0x3f3f3f3f��
            dp[i][j] = 0x3f3f3f3f;
        }
    }

    // �� T Ϊ���ַ���ʱ��dp[i][0] ����Ϊ0����Ϊ����Ҫ�κ��޸�
    for (i = 0; i <= ls; i++)
    {
        dp[i][0] = 0;
    }

    // ���ַ��� S �� T ���ַ�����ƶ�һλ�����ڿ�ͷ���һ���ո�
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

    // ��䶯̬�滮��
    for (i = 1; i <= ls; i++)
    {
        for (j = 1; j <= lt; j++)
        {
            if (S[i] == T[j])
            {
                // ����Ҫ�޸� S[i]
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // ����ѡ���޸� S[i] Ϊ T[j]���� dp[i][j] = dp[i-1][j-1] + 1
                // ����ѡ��ƥ�� T[j]���� dp[i][j] = dp[i - 1][j]
                // ȡ�������������Сֵ
                dp[i][j] = MIN(dp[i][j], MIN(dp[i - 1][j], dp[i - 1][j - 1] + 1));
            }
        }
    }

    printf("%d\n", dp[ls][lt]);
    return 0;
}
