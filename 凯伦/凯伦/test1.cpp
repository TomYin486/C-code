#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int a[1000];    // ���� a ���ڴ洢���ֵ�ÿһλ
int B = 2;      // B �ǳ�������������Ϊ 2
int n = 0;      // n ������ a ���Ѿ��洢�����ֵ�λ��

// ���ڽ����� a �е����ֳ��� 2
void gj(int a[], int len)
{
    int i = 0;
    int t = 0; // ���ڴ洢��λ
    for (i = 0; i < len; i++)
    {
        // ������ a �ĵ�ǰλ���� B��2�����ټ���֮ǰ����Ľ�λ t
        a[i] = (a[i] * B) + t;

        // �����µĽ�λ���õ�ǰλ���� B ���Ͻ�λ����� 10 ����
        t = a[i] / 10;

        // �������� a �ĵ�ǰλ������ȡ����
        a[i] %= 10;
    }
    // ����н�λ���򽫽�λֵ�洢������ a ����һλ
    if (t != 0)
    {
        a[len] = t;
        n++;
    }
}

int main()
{
    int i = 0;
    int N = 0;        // N ��ʾΪ��Ҫ���ԵĴ���
    scanf("%d", &N);
    char str[1000];   // ���ڴ洢�������ַ�������
    scanf("%s", str);

    int flag = 0;     // ���ڱ��С�����λ��
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == '.')
        {
            // ��¼С�����λ��
            flag = strlen(str) - 1 - i;
            continue;
        }
        else
        {
            // ���ַ�ת��Ϊ��Ӧ������ֵ�����洢������ a �У�Ȼ������ n
            a[n] = (str[i] - '0');
            n++;
        }
    }

    while (N--)
    {
        // ִ�г˷�����
        gj(a, n);
    }

    // �ж��Ƿ���Ҫ������������
    if (a[flag - 1] >= 5)
    {
        int t = 1; // ĩβ +1��ע�� i = flag
        for (i = flag; i < n; i++)
        {
            // ������ a ��ÿһλ�� 1 ���������λ
            a[i] = a[i] + t;
            t = a[i] / 10;
            a[i] %= 10;
        }
        // �������н�λ��������ӵ����� a ��ĩβ�������� n
        if (t != 0)
        {
            a[n] = t;
            n++;
        }
    }

    // ֱ�Ӵ�ӡ
    for (i = n - 1; i >= flag; i--)
    {
        printf("%d", a[i]);
    }
    return 0;
}
