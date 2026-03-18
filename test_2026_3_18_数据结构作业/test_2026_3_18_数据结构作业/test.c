#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node* next;
	int val;

}Node;

int find_size(Node** head)
{
	int ret = 0;
	Node* cur = *head;
	while ( cur != NULL)
	{
		cur = cur->next;
		ret++;
	}

	return ret;
}

void insert(Node** head,int pos, int x)
{
	assert(*head != NULL);
	Node* cur = *head;
	int size = 0;
	while (size < pos&& cur->next != NULL)
	{
		size++;
		cur = cur->next;
	}

	if (cur->next != NULL)
	{
		Node* next = cur->next;
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->val = x;
		new_node->next = next;
		cur->next = new_node;
	}
}
 
void split_list(Node** head,Node** odd_head,Node** even_head)
{
	//这里采用带头单链表

	assert((*head)->next != NULL);
	Node* cur = (*head);
	Node* odd_cur = *odd_head;
	Node* even_cur = *even_head;
	Node* next;
	while (cur != NULL)
	{
		if (cur->next->val % 2 == 0)
		{
			next = cur->next->next;
			even_cur->next = cur->next;
			even_cur = cur->next;
			cur->next->next = NULL;
			cur->next = next;
		}
		else
		{
			next = cur->next->next;
			odd_cur->next = cur->next;
			odd_cur = cur->next;
			cur->next->next = NULL;
			cur->next = next;
		}
	}

}

void erase(Node** head,int val1, int val2)
{
	if (*head == NULL)
		return;
	//这里依旧是带头单链表
	Node* cur = *head;
	Node* to_delete = NULL;
	while (cur->next)
	{
		if (cur->val > val1 && cur->val < val2)
		{
			to_delete = cur->next;
			cur->next = cur->next->next;
			free(to_delete);
		}
	}

}
int main()
{



	return 0;
}