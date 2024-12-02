#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// ���� 3 ���������������� nums ��ָ�룬����Ĵ�С numsSize���Լ�һ��Ҫ�Ƴ���ֵ val
int removeElement(int* nums, int numsSize, int val)
{
    // ���������в����� val ��Ԫ�ص��±�
    int left = 0;

    // right ���ڱ��������е�ÿ��Ԫ��
    for (int right = 0; right < numsSize; right++)
    {
        // ��鵱ǰ right �±괦��Ԫ���Ƿ񲻵��� val
        if (nums[right] != val)
        {
            // �����ǰԪ�ز����� val�����临�Ƶ� left �±괦
            // �������������в����� val ��Ԫ�ض��ᱻ�ƶ��������ǰ��
            nums[left] = nums[right];
            left++;
        }
    }
    // ���� left ��ֵ���������в����� val ��Ԫ�ص�����
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
