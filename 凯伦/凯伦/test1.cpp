#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int waysToStep(int n)
{
	// count 用于在循环中计数，从 3 开始，因为至少需要走 3 步才能开始计算
	int count = 3;

	// 存储到达每一级台阶的不同方式的数量
	// arr[0]，arr[1]，arr[2] 分别表示到达前一阶、前两阶和前三阶台阶的不同方式的数量
	int arr[4] = { 0 };
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;

	if (n <= 2)
	{
		return n;
	}
	else if (n == 3)
	{
		return 4;
	}

	// 直到 count 等于 n，即到达最后一阶台阶
	while (count < n)
	{
		// 将到达前 3 个台阶的方式数量相加并取模，以避免结果过大
		arr[3] = (arr[0] + arr[1]) % 1000000007 + arr[2];  // 计算到达第 count 阶的方式数量
		arr[3] %= 1000000007;     // 取模以避免溢出

		/// 将 arr[0], arr[1], arr[2] 的值向前移动
		arr[0] = arr[1];
		arr[1] = arr[2];
		arr[2] = arr[3];

		// 移动到下一阶
		count++;
	}
	// 返回数组中最后 1 个元素的值，即到达第 n 阶台阶的不同方式的数量
	return arr[3];
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = waysToStep(n);
	printf("%d\n", ret);

	return 0;
}
