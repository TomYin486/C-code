#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// �������� a �� sum ������С����ȷ���ܹ��洢�㹻�������
#define MAXN 200005

int n = 0;
int a[MAXN] = { 0 };   // �洢���������
long long sum[MAXN] = { 0 };   // ��������ǰ׺��
long long ans = 0;     // �����洢���յ�������˵ĺ�

int main()
{
    scanf("%d", &n);
    int i = 0;

    // ��ȡ�����ÿ���������洢������ a ����Ӧλ��
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        // ����ǰ׺�� sum[i]������ sum[i-1]��ǰһ��Ԫ�ص�ǰ׺�ͣ����ϵ�ǰԪ�� a[i]
        sum[i] = sum[i - 1] + a[i];
    }

    // ����������˵ĺ�
    for (i = 1; i <= n - 1; i++)
    {
        // ���� a[i] �����������������������ĳ˻�֮�ͣ���������ۼӵ� ans ��
        // sum[n] - sum[i] ��ʾ���� a[i] ������������ĺ�
        ans += a[i] * (sum[n] - sum[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
