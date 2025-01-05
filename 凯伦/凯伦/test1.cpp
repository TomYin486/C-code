#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 比较函数，用于 qsort
int compare(const void* a, const void* b)
{
	// 从小到大排序
	return (*(char*)a - *(char*)b);
}

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d %d", &n, &m);

	char a[n + 1]; // 原始字符串
	char b[m + 1]; // 待插入的字符
	scanf("%s", a);
	scanf("%s", b);

	// 对字符数组 b 进行从小到大的排序，确保在合并时能够优先插入较小的字符，从而得到字典序最小的结果
	qsort(b, m, sizeof(char), compare);

	// 合并字符串 a 和字符数组 b(不包含 '\0')
	char result[n + m + 1];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n && j < m)
	{
		// 确保每次选择较小的字符放入结果中
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

	// 将剩余的字符添加到结果中
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

	result[k] = '\0';  // 注意要添加字符串结束符'\0'

	// 打印结果
	printf("%s\n", result);

	return 0;
}
