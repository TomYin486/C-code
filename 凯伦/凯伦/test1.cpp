#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func1(int x)
{
	// ���ڱ�ʾ��ǰ����λ��������λ��ż��λ��
	int i = 1;
	while (x)
	{
		// ��� i Ϊ����λ
		if (i % 2 == 1)
		{
			// ��� x �ĵ�ǰ���λ��ż������ x ���Ǻ������������� 0
			if ((x % 10) % 2 == 0)
			{
				return 0;
			}
		}
		// ��� i Ϊż��λ
		else
		{
			// ��� x �ĵ�ǰ���λ���������� x ���Ǻ������������� 0
			if ((x % 10) % 2 == 1)
			{
				return 0;
			}
		}

		x /= 10;   // �� x ���� 10��ȥ����ǰ���λ�������һλ
		i++;       // ������ i �� 1
	}
	return 1;
}

int main()
{
	int i = 0;
	int n = 0;
	int count = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		// ��� func1 �������� 1��˵�� i ��һ������
		if (func1(i) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}
