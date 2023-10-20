#include "sort.h"

/**
 * insertion_sort_list - Function implementing insertion sort algorithm
 * to sort doubly linked list in ascending order.
 * @list:  The head node pointer.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	a = (*list)->next;
	while (a != NULL)
	{
		b = a;
		a = a->next;
		while (b != NULL && b->prev)
		{
			if (b->prev->n > b->n)
			{
				_nodeswap(b->prev, b);
				if (b->prev == NULL)
					*list = b;
				print_list((const listint_t *)*list);
			}
			else
				b = b->prev;
		}
	}
}

/**
 * _nodeswap - Function to swap two nodes in a doubly-linked list.
 * @first: first node address.
 * @second: second node to swap.
 */
void _nodeswap(listint_t *first, listint_t *second)
{
	if (first->prev != NULL)
		first->prev->next = second;

	if (second->next != NULL)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;

	first->prev = second;
	second->next = first;
}
