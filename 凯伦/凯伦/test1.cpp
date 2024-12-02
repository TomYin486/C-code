#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 接受 3 个参数，整数数组 nums 的指针，数组的大小 numsSize，以及一个要移除的值 val
int removeElement(int* nums, int numsSize, int val)
{
    // 用作数组中不等于 val 的元素的下标
    int left = 0;

    // right 用于遍历数组中的每个元素
    for (int right = 0; right < numsSize; right++)
    {
        // 检查当前 right 下标处的元素是否不等于 val
        if (nums[right] != val)
        {
            // 如果当前元素不等于 val，则将其复制到 left 下标处
            // 这样可以让所有不等于 val 的元素都会被移动到数组的前部
            nums[left] = nums[right];
            left++;
        }
    }
    // 返回 left 的值，即数组中不等于 val 的元素的数量
    return left;
}

int main()
{
    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int val = 0;
    scanf("%d", &val);
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ret = removeElement(nums, numsSize, val);
    printf("%d\n", ret);

    return 0;
}
