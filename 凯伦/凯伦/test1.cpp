#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 单链表
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

// 定义新链表，遍历原链表找不为 val 的节点，尾插在新链表中
struct ListNode* removeElements(struct ListNode* head, int val)
{
    ListNode* newHead = NULL;
    ListNode* newTail = NULL;

    ListNode* pcur = head;

    while (pcur != NULL)
    {
        // 不是 val，尾插到新链表
        if (pcur->val != val)
        {
            // 链表为空：插入进来的节点就是链表的头节点和尾节点
            if (newHead == NULL)
            {
                newHead = newTail = pcur;
            }
            // 链表不为空：插入进来的节点就是链表的新的尾节点
            else
            {
                // 让 newTail 变为新的尾节点
                newTail->next = pcur;
                newTail = newTail->next;
            }
        }
        pcur = pcur->next;
    }
    // 确保新链表的最后一个节点正确终止
    if (newTail != NULL)
    {
        newTail->next = NULL;
    }
    // 返回新链表的头节点
    return newHead;
}

// 打印链表
void printList(ListNode* head)
{
    ListNode* pcur = head;
    while (pcur != NULL)
    {
        printf("%d->", pcur->val);
        pcur = pcur->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(ListNode* head)
{
    ListNode* pcur = head;
    while (pcur != NULL)
    {
        ListNode* next = pcur->next;
        free(pcur);
        pcur = next;
    }
}

int main()
{
    // 创建链表 [1, 2, 3]
    ListNode* s1 = (ListNode*)malloc(sizeof(ListNode));
    s1->val = 1;

    ListNode* s2 = (ListNode*)malloc(sizeof(ListNode));
    s2->val = 2;

    ListNode* s3 = (ListNode*)malloc(sizeof(ListNode));
    s3->val = 3;

    s1->next = s2;
    s2->next = s3;
    s3->next = NULL;

    // 打印原始链表
    printf("Original list: ");
    printList(s1);

    int val = 2;

    ListNode* newHead = removeElements(s1, val);

    // 打印处理后的链表
    printf("List after removing %d: ", val);
    printList(newHead);

    // 释放新链表的内存
    freeList(newHead);

    // 注意：不要释放原始链表的节点，因为它们可能已经被新链表使用
    // 不能这么写 freeList(s1); 

    return 0;
}
