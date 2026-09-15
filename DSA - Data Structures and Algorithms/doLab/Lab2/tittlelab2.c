#include "list.h"
#include <stdio.h>
#include <stdlib.h>

bool IsEmpty(Node* head)
{
	return head == NULL ? true : false;
}

void DisplayList(Node* head)
{
	if (IsEmpty(head) == false)
	{
		while (head)
		{
			printf("%f ", head->data);
			head = head->next;
		}
		printf("\n");
	}
}

Node* InsertNode(Node** phead, int index, double x)
{
//Your code
	}

int FindNode(Node* head, double x)
{
//Your code 
	}

int DeleteNode(Node** phead, double x)
{
//Your code
	}


void DestroyList(Node** phead)
{
//Your code
	}


int main()
{
	Node *head = 0;
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

	DeleteNode(&head,4);
	DisplayList(head);

	DeleteNode(&head, 7);
	DisplayList(head);

	DestroyList(&head);
	printf("IsEmpty[%d]\n", IsEmpty(head));
}