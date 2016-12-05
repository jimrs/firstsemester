#include <stdio.h>
#include <stdlib.h>

struct item {
	int value;
	struct item *next;
};

typedef struct item item_t;

struct list {
	item _t *head;
};

typedef struct list list_t;

item_t *itemNew(int Value)
{
	item_t *item;
	item = malloc(sizeof(item_t));
	item->value = value;
	item->next = NULL;
	return item;

void listInit(list_t *list)
{
	list->head = NULL;	
	// list->head->next je hodnota prvni polozky
	// list->head->next->next druha polozka etc
}

void listFree(list_t *list)
{
	item_t *item, *tmp;

	item = list->head;
	while (item != NULL) {
		tmp = item->next;
		free(item);
		item = tmp;
	} // musim tmp mit, jelikoz free(item) mi smaze i item.next takze bych nemohl na dalsi prvek
	// lze rekurzi bez tmp
}

void listAppend(list_t *list, int value)
{
	item_t *item;
	item_t *it;

	item = itemNew(value);

	if (list->head == NULL) {
		list->head = item;
	} else {
		it = list->head;

		while (it->next != NULL) {
			it = it->next;
		}

		//nebo

		//for (it = list->head; it->next != NULL; it = it->next);

		it->next = item;
	}

}

void listPrepend(list_t *list, int value)
{
	item_t *item;
	item = malloc(sizeof(item_t));

	item->value = value;
	item->next = list->head;
	list->head = item;
}
void listInsert(list_t *list, int value, int idx);
void listDel(list_t *list, int idx);

int main()
{
	return 0;
}
