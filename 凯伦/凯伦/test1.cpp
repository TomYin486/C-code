#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

struct ListNode* middleNode(struct ListNode* head) {
    // slow 和 fast 初始时都指向链表的头节点 head
    ListNode* slow = head;
    ListNode* fast = head;

    // 注意两个循环条件不能写反了，不然会出问题
    // 如果 fast 为 NULL，fast->next 会导致访问空指针
    while (fast != NULL && fast->next != NULL)
    {
        // 让 slow 指针每次走一步，fast 指针每次走两步 
        // 当 fast = NULL 或 fast->next = NULL 时，则 slow 指针刚好指向的就是中间的节点
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
