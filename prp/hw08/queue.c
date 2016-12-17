#include "queue.h"

queue_t* create_queue(int capacity)
{
	queue_t *queue = malloc(sizeof(queue_t));

	queue->data = malloc(sizeof(void*) * capacity);
	queue->capacity = capacity;
	queue->used = 0;
	queue->head = queue->data;
	queue->tail = queue->data;

	return queue;
}

void delete_queue(queue_t *queue)
{
	free(queue->data);
	free(queue);
}

bool push_to_queue(queue_t *queue, void *data)
{
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
	if (queue->used == 0)
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
	if (idx < 0 || idx >= queue->capacity)
		return NULL;
	if (idx >= queue->used)
		return NULL;

	return *(queue->tail + idx);
}

int get_queue_size(queue_t *q)
{
	return q->used;
}
