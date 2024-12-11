#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdbool.h> // ������׼�������Ϳ⣬�ṩ bool ����
#include<string.h>  // �����ַ�������⣬�ṩ strlen �Ⱥ���
#include<ctype.h>   // �����ַ����ʹ���⣬�ṩ isdigit��isalpha��tolower �Ⱥ���

bool isPalindrome(char* s)
{
	// ��ʼ����ָ�� left Ϊ 0��ָ���ַ����Ŀ�ʼλ��
	int left = 0;

	// ��ʼ����ָ�� right Ϊ�ַ������ȼ� 1��ָ���ַ����Ľ���λ��
	int right = strlen(s) - 1;

	// ����ָ��С����ָ��ʱ
	while (left < right)
	{
		// ��ָ��С����ָ�룬�ҵ�ǰ�ַ��Ȳ�������Ҳ������ĸ����ָ�������ƶ�
		while (left < right && !(isdigit(s[left]) || isalpha(s[left])))
		{
			left++;
		}

		// ��ָ��С����ָ�룬�ҵ�ǰ�ַ��Ȳ�������Ҳ������ĸ����ָ�������ƶ�
		while (left < right && !(isdigit(s[right]) || isalpha(s[right])))
		{
			right--;
		}

		// ������ָ����ָ���ַ���ת��ΪСд��Ƚ�
		if (tolower(s[left]) != tolower(s[right]))
		{
			// �������ȣ����� false����ʾ���ǻ��Ĵ�
			return false;
		}

		left++;
		right--;
	}
	// ��������ַ�����������û�в�ƥ������������ true����ʾ�ǻ��Ĵ�
	return true;
}

int main()
{
	char s1[] = "A man, a plan, a canal: Panama";
	printf("%d\n", isPalindrome(s1));

	char s2[] = "race a car";
	printf("%d\n", isPalindrome(s2));

	return 0;
}
