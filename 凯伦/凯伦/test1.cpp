#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// �������ѭ��ʹ������� 1 �Σ�Ȼ������ִ�� n ��

#include<string.h>  // ������׼�ַ�������⣬�Ա�ʹ�� strlen���������ַ�������
void leftRound(char arr[], int len, int time)
{
	int i = 0;
	int j = 0;

	// ȡ time ���ַ������� len ��ģ���Ա��� time ���� len �����
	// �磺����Ϊ 6 ������£���ת 7��13��19...���൱�� 1 �Σ�8��14��20...���൱�� 2 ��
	time %= len;

	// ִ�� time �εĵ���ƽ��
	// ��ѭ�� time �Σ�ÿ��ѭ�����ַ������� 1 ���ַ�
	for (i = 0; i < time; i++)
	{
		char tmp = arr[0];
		// ����ƽ��
		for (j = 0; j < len - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[j] = tmp;  // Ҳ����д������ arr[len - 1] = tmp;

	}
}
int main()
{
	char arr[] = "abcdef";
	int time = 0;   // ��ʾ��������
	scanf("%d", &time);
	int len = strlen(arr);   // ʹ�� strlen���������ַ��� arr �ĳ���
	leftRound(arr, len, time);
	printf("%s", arr);
	return 0;
}
