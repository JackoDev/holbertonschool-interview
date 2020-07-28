#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


/**
 * insert_node - Function that inserts a number into a sorted singly linked list
 * @head: double pinter to the header node
 * @number: node's nuevo integer
 * Return: nuevo node's adress, or NULL
 */


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *anterior, *siguiente, *nuevo;

	nuevo = malloc(sizeof(listint_t));
	if (!nuevo)
		return (NULL);
	nuevo->n = number;
	if (*head == NULL)
	{
		nuevo->next = NULL;
		*head = nuevo;
		return (nuevo);
	}
	anterior = *head;
	siguiente = anterior->next;
	while (anterior)
	{
		if (anterior->n >= number)
		{
			nuevo->next = anterior;
			*head = nuevo;
			return (nuevo);
		}
		else if (!siguiente && anterior->n <= number)
		{
			anterior->next = nuevo;
			nuevo->next = NULL;
			return (nuevo);
		}
		else if (anterior->n <= number && siguiente->n >= number)
		{
			anterior->next = nuevo;
			nuevo->next = siguiente;
			return (nuevo);
		}
		anterior = siguiente;
		siguiente = anterior->next;
	}
	return (NULL);
}