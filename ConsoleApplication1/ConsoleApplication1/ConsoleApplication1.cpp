// ConsoleApplication1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct node
{
	int num;
	struct node *next;
};

node *init()
{
	node *head;
	head = new node;
	return head;
}

void destroy(node **head)
{
	node *tmp;
	while ((*head)->next)
	{
		tmp = (*head);
		*head = (*head)->next;
		delete tmp;
	}
	delete *head;
}

void push(node **head, int n)
{
	node *newhead;
	newhead = new node;
	newhead->num = n;
	newhead->next = (*head);
	*head = newhead;
}

void pop(node **head)
{
	node *tmp;
	tmp = (*head);
	*head = (*head)->next;
	delete tmp;
}

int top(node *head)
{
	return head->num;
}

bool empty(node *head)
{
	if (head == NULL) return true;
	else return false;
}

bool full(node *head, int size)
{
	int amount = 0;
	while(head)
	{
		amount++;
		head = head->next;
	}
	if (amount == size) return true;
	else return false;
}

int main()
{
	int size,i;
	node *head;

	cout << "Enter size of stack: " << endl;
	cin >> size; i = size;
	head = init();
	head->num = i;

	while (i)
	{
		push(&head,i);
		i--;
	}i = size;
	while (i)
	{
		cout << head->num;
		head = head->next;
		i--;
	}
	return 0;
}