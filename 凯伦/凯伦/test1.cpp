#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ȽϺ��������� qsort
int compare(const void* a, const void* b)
{
	// ��С��������
	return (*(char*)a - *(char*)b);
}

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);

	char a[n + 1]; // ԭʼ�ַ���
	char b[m + 1]; // ��������ַ�
	scanf("%s", a);
	scanf("%s", b);

	// ���ַ����� b ���д�С���������ȷ���ںϲ�ʱ�ܹ����Ȳ����С���ַ����Ӷ��õ��ֵ�����С�Ľ��
	qsort(b, m, sizeof(char), compare);

	// �ϲ��ַ��� a ���ַ����� b(������ '\0')
	char result[n + m + 1];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n && j < m)
	{
		// ȷ��ÿ��ѡ���С���ַ���������
		if (a[i] <= b[j])
		{
			result[k] = a[i];
			k++;
			i++;
		}
		else
		{
			result[k] = b[j];
			k++;
			j++;
		}
	}

	// ��ʣ����ַ���ӵ������
	while (i < n)
	{
		result[k] = a[i];
		k++;
		i++;
	}
	while (j < m)
	{
		result[k] = b[j];
		k++;
		j++;
	}

	result[k] = '\0';  // ע��Ҫ����ַ���������'\0'

	// ��ӡ���
	printf("%s\n", result);

	return 0;
}
