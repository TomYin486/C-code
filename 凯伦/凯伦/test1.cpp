#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    int i = 0;
    // ���� 0 �� numsSize ���ܺ�
    // for (i = 0; i <= numsSize; i++) 
    // {
    //     x += i;
    // }
    x = numsSize * (numsSize + 1) / 2;    // ʹ�õȲ�������͹�ʽ
    for (i = 0; i < numsSize; i++)
    {
        x -= nums[i];
    }
    return x;
}

int main()
{
    int nums[] = { 0,2,3,4,5,6 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);   // ��������Ĵ�С
    int ret = missingNumber(nums, numsSize);
    printf("%d\n", ret);

    return 0;
}
