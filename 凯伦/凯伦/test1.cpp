#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ʹ�� ^ �ɷ�ֹ����̫������������� (n+1) * n / 2��
// ���������ص�: 
// 1.�κ����� 0 ��򣬽����Ȼ��ԭ������
// 2.�κ�����������򣬽���� 0
// 3.���������㽻���ɺͽ����

int missingNumber(int* nums, int numsSize)
{
	int x = 0;       // x ���ڱ�ʾ�����
	int n = numsSize;
	int i = 0;

	// �� 0 �� n �����������������������õ�һ���м������������൱�� 0 �� n ����������������
	for (i = 0; i <= n; i++)
	{
		x ^= i;
	}

	// �������е�ÿ��Ԫ�ؽ���������
	// ���������е�Ԫ���� 0 �� n ��ȱʧһ�������ļ��ϣ��������Ὣ�ظ�����������������ʣ�µľ���ȱʧ������
	for (i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	return x;

	// Ҳ���Լ�
	/*int x = 0;
	for (int i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
		x ^= i;
	}
	x ^= numsSize;
	return x;*/
}

int main()
{
	int nums[] = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);   // ��������Ĵ�С
	int ret = missingNumber(nums, numsSize);
	printf("%d\n", ret);
	return 0;
}
