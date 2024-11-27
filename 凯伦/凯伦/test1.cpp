#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

// 函数 reverse_part，接受字符指针src（指向字符串的起始位置）、整数start（逆序开始的位置）和整数end（逆序结束的位置）
// 将字符串从 start 到 end 这一段逆序
void reverse_part(char* src, int start, int end)
{
	int i = 0;
	int j = 0;

	for (i = start, j = end; i < j; i++, j--)
	{
		char tmp = src[i];
		src[i] = src[j];
		src[j] = tmp;

	}

}

// 例如：左旋 3 次字符串 ABCDEFG，结果为 DEFGABC
// 先将要左旋的前 3 个字符串逆序（CBADEFG），然后将后半段也逆序（CBAGFED），最后整体逆序（DEFGABC）即可
// 这样只需要做数值交换即可，可以写个上述函数来完成局部逆序


int main()
{
	int time = 0;
	char arr[] = "ABCD";
	scanf("%d", &time);

	int len = strlen(arr);
	int pos = time % len;

	reverse_part(arr, 0, pos - 1);   //逆序前段,将字符串 arr 从下标 0 到 pos - 1 的子串逆序
	reverse_part(arr, pos, len - 1); //逆序后段，将字符串 arr 从下标 pos 到 len - 1 的子串逆序
	reverse_part(arr, 0, len - 1);   //整体逆序
	printf("%s", arr);

	return 0;
}
