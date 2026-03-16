#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CircularQueue
{
	int* _str;
	int front;
	int rear;
	int n;
}CircularQueue;


typedef struct sequence_list
{
	int* _str;
	size_t _size;
	size_t _capacity;

}sequence_list;


void list_reserve(sequence_list* list, size_t n)
{
	list->_capacity *= 2;
	int* tmp = (int*)malloc(list->_capacity * sizeof(int));
	memcpy(tmp, list->_str, list->_size * sizeof(int));
	
	free(list->_str);
	list->_str = tmp;
	
}

int find_count_of_list(sequence_list* list, int x)
{
	int ret = 0;
	for (size_t cur = 0; cur < list->_size; cur++)
	{
		if (list->_str[cur] == x)
			++ret;
	}
	return ret;
}



void insert_SortedList(sequence_list* list, int x)
{
	if (list->_size == list->_capacity)
	{
		list_reserve(list, 2 * list->_capacity);
	}
	size_t cur = 0;
	while (cur < list->_size)
	{
		if (list->_str[cur] >= x)
			break;
		else
			++cur;
	}

	for (size_t i = list->_size;i > cur ;i--)
	{
		list->_str[i] = list->_str[i - 1];
	}

	list->_str[cur] = x;

	list->_size++;
}


int size_of_CircularQueue(CircularQueue* queue)
{
	if (queue->front <= queue->rear)
	{
		return queue->rear - queue->front;
	}

	return queue->n - queue->front + queue->rear;
	
}

int main()
{


	return 0;
}