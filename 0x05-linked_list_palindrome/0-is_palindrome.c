#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * length_list - A function to obtain the length of a linked list
 * @head: head of the linked list
 * Return: the lenght of the linked list
 */

int length_list(listint_t **head)
{
	listint_t *actual = *head;
    int i;

	for (i = 0; actual != NULL; i++)
		actual = actual->next;
	return (i);
}

/**
 * reversed - function that reverse a linked list
 * @head: double pointer to the linked list start
 * Return: a pointer to the new element
 */

listint_t *reversed(listint_t **head)
{
	listint_t *prev = NULL, *actual = *head, *next = NULL;

	while (actual != NULL)
	{
		next = actual->next;
		actual->next = prev;
		prev = actual;
		actual = next;
	}
	*head = prev;
	return (*head);
}

/**
 * is_palindrome - a function for check if a linked list is palindrome
 * @head: linked list head
 * Return: 1 if is palindrome or 0 if not
 */

int is_palindrome(listint_t **head)
{
	int length = length_list(head);
	int middle = length / 2;
	int i, validator = 1;
	listint_t *head_rev;
	listint_t *actual = *head;
	listint_t *reversed_actual;

	head_rev = *head;
	for (i = 0; i < middle; i++)
		head_rev = head_rev->next;
	if (length % 2 != 0)
		head_rev = head_rev->next;
	head_rev = reversed(&head_rev);
	reversed_actual = head_rev;
	actual = *head;
	while (reversed_actual != NULL)
	{
		if (reversed_actual->n != actual->n)
			validator = 0;
		reversed_actual = reversed_actual->next;
		actual = actual->next;
	}
	return (validator);
}