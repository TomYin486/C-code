#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<stdbool.h> // 包含标准布尔类型库，提供 bool 类型
#include<string.h>  // 包含字符串处理库，提供 strlen 等函数
#include<ctype.h>   // 包含字符类型处理库，提供 isdigit、isalpha、tolower 等函数

bool isPalindrome(char* s)
{
	// 初始化左指针 left 为 0，指向字符串的开始位置
	int left = 0;

	// 初始化右指针 right 为字符串长度减 1，指向字符串的结束位置
	int right = strlen(s) - 1;

	// 当左指针小于右指针时
	while (left < right)
	{
		// 左指针小于右指针，且当前字符既不是数字也不是字母，左指针向右移动
		while (left < right && !(isdigit(s[left]) || isalpha(s[left])))
		{
			left++;
		}

		// 左指针小于右指针，且当前字符既不是数字也不是字母，右指针向左移动
		while (left < right && !(isdigit(s[right]) || isalpha(s[right])))
		{
			right--;
		}

		// 将左右指针所指的字符都转换为小写后比较
		if (tolower(s[left]) != tolower(s[right]))
		{
			// 如果不相等，返回 false，表示不是回文串
			return false;
		}

		left++;
		right--;
	}
	// 如果所有字符都检查完毕且没有不匹配的情况，返回 true，表示是回文串
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
