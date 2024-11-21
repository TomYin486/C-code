#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//  char����ָ�� str��ָ��Ҫ��ת���ַ�������ʼλ�ã�sz ��ʾ�ַ����ĳ���
void reverse_string(char* str, int sz)
{
	// ָ��left ָ���ַ�������ʼλ��
	char* left = str;

	// ָ��right��ָ���ַ��������һ���ַ���λ��(�� str + sz - 1,��ȥ 1 ����Ϊ���������Ǵ� 0 ��ʼ��)
	char* right = str + sz - 1;

	// ���ַ������м䲿�ֽ��н���������ֱ������ָ������
	while (left < right)
	{
		// ��������ָ�� left �� right ��ָ����ַ�
		char tmp = *right;
		*right = *left;
		*left = tmp;

		// ָ��left ����ƶ�һ���ַ�
		left++;
		// ָ��right ��ǰ�ƶ�һ���ַ�
		right--;
	}
}

#include<string.h>
int main()
{

	char arr[] = "abcdef";
	int sz = strlen(arr);     // �����ַ��� arr �ĳ���
	reverse_string(arr, sz);
	printf("%s", arr);

	return 0;
}
