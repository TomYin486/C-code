#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <string.h>
int main()
{
	char str[1001];    // ����������ַ���������1000���ַ�
	scanf("%s", str);

	// i ���ڱ���������ַ�����j ���ڱ��������� "alan"
	int i = 0;
	int j = 0;

	// һ���ַ�ָ�� subseq��ָ���ַ������� "alan"������Ҫ�������ַ����в��ҵ�������
	char* subseq = "alan";

	// i С�������ַ����ĳ����� j С�������еĳ��ȣ�ȷ�����������ַ�������Ч��Χ�ڽ��бȽ�
	while (i < strlen(str) && j < strlen(subseq))
	{
		// ����ҵ�ƥ����ַ����ƶ������е�ָ��
		if (str[i] == subseq[j])
		{
			j++; // �ƶ������е�ָ��
		}
		i++; // �ƶ��ַ�����ָ��
	}

	// ��� j �Ƿ���������еĳ��ȣ�����ǣ�������Ѿ��ҵ���������������
	if (j == strlen(subseq))
	{
		printf("YES\n"); // �ҵ���������������
	}
	else
	{
		printf("NO\n"); // û���ҵ�������������
	}
	return 0;
}
