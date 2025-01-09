#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// 用于判断两个数大小的比较函数
int compare(const void* p1, const void* p2)
{
    // 转换为 int 类型并解引用
    return *(int*)p1 - *(int*)p2;
}

void merge(int* nums1, int m, int* nums2, int n)
{
    int i = 0;
    int j = 0;

    // 将 nums2 中的元素合并到 nums1 的末尾
    for (i = m; i < m + n; i++)
    {
        nums1[i] = nums2[j];
        j++;
    }
    // 使用 qsort 对合并后的 nums1 进行排序
    qsort(nums1, m + n, sizeof(int), compare);

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
