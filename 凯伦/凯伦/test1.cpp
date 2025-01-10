#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n)
{
    int l1 = m - 1;      // ��ʾ nums1 �����һ����ЧԪ��
    int l2 = n - 1;      // ��ʾ nums2 �����һ����ЧԪ��
    int l3 = m + n - 1;  // ��ʾ nums1 ���һ��λ��

    // �Ӻ���ǰ�ϲ��������飬ȷ���ϴ��Ԫ�ط��ں���
    // l1 >= 0 �� l2 >= 0����ʾ nums1 �� nums2 ������δ�����Ԫ��
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
    // ѭ����������ʾ l1 < 0 �� l2 < 0����� nums2 ����ʣ��Ԫ�أ�ֱ�Ӻϲ��� nums1 ��
    while (l2 >= 0)
    {
        nums1[l3] = nums2[l2];
        l3--;
        l2--;
    }

}

int main()
{
    int nums1[] = { 2,3,4,5,0,0,0,0 };  // nums1 ΪĿ�����飬���ڴ洢�ϲ���Ľ��
    int nums2[] = { 1,4,7,8 };     // Դ���飬��Ҫ�ϲ��� nums1 ��

    // m Ϊ nums1 ������Ч����Ԫ�أ�����������ĳ���
    int m = 4;

    // n Ϊ nums2 ����ЧԪ�صĸ���
    int n = sizeof(nums2) / sizeof(nums2[0]);

    merge(nums1, m, nums2, n);

    int i = 0;
    for (i = 0; i < m + n; i++)
    {
        printf("%d ", nums1[i]);
    }
    return 0;
}
