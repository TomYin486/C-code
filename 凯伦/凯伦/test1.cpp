#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <stdbool.h>
#include <string.h>

// haystack �� needle 2 ��������Ϊ���ַ�ָ�룬�ֱ�ָ��Ҫ�������ַ�����Ҫ���ҵ��Ӵ�
// ��������һ����������ʾ�Ӵ����ַ����е�λ��
int strStr(char* haystack, char* needle)
{
    // ���� haystack �� needle �ַ����ĳ���
    int n = strlen(haystack);
    int m = strlen(needle);

    // ��� needle �ĳ���Ϊ 0(���ַ���)�����ַ������κ��ַ������Ӵ����������� 0
    if (m == 0)
    {
        return 0;
    }
    // ��� needle �ĳ��ȴ��� haystack �ĳ��ȣ��������� haystack ���ҵ��������������Ӵ����������� -1
    if (m > n)
    {
        return -1;
    }
    int i = 0;

    // ��ǵ�ǰ�����Ӵ��Ƿ��� needle ƥ��
    bool flag = true;

    // �� haystack �ĵ� 0 λ���ַ���ʼ��ÿ�μ� 1��ֱ�� i + m (����λ�ü��� needle �ĳ���)������ haystack �ĳ��� n
    for (i = 0; i + m <= n; i++)
    {
        // flag ����Ϊ true�������µ�ƥ����
        flag = true;
        // ����ַ��Ƚ� haystack �д�λ�� i ��ʼ���Ӵ��� needle
        for (int j = 0; j < m; j++)
        {
            // ��� haystack �еĵ�ǰ�ַ��� needle �еĶ�Ӧ�ַ���ƥ�䣬�� flag ����Ϊ false �������ڲ�ѭ��
            if (haystack[i + j] != needle[j])
            {
                flag = false;
                break;
            }
        }
        // ��� flag ��ȻΪ true�����ҵ���ƥ����Ӵ����������ص�ǰ����ʼλ�� i
        if (flag)
        {
            return i;
        }
    }
    // ���ѭ��������û���ҵ�ƥ����Ӵ����������� -1
    return -1;
}

int main()
{
    char haystack1[] = "abc";
    char needle1[] = "abcd";
    int ret1 = strStr(haystack1, needle1);
    printf("%d\n", ret1);

    char haystack2[] = "ccabcd";
    char needle2[] = "ab";
    int ret2 = strStr(haystack2, needle2);
    printf("%d\n", ret2);
    return 0;
}
