#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<string.h>
void leftRound(char* src, int time)
{
	int len = strlen(src);  // ʹ�� strlen �������㴫���ַ��� src �ĳ���

	// ���� time ���� len ���������õ�ʵ����Ҫ��ת�Ĵ��� pos
	// ��Ϊ��ת�ַ������ȵ����������ַ������ᷢ���仯
	int pos = time % len;   // �Ͽ�λ�õ��±�

	// �ַ����� tmp ������ʱ�洢��ת����ַ���
	// �����СΪ 256��������������κ���ת����ַ���
	char tmp[256] = { 0 };  // ��׼ȷ�Ļ�����ѡ�� malloc len + 1 ���ֽڵĿռ�������� tmp

	// ʹ�� strcpy ������ src �д�λ�� pos ��ʼ�����ַ������Ƶ� tmp ��
	strcpy(tmp, src + pos); // �Ƚ������ȫ��������

	// ʹ�� strncat ������ src �дӿ�ʼ��λ�� pos �����ַ���ƴ�ӵ� tmp ��ĩβ
	strncat(tmp, src, pos); // Ȼ��ǰ�漸������

	// ʹ�� strcpy ������ tmp �д洢����ת����ַ������ƻ� src
	strcpy(src, tmp);       // ��󿽻�ȥ
}

int main()
{
	int time = 0;
	char arr[] = "abcde";
	scanf("%d", &time);
	leftRound(arr, time);
	printf("%s", arr);
	return 0;
}
