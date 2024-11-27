#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

// ���� reverse_part�������ַ�ָ��src��ָ���ַ�������ʼλ�ã�������start������ʼ��λ�ã�������end�����������λ�ã�
// ���ַ����� start �� end ��һ������
void reverse_part(char* src, int start, int end)
{
	int i = 0;
	int j = 0;

	for (i = start, j = end; i < j; i++, j--)
	{
		char tmp = src[i];
		src[i] = src[j];
		src[j] = tmp;

	}

}

// ���磺���� 3 ���ַ��� ABCDEFG�����Ϊ DEFGABC
// �Ƚ�Ҫ������ǰ 3 ���ַ�������CBADEFG����Ȼ�󽫺���Ҳ����CBAGFED���������������DEFGABC������
// ����ֻ��Ҫ����ֵ�������ɣ�����д��������������ɾֲ�����


int main()
{
	int time = 0;
	char arr[] = "ABCD";
	scanf("%d", &time);

	int len = strlen(arr);
	int pos = time % len;

	reverse_part(arr, 0, pos - 1);   //����ǰ��,���ַ��� arr ���±� 0 �� pos - 1 ���Ӵ�����
	reverse_part(arr, pos, len - 1); //�����Σ����ַ��� arr ���±� pos �� len - 1 ���Ӵ�����
	reverse_part(arr, 0, len - 1);   //��������
	printf("%s", arr);

	return 0;
}
