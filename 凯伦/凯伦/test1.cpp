#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    int i = 0;
    // 计算 0 到 numsSize 的总和
    // for (i = 0; i <= numsSize; i++) 
    // {
    //     x += i;
    // }
    x = numsSize * (numsSize + 1) / 2;    // 使用等差数列求和公式
    for (i = 0; i < numsSize; i++)
    {
        x -= nums[i];
    }
    return x;
}

int main()
{
    int nums[] = { 0,2,3,4,5,6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);   // 计算数组的大小
    int ret = missingNumber(nums, numsSize);
    printf("%d\n", ret);

    return 0;
}
