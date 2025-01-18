#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ������
struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

// ��������������ԭ�����Ҳ�Ϊ val �Ľڵ㣬β������������
struct ListNode* removeElements(struct ListNode* head, int val)
{
    ListNode* newHead = NULL;
    ListNode* newTail = NULL;

    ListNode* pcur = head;

    while (pcur != NULL)
    {
        // ���� val��β�嵽������
        if (pcur->val != val)
        {
            // ����Ϊ�գ���������Ľڵ���������ͷ�ڵ��β�ڵ�
            if (newHead == NULL)
            {
                newHead = newTail = pcur;
            }
            // ����Ϊ�գ���������Ľڵ����������µ�β�ڵ�
            else
            {
                // �� newTail ��Ϊ�µ�β�ڵ�
                newTail->next = pcur;
                newTail = newTail->next;
            }
        }
        pcur = pcur->next;
    }
    // ȷ������������һ���ڵ���ȷ��ֹ
    if (newTail != NULL)
    {
        newTail->next = NULL;
    }
    // �����������ͷ�ڵ�
    return newHead;
}

// ��ӡ����
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

// �ͷ������ڴ�
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
    // �������� [1, 2, 3]
    ListNode* s1 = (ListNode*)malloc(sizeof(ListNode));
    s1->val = 1;

    ListNode* s2 = (ListNode*)malloc(sizeof(ListNode));
    s2->val = 2;

    ListNode* s3 = (ListNode*)malloc(sizeof(ListNode));
    s3->val = 3;

    s1->next = s2;
    s2->next = s3;
    s3->next = NULL;

    // ��ӡԭʼ����
    printf("Original list: ");
    printList(s1);

    int val = 2;

    ListNode* newHead = removeElements(s1, val);

    // ��ӡ����������
    printf("List after removing %d: ", val);
    printList(newHead);

    // �ͷ���������ڴ�
    freeList(newHead);

    // ע�⣺��Ҫ�ͷ�ԭʼ����Ľڵ㣬��Ϊ���ǿ����Ѿ���������ʹ��
    // ������ôд freeList(s1); 

    return 0;
}
