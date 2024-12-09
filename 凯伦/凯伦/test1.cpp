#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    // ��������СΪ 0��������Ϊ�գ���ôֱ�ӷ��� 0����Ϊû��Ԫ�ؿ��Դ���
    if (numsSize == 0)
    {
        return 0;
    }

    // fast ָ�����ڱ������飬slow ָ�����ڱ�ǲ��ظ�Ԫ�ص�λ��
    int fast = 1;
    int slow = 1;
    while (fast < numsSize)
    {
        // ��� fast ָ��ָ��ĵ�ǰԪ���Ƿ���ǰһ��Ԫ�ز�ͬ�������ͬ��˵����ǰԪ����һ���µ�ΨһԪ��
        if (nums[fast] != nums[fast - 1])
        {
            // ǰԪ����Ψһ�ģ��ͽ��临�Ƶ� slow ָ��ָ���λ�ã����� slow ָ����ǰ�ƶ�һλ
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }
    // slow ָ��ָ���λ�þ������ 1 ��ΨһԪ��֮���λ�ã���������ΨһԪ�ص�����
    return slow;
}

int main()
{
    int nums[] = { 1,1,2,3,4,4,10 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int ret = removeDuplicates(nums, numsSize);
    printf("%d\n", ret);

    // ��飬��ӡ������ nums ��ÿ��ΨһԪ��
    for (int i = 0; i < ret; i++)
    {
        printf("%d ", nums[i]);

    }
    return 0;
}
