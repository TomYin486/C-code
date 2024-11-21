#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//  char类型指针 str，指向要反转的字符串的起始位置，sz 表示字符串的长度
void reverse_string(char* str, int sz)
{
	// 指针left 指向字符串的起始位置
	char* left = str;

	// 指针right，指向字符串的最后一个字符的位置(即 str + sz - 1,减去 1 是因为数组索引是从 0 开始的)
	char* right = str + sz - 1;

	// 对字符串的中间部分进行交换操作，直到两个指针相遇
	while (left < right)
	{
		// 交换两个指针 left 和 right 所指向的字符
		char tmp = *right;
		*right = *left;
		*left = tmp;

		// 指针left 向后移动一个字符
		left++;
		// 指针right 向前移动一个字符
		right--;
	}
}

#include<string.h>
int main()
{

	char arr[] = "abcdef";
	int sz = strlen(arr);     // 计算字符串 arr 的长度
	reverse_string(arr, sz);
	printf("%s", arr);

	return 0;
}
