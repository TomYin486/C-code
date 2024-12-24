#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int func1(int x)
{
	// 用于表示当前检查的位数（奇数位或偶数位）
	int i = 1;
	while (x)
	{
		// 如果 i 为奇数位
		if (i % 2 == 1)
		{
			// 如果 x 的当前最低位是偶数，则 x 不是好数，函数返回 0
			if ((x % 10) % 2 == 0)
			{
				return 0;
			}
		}
		// 如果 i 为偶数位
		else
		{
			// 如果 x 的当前最低位是奇数，则 x 不是好数，函数返回 0
			if ((x % 10) % 2 == 1)
			{
				return 0;
			}
		}

		x /= 10;   // 将 x 除以 10，去掉当前最低位，检查下一位
		i++;       // 计数器 i 加 1
	}
	return 1;
}

int main()
{
	int i = 0;
	int n = 0;
	int count = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		// 如果 func1 函数返回 1，说明 i 是一个好数
		if (func1(i) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}
