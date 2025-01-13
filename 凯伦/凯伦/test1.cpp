#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 使用 ^ 可防止数据太大而溢出（如计算 (n+1) * n / 2）
// 异或操作的特点: 
// 1.任何数和 0 异或，结果仍然是原来的数
// 2.任何数和自身异或，结果是 0
// 3.异或操作满足交换律和结合律

int missingNumber(int* nums, int numsSize)
{
	int x = 0;       // x 用于表示异或结果
	int n = numsSize;
	int i = 0;

	// 对 0 到 n 的所有整数进行异或操作，得到一个中间结果。这个结果相当于 0 到 n 的所有整数的异或和
	for (i = 0; i <= n; i++)
	{
		x ^= i;
	}

	// 对数组中的每个元素进行异或操作
	// 由于数组中的元素是 0 到 n 中缺失一个整数的集合，异或操作会将重复的数抵消掉，最终剩下的就是缺失的整数
	for (i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	return x;

	// 也可以简化
	/*int x = 0;
	for (int i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
		x ^= i;
	}
	x ^= numsSize;
	return x;*/
}

int main()
{
	int nums[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);   // 计算数组的大小
	int ret = missingNumber(nums, numsSize);
	printf("%d\n", ret);
	return 0;
}
