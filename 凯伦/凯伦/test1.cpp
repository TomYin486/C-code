#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<string.h>
void leftRound(char* src, int time)
{
	int len = strlen(src);  // 使用 strlen 函数计算传入字符串 src 的长度

	// 计算 time 除以 len 的余数，得到实际需要旋转的次数 pos
	// 因为旋转字符串长度的整数倍后，字符串不会发生变化
	int pos = time % len;   // 断开位置的下标

	// 字符数组 tmp 用作临时存储旋转后的字符串
	// 数组大小为 256，假设可以容纳任何旋转后的字符串
	char tmp[256] = { 0 };  // 更准确的话可以选择 malloc len + 1 个字节的空间来做这个 tmp

	// 使用 strcpy 函数将 src 中从位置 pos 开始的子字符串复制到 tmp 中
	strcpy(tmp, src + pos); // 先将后面的全部拷过来

	// 使用 strncat 函数将 src 中从开始到位置 pos 的子字符串拼接到 tmp 的末尾
	strncat(tmp, src, pos); // 然后将前面几个接上

	// 使用 strcpy 函数将 tmp 中存储的旋转后的字符串复制回 src
	strcpy(src, tmp);       // 最后拷回去
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
