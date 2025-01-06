#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100005   // ��ʾ���������С

int main()
{
    // n��m �ֱ��ʾ��������ĳ���
    int n = 0;
    int m = 0;

    // a��b ���ڱ�ʾ�������������
    int a[MAX_SIZE];
    int b[MAX_SIZE];

    // front1��front2 ���ڱ�ʾ��������ĵ�ǰ����λ�ã����е�ǰ�ˣ�
    int front1 = 0;
    int front2 = 0;

    // rear1��rear2 ���ڱ�ʾ���������ĩβλ�ã����еĺ�ˣ�
    int rear1;
    int rear2;

    // sum ��ʾ�ϲ������Ĵ���
    long long sum = 0;

    scanf("%d %d", &n, &m);

    rear1 = n;    // ��ʾ a �����ĩβλ��
    rear2 = m;    // ��ʾ b �����ĩβλ��

    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    // ͨ���ϲ�����ʹ���� a �� b �����ȫ��ͬ
    while (front1 < rear1 && front2 < rear2)
    {
        // ��� a �� b ��ǰ�����Ԫ����ȣ���ֱ���ƶ�����һ��Ԫ��
        if (a[front1] == b[front2])
        {
            front1++;
            front2++;
        }
        // ��� a ��ǰԪ�ش��� b ��ǰԪ�أ��� b ��ǰԪ������һ��Ԫ�غϲ��������Ӻϲ�����
        else if (a[front1] > b[front2])
        {
            a[front2 + 1] += b[front2];
            front2++;
            sum++;
        }
        // ��� a ��ǰԪ��С�� b ��ǰԪ�أ��� a ��ǰԪ������һ��Ԫ�غϲ��������Ӻϲ�����
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
