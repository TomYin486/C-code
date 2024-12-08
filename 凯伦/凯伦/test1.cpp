#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include <stdbool.h>
#include <string.h>

// haystack 和 needle 2 个参数都为个字符指针，分别指向要搜索的字符串和要查找的子串
// 函数返回一个整数，表示子串在字符串中的位置
int strStr(char* haystack, char* needle)
{
    // 计算 haystack 和 needle 字符串的长度
    int n = strlen(haystack);
    int m = strlen(needle);

    // 如果 needle 的长度为 0(空字符串)，空字符串是任何字符串的子串，则函数返回 0
    if (m == 0)
    {
        return 0;
    }
    // 如果 needle 的长度大于 haystack 的长度，不可能在 haystack 中找到比它本身还长的子串，则函数返回 -1
    if (m > n)
    {
        return -1;
    }
    int i = 0;

    // 标记当前检查的子串是否与 needle 匹配
    bool flag = true;

    // 从 haystack 的第 0 位置字符开始，每次加 1，直到 i + m (检查的位置加上 needle 的长度)不超过 haystack 的长度 n
    for (i = 0; i + m <= n; i++)
    {
        // flag 重置为 true，进行新的匹配检查
        flag = true;
        // 逐个字符比较 haystack 中从位置 i 开始的子串与 needle
        for (int j = 0; j < m; j++)
        {
            // 如果 haystack 中的当前字符与 needle 中的对应字符不匹配，将 flag 设置为 false 并跳出内层循环
            if (haystack[i + j] != needle[j])
            {
                flag = false;
                break;
            }
        }
        // 如果 flag 仍然为 true，则找到了匹配的子串，函数返回当前的起始位置 i
        if (flag)
        {
            return i;
        }
    }
    // 如果循环结束后没有找到匹配的子串，函数返回 -1
    return -1;
}

int main()
{
    char haystack1[] = "abc";
    char needle1[] = "abcd";
    int ret1 = strStr(haystack1, needle1);
    printf("%d\n", ret1);

    char haystack2[] = "ccabcd";
    char needle2[] = "ab";
    int ret2 = strStr(haystack2, needle2);
    printf("%d\n", ret2);
    return 0;
}
