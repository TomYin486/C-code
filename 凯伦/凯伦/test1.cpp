#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ���� 3 ���������������� nums ��ָ�룬����Ĵ�С numsSize���Լ�Ҫ���ҵ�Ŀ��ֵ target
int searchInsert(int* nums, int numsSize, int target)
{
    // left �� right�������������ʼλ�úͽ���λ�õ��±�
    int left = 0;
    int right = numsSize - 1;

    // ���ڱ�ʾ target Ӧ�ò����λ�ã���� target �������е�����Ԫ�ض���ans ������Ϊ numsSize
    int ans = numsSize;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        // ��� target С�ڻ�����м��±괦��ֵ������ ans Ϊ mid�������� right Ϊ mid - 1
        // ������һ��ѭ��ֻ�����������벿�ֲ���
        if (target <= nums[mid])
        {
            ans = mid;
            right = mid - 1;

        }
        // ��� target �����м��±괦��ֵ������ left Ϊ mid + 1
        // ������һ��ѭ��ֻ����������Ұ벿�ֲ���
        else
        {
            left = mid + 1;
        }
    }
    // ��ʾ target Ӧ�ò����λ��
    return ans;
}


int main()
{
    int nums[] = { -1,0,1,2,3,4 };
    int target = 0;
    scanf("%d", &target);
    int numsSize = sizeof(nums) / sizeof(nums[0]);   // �������� nums �Ĵ�С
    int ret = searchInsert(nums, numsSize, target);

    // ��ӡĿ��ֵ(target)�������е��±꣬������Ӧ�ñ������λ��
    printf("%d\n", ret);

    return 0;
}
