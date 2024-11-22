#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 可以设计循环使其可以旋 1 次，然后让其执行 n 次

#include<string.h>  // 包含标准字符串处理库，以便使用 strlen函数计算字符串长度
void leftRound(char arr[], int len, int time)
{
	int i = 0;
	int j = 0;

	// 取 time 和字符串长度 len 的模，以避免 time 大于 len 的情况
	// 如：长度为 6 的情况下，旋转 7、13、19...次相当于 1 次，8、14、20...次相当于 2 次
	time %= len;

	// 执行 time 次的单次平移
	// 即循环 time 次，每次循环将字符串左旋 1 个字符
	for (i = 0; i < time; i++)
	{
		char tmp = arr[0];
		// 单次平移
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[j] = tmp;  // 也可以写成这样 arr[len - 1] = tmp;

	}
}
int main()
{
	char arr[] = "abcdef";
	int time = 0;   // 表示左旋次数
	scanf("%d", &time);
	int len = strlen(arr);   // 使用 strlen函数计算字符串 arr 的长度
	leftRound(arr, len, time);
	printf("%s", arr);
	return 0;
}
