#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int waysToStep(int n)
{
	// count ������ѭ���м������� 3 ��ʼ����Ϊ������Ҫ�� 3 �����ܿ�ʼ����
	int count = 3;

	// �洢����ÿһ��̨�׵Ĳ�ͬ��ʽ������
	// arr[0]��arr[1]��arr[2] �ֱ��ʾ����ǰһ�ס�ǰ���׺�ǰ����̨�׵Ĳ�ͬ��ʽ������
	int arr[4] = { 0 };
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;

	if (n <= 2)
	{
		return n;
	}
	else if (n == 3)
	{
		return 4;
	}

	// ֱ�� count ���� n�����������һ��̨��
	while (count < n)
	{
		// ������ǰ 3 ��̨�׵ķ�ʽ������Ӳ�ȡģ���Ա���������
		arr[3] = (arr[0] + arr[1]) % 1000000007 + arr[2];  // ���㵽��� count �׵ķ�ʽ����
		arr[3] %= 1000000007;     // ȡģ�Ա������

		/// �� arr[0], arr[1], arr[2] ��ֵ��ǰ�ƶ�
		arr[0] = arr[1];
		arr[1] = arr[2];
		arr[2] = arr[3];

		// �ƶ�����һ��
		count++;
	}
	// ������������� 1 ��Ԫ�ص�ֵ��������� n ��̨�׵Ĳ�ͬ��ʽ������
	return arr[3];
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = waysToStep(n);
	printf("%d\n", ret);

	return 0;
}
