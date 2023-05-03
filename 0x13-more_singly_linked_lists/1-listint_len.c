#include "lists.h"

/**
 * listint_len - returns the number of the elements in a linked listint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of the nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t sum = 0;

	while (h != NULL)
	{
		sum++;
		h = h->next;
	}

	return (sum);
}
