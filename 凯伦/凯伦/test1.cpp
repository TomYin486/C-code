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
    // slow �� fast ��ʼʱ��ָ�������ͷ�ڵ� head
    ListNode* slow = head;
    ListNode* fast = head;

    // ע������ѭ����������д���ˣ���Ȼ�������
    // ��� fast Ϊ NULL��fast->next �ᵼ�·��ʿ�ָ��
    while (fast != NULL && fast->next != NULL)
    {
        // �� slow ָ��ÿ����һ����fast ָ��ÿ�������� 
        // �� fast = NULL �� fast->next = NULL ʱ���� slow ָ��պ�ָ��ľ����м�Ľڵ�
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
