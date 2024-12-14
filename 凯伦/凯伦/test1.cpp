#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> // ���� stdlib.h ͷ�ļ�����ʹ�� malloc �� free �ȶ�̬�ڴ���亯��

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i = 0;
    for (i = 0; i < numsSize; ++i)
    {
        int j = 0;
        // �ӵ�ǰ���ѭ��Ԫ�ص���һ��Ԫ�ؿ�ʼ��ȷ������ʹ����ͬ��Ԫ������
        for (j = i + 1; j < numsSize; j++)
        {
            // ��鵱ǰ���ѭ����Ԫ�� nums[i] ���ڲ�ѭ����Ԫ�� nums[j] �ĺ��Ƿ����Ŀ��ֵ target
            if (nums[i] + nums[j] == target)
            {
                // ����ҵ�����������������ʹ�� malloc ����һ����СΪ 2 ������������ڴ�ռ䣬���ڴ洢�����±�
                int* ret = (int*)malloc(sizeof(int) * 2);
                if (ret == NULL)
                {
                    // ����ڴ����ʧ��
                    return NULL;
                }
                // ���ҵ������������±긳ֵ�� ret ���������Ԫ��
                ret[0] = i;
                ret[1] = j;

                // �� returnSize ָ���ֵ����Ϊ 2����ʾ���ص�������������Ԫ��
                *returnSize = 2;

                // ���ذ��������±������
                return ret;
            }
        }
    }
    *returnSize = 0;

    // ���� NULL����ʾû���ҵ�����������������
    return NULL;
}

int main()
{
    int nums[] = { 1,2,3,4,5 };
    int target = 0;
    int returnSize = 0;
    scanf("%d", &target);
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int* ret = twoSum(nums, numsSize, target, &returnSize);
    if (ret != NULL)
    {
        printf("�ҵ��ˣ������±���:[%d,%d]\n", ret[0], ret[1]);
        free(ret);  // �ͷ�retָ����ڴ�
    }
    else
    {
        printf("û���ҵ���������������������ռ俪��ʧ��\n");
    }
    return 0;
}
