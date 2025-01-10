#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    int l1 = m - 1;      // 表示 nums1 的最后一个有效元素
    int l2 = n - 1;      // 表示 nums2 的最后一个有效元素
    int l3 = m + n - 1;  // 表示 nums1 最后一个位置

    // 从后往前合并两个数组，确保较大的元素放在后面
    // l1 >= 0 且 l2 >= 0，表示 nums1 和 nums2 都还有未处理的元素
    while (l1 >= 0 && l2 >= 0)
    {
        if (nums1[l1] > nums2[l2])
        {
            nums1[l3] = nums1[l1];
            l3--;
            l1--;
        }
        else
        {
            nums1[l3] = nums2[l2];
            l3--;
            l2--;
        }

    }
    // 循环结束，表示 l1 < 0 或 l2 < 0，如果 nums2 还有剩余元素，直接合并到 nums1 中
    while (l2 >= 0)
    {
        nums1[l3] = nums2[l2];
        l3--;
        l2--;
    }

}

int main()
{
    int nums1[] = { 2,3,4,5,0,0,0,0 };  // nums1 为目标数组，用于存储合并后的结果
    int nums2[] = { 1,4,7,8 };     // 源数组，需要合并到 nums1 中

    // m 为 nums1 所含有效数组元素，而不是数组的长度
    int m = 4;

    // n 为 nums2 中有效元素的个数
    int n = sizeof(nums2) / sizeof(nums2[0]);

    merge(nums1, m, nums2, n);

    int i = 0;
    for (i = 0; i < m + n; i++)
    {
        printf("%d ", nums1[i]);
    }
    return 0;
}
