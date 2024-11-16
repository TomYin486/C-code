#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i = 0;
	int n = 0;
	scanf("%d", &n);
	int flag = 0;     // 用 flag 标记是否找到了符合条件的数
	for (i = 10000; i <= 30000; i++)
	{
		// (i / 100)实际上获取的是 i 的前 3 位数（即sub1）
		if ((i / 100) % n == 0)
		{
			// 比如：i 为 12345，12345 / 10000 * 1000 = 1000，i / 10 = 1234，则 1234 - 1000 = 234，得到的结果是 sub2
			if ((i / 10 - i / 10000 * 1000) % n == 0)
			{
				// 通过(i - i / 1000 * 1000)直接得到 i 的后 3 位数，即 sub3
				if ((i - i / 1000 * 1000) % n == 0)
				{
					printf("%d\n", i);
					// 如果所有条件都满足，打印出这个数 i，并将 flag 设置为 1，表示找到了至少一个符合条件的数
					flag = 1;
				}
			}
		}

	}

	if (flag == 0)
	{
		printf("No\n");
	}

	return 0;
}

