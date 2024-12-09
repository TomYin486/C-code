#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    // 如果数组大小为 0，即数组为空，那么直接返回 0，因为没有元素可以处理
    if (numsSize == 0)
    {
        return 0;
    }

    // fast 指针用于遍历数组，slow 指针用于标记不重复元素的位置
    int fast = 1;
    int slow = 1;
    while (fast < numsSize)
    {
        // 检查 fast 指针指向的当前元素是否与前一个元素不同。如果不同，说明当前元素是一个新的唯一元素
        if (nums[fast] != nums[fast - 1])
        {
            // 前元素是唯一的，就将其复制到 slow 指针指向的位置，并将 slow 指针向前移动一位
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    // slow 指针指向的位置就是最后 1 个唯一元素之后的位置，即数组中唯一元素的数量
    return slow;
}

int main()
{
    int nums[] = { 1,1,2,3,4,4,10 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ret = removeDuplicates(nums, numsSize);
    printf("%d\n", ret);

    // 检查，打印出数组 nums 的每个唯一元素
    for (int i = 0; i < ret; i++)
    {
        printf("%d ", nums[i]);

    }
    return 0;
}
