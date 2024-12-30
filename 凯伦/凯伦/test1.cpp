#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000   // ��ʾ���������С
#define MAXA 1000000  // ��ʾ a[i] �����ֵ

long long f[MAXN];    // ���� f ���ڴ���쳲���������
long long a[MAXN];    // ���� a ���ڴ����������������
int bot[MAXA];        // ���� bot ����ͳ�� a[i] / f[i] �ĳ��ִ���

int main()
{
    int n = 0;           // ��ʾ������������еĳ���
    scanf("%d", &n);

    long long az = -1;   // az ���ڼ�¼ a[i] �����ֵ
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] > az)
        {
            az = a[i];  // ���� az
        }
    }

    // ��ʼ��쳲���������
    f[1] = f[2] = 1;
    int m = 0;       // m ��ʾ��һ�� <= 1e6 �� f[i] ��λ��
    for (i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2]; // ����쳲���������
        if (f[i] > 1000000)
        {
            // ��� f[i] ���� 1e6
            m = i - 1;              // ��¼ m ��λ��
            break;
        }
    }

    // ��� m û�иı䣬˵�� f[n] <= 1e6��ֱ�Ӹ�ֵΪ n
    if (m == 0)
    {
        m = n;
    }

    // ͳ�� a[i] / f[i] �ĳ��ִ���
    for (i = 1; i <= m; i++)
    {
        if (a[i] % f[i] == 0)
        {
            // ��� a[i] �ܱ� f[i] ����
            bot[a[i] / f[i]]++;     // ͳ�� a[i] / f[i] �ĳ��ִ���
        }
    }

    // �ҵ� bot �����е����ֵ
    int maxc = -1;
    for (i = 1; i <= az; i++)
    {
        if (bot[i] > maxc)
        {
            maxc = bot[i];   // ���� maxc
        }
    }

    printf("%d\n", n - maxc);

    return 0;
}
