#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <string.h>
int main()
{
	char str[1001];    // 假设输入的字符串不超过1000个字符
	scanf("%s", str);

	// i 用于遍历输入的字符串，j 用于遍历子序列 "alan"
	int i = 0;
	int j = 0;

	// 一个字符指针 subseq，指向字符串常量 "alan"，这是要在输入字符串中查找的子序列
	char* subseq = "alan";

	// i 小于输入字符串的长度且 j 小于子序列的长度，确保了在两个字符串的有效范围内进行比较
	while (i < strlen(str) && j < strlen(subseq))
	{
		// 如果找到匹配的字符，移动子序列的指针
		if (str[i] == subseq[j])
		{
			j++; // 移动子序列的指针
		}
		i++; // 移动字符串的指针
	}

	// 检查 j 是否等于子序列的长度，如果是，这表明已经找到了完整的子序列
	if (j == strlen(subseq))
	{
		printf("YES\n"); // 找到了完整的子序列
	}
	else
	{
		printf("NO\n"); // 没有找到完整的子序列
	}
	return 0;
}
