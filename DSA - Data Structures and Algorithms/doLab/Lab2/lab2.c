#include <stdio.h>
#include <stdlib.h>
#include "list.h"

bool IsEmpty(Node* head)
{
    return head == NULL ? true : false;
}

void DisplayList(Node* head)
{
    if (!IsEmpty(head))
    {
        for (; head; head = head->next)
            printf("%f ", head->data);
        printf("\n");
    }
}

Node* InsertNode(Node** phead, int index, double x)
{
    if (index < 0) return NULL;
    else if (index == 0)
    {
        Node* newnode = (Node*)malloc(sizeof(Node));
        if (newnode == NULL) return NULL;
        newnode->data = x;

        newnode->next = *phead;
        *phead = newnode;
    }
    else if (index > 0)
    {
        int curindex = 1;
        Node* curpos = *phead;
        for (; curindex < index && curpos; curindex++, curpos = curpos->next){} // 遍历到 index 的位置
        if(curindex != index || curpos == NULL) return NULL;

        Node* newnode = (Node*)malloc(sizeof(Node));
        if (newnode == NULL) return NULL;
        newnode->data = x;

        newnode->next = curpos->next;
        curpos->next = newnode;
        return newnode;
    }
    return NULL;
}

int FindNode(Node* head, double x)
{
    for (int curindex = 1; head; head = head->next, curindex++)
    {
        if (head->data == x) return curindex;
    }
    return 0;
}

int DeleteNode(Node** phead, double x)
{
    int delindex = FindNode(*phead, x);

    if (delindex == 0) return 0;
    else if (delindex == 1)
    {
        *phead = (*phead)->next;
    }
    else
    {
        Node* curpos = (*phead)->next;
        Node* prepos = *phead;
        for (; curpos; curpos = curpos->next, prepos = prepos->next)
        {
            if (curpos->data == x)
            {
                prepos->next = curpos->next;
                free(curpos);
                return delindex;
            }
        }
    }
    return delindex;
}

void DestroyList(Node** phead)
{
    Node* curpos = *phead;
    while (curpos)
    {
        Node* nextpos = curpos->next;
        free(curpos);
        curpos = nextpos;
    }
    *phead = NULL;
}

int main()
{
    Node* head = 0;
    for (int i = 0; i < 5; i++)
        InsertNode(&head, i, i);
    DisplayList(head);

    for (int i = 0; i < 5; i++)
        InsertNode(&head, 0, i);
    DisplayList(head);

    InsertNode(&head, 12, 7);
    DisplayList(head);

    for (int i = 0; i < 7; i += 2)
    {
        int idx = FindNode(head, i);
        if (idx > 0)
            printf("%d is at position %d.\n", i, idx);
        else
            printf("%d is not in the list.\n", i);
    }

    DeleteNode(&head, 0);
    DisplayList(head);

    DeleteNode(&head, 4);
    DisplayList(head);

    DeleteNode(&head, 7);
    DisplayList(head);

    DestroyList(&head);
    printf("IsEmpty[%d]\n", IsEmpty(head));
    return 0;
}