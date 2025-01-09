#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

// �����ж���������С�ıȽϺ���
int compare(const void* p1, const void* p2)
{
    // ת��Ϊ int ���Ͳ�������
    return *(int*)p1 - *(int*)p2;
}

void merge(int* nums1, int m, int* nums2, int n)
{
    int i = 0;
    int j = 0;

    // �� nums2 �е�Ԫ�غϲ��� nums1 ��ĩβ
    for (i = m; i < m + n; i++)
    {
        nums1[i] = nums2[j];
        j++;
    }
    // ʹ�� qsort �Ժϲ���� nums1 ��������
    qsort(nums1, m + n, sizeof(int), compare);

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
