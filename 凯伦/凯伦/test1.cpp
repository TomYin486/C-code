#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ��ʮ������ת��Ϊ n ������
void func1(int num, int base)
{
    // ���������㹻�󣬿��Դ洢ת���������
    char result[100];
    int index = 0;

    // �������Ϊ 0��ֱ�ӷ���
    if (num == 0)
    {
        printf("0");
        return;
    }


    while (num > 0)
    {
        // ȡ����
        int remainder = num % base;

        if (remainder < 10)
        {
            // ת��Ϊ�ַ����洢
            result[index++] = '0' + remainder;
        }
        else
        {
            // ʹ�ô�д��ĸ��ʾ 10 ���ϵ�����
            result[index++] = 'A' + remainder - 10;
        }
        // ���� num Ϊ num/base ����������
        num /= base;
    }

    int i = 0;
    // ����Ƿ���洢�ģ�Ҫ�����ӡ
    for (i = index - 1; i >= 0; i--)
    {
        printf("%c", result[i]);
    }
}

int main()
{
    int i = 0;
    int j = 0;
    int n = 0;
    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            int product = i * j;
            func1(i, n);   // �����һ������
            printf("*");
            func1(j, n);   // ����ڶ�������
            printf("=");
            func1(product, n); // ����˻�
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}
