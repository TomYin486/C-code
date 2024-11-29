#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 接受 3 个参数：整数数组 nums 的指针，数组的大小 numsSize，以及要查找的目标值 target
int searchInsert(int* nums, int numsSize, int target)
{
    // left 和 right，分是数组的起始位置和结束位置的下标
    int left = 0;
    int right = numsSize - 1;

    // 用于表示 target 应该插入的位置，如果 target 比数组中的所有元素都大，ans 将保持为 numsSize
    int ans = numsSize;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        // 如果 target 小于或等于中间下标处的值，更新 ans 为 mid，并调整 right 为 mid - 1
        // 这样下一次循环只会在数组的左半部分查找
        if (target <= nums[mid])
        {
            ans = mid;
            right = mid - 1;

        }
        // 如果 target 大于中间下标处的值，调整 left 为 mid + 1
        // 这样下一次循环只会在数组的右半部分查找
        else
        {
            left = mid + 1;
        }
    }
    // 表示 target 应该插入的位置
    return ans;
}


int main()
{
    int nums[] = { -1,0,1,2,3,4 };
    int target = 0;
    scanf("%d", &target);
    int numsSize = sizeof(nums) / sizeof(nums[0]);   // 计算数组 nums 的大小
    int ret = searchInsert(nums, numsSize, target);

    // 打印目标值(target)在数组中的下标，或者它应该被插入的位置
    printf("%d\n", ret);

    return 0;
}
