#include "queue.h"

queue_t* create_queue(int capacity)
{
	queue_t *queue = malloc(sizeof(queue_t));

	queue->data = malloc(sizeof(void*) * capacity);
	queue->capacity = capacity;
	queue->used = 0;
	queue->head = queue->data;
	queue->tail = queue->data;

	//printf("queue allocated at adress %ld with capacity %ld\n", queue->data, queue->capacity);
	//printf("head is pointing at adress %ld\n", queue->head);
	//printf("tail is pointing at adress %ld\n", queue->tail);

	return queue;
}

void delete_queue(queue_t *queue)
{
	free(queue->data);
	free(queue);
}

bool push_to_queue(queue_t *queue, void *data)
{
	printf("queue allocated at adress %ld with capacity %ld\n", queue->data, queue->capacity);
	printf("head is pointing at adress %ld\n", queue->head);
	printf("tail is pointing at adress %ld\n", queue->tail);
	printf("value at head is %ld\n", *queue->head);
	printf("value at tail is %ld\n", *queue->tail);
	printf("used is %ld\n", queue->used);
	printf("data to push is %ld\n", *((int*)data));


	if (queue == NULL || (queue->used == queue->capacity))
		return false;
	
	*(queue->head) = data;
	queue->head++;

	if (queue->head >= (queue->data + queue->capacity))
		queue->head = queue->data;	

	queue->used++;

	return true;
}

void* pop_from_queue(queue_t *queue)
{
	if (queue->used < 1)
		return NULL;

	queue->used--;

	void *tail_tmp = *queue->tail;
	queue->tail++;

	if (queue->tail >= queue->data + queue->capacity)
		queue->tail = queue->data;

	return tail_tmp;
}

void* get_from_queue(queue_t *queue, int idx)
{
	return NULL;
}

int get_queue_size(queue_t *q)
{
	printf("queue size is %ld\n", q->used);

	return q->used;
}
