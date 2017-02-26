// ConsoleApplication1.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <ctime>

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
	head->next = NULL;
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
	*head = NULL;
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
	srand(time(NULL));
	int size,i;
	node *head;

	size = rand() % 100 + 1;
	i = size;
	head = init();
	head->num = i;

	while (i)
	{
		push(&head,rand()%100+1);
		i--;
	}i = size;


	while (i)
	{
		cout << top(head)<<", ";
		pop(&head);
		i--;
	}

	destroy(&head);


	//if (empty(head))
	//{
	//	cout << "\nStack is empty";
	//}
	//else cout << "\nStack is not empty";
	Sleep(3000);
	return 0;
}