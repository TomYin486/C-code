#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> // 包含 stdlib.h 头文件，可使用 malloc 和 free 等动态内存分配函数

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i = 0;
    for (i = 0; i < numsSize; ++i)
    {
        int j = 0;
        // 从当前外层循环元素的下一个元素开始，确保不会使用相同的元素两次
        for (j = i + 1; j < numsSize; j++)
        {
            // 检查当前外层循环的元素 nums[i] 和内层循环的元素 nums[j] 的和是否等于目标值 target
            if (nums[i] + nums[j] == target)
            {
                // 如果找到了这样的两个数，使用 malloc 分配一个大小为 2 的整数数组的内存空间，用于存储两个下标
                int* ret = (int*)malloc(sizeof(int) * 2);
                if (ret == NULL)
                {
                    // 如果内存分配失败
                    return NULL;
                }
                // 将找到的两个数的下标赋值给 ret 数组的两个元素
                ret[0] = i;
                ret[1] = j;

                // 将 returnSize 指向的值设置为 2，表示返回的数组中有两个元素
                *returnSize = 2;

                // 返回包含两个下标的数组
                return ret;
            }
        }
    }
    *returnSize = 0;

    // 返回 NULL，表示没有找到符合条件的两个数
    return NULL;
}

int main()
{
    int nums[] = { 1,2,3,4,5 };
    int target = 0;
    int returnSize = 0;
    scanf("%d", &target);
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int* ret = twoSum(nums, numsSize, target, &returnSize);
    if (ret != NULL)
    {
        printf("找到了，两个下标是:[%d,%d]\n", ret[0], ret[1]);
        free(ret);  // 释放ret指向的内存
    }
    else
    {
        printf("没有找到符合条件的两个数，或空间开辟失败\n");
    }
    return 0;
}
