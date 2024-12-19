#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	long long a = 0;
	long long b = 0;
	long long n = 0;
	scanf("%lld %lld %lld", &a, &b, &n);

	// 计算一周内做题的总数
	long long s = 5 * a + 2 * b;

	// 计算在完成若干周的题目后，还剩下多少题目没有做
	long long s1 = n % s;

	// 使用整数除法 / 来得到完整的周数
	long long s2 = n / s;

	// 检查剩余的题目数 s1 是否能在一周的工作日内完成
	if (s1 <= 5 * a)
	{
		// 如果剩余题目可以在工作日内完成，则打印完成题目所需的总天数
		// s2 * 7 表示已经完成的周数对应的天数，(s1 + a - 1) / a 表示剩余题目需要的工作日天数
		printf("%lld\n", s2 * 7 + (s1 + a - 1) / a);
	}
	// 处理剩余题目数超过工作日能完成的情况
	else
	{
		// s2 * 7 + 5 表示已经完成的周数对应的天数加上 5 个工作日，(s1 - 5 * a + b - 1) / b 表示剩余题目需要的周末天数
		printf("%lld\n", s2 * 7 + 5 + (s1 - 5 * a + b - 1) / b);
	}

	return 0;
}
