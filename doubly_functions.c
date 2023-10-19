#include "monty.h"

/**
 *add_dnodeint_end - power of now  end of the doubly link list
 *@head: first position of linked list
 *@n: watch it data to store
 *Return: a doubly win linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmpcatch, *judge;

	if (head == NULL)
		return (NULL);
	tmpcatch = malloc(sizeof(stack_t));
	if (!tmpcatch)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmpcatch->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		tmpcatch->next = *head;
		tmpcatch->prev = NULL;
		*head = tmpcatch;
		return (*head);
	}
	judge = *head;
	while (judge->next)
		judge = judge->next;
	tmpcatch->next = judge->next;
	tmpcatch->prev = judge;
	judge->next = tmpcatch;
	return (judge->next);
}

/**
 *add_dnodeint - add  begining of the doubly link list
 *@head: first position of linked list
 *@n: what is required data to store
 *Return: a doubly action  linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmpcatch;

	if (head == NULL)
		return (NULL);
	tmpcatch = malloc(sizeof(stack_t));
	if (!tmpcatch)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmpcatch->n = n;
	if (*head == NULL)
	{
		tmpcatch->next = *head;
		tmpcatch->prev = NULL;
		*head = tmpcatch;
		return (*head);
	}
	(*head)->prev = tmpcatch;
	tmpcatch->next = (*head);
	tmpcatch->prev = NULL;
	*head = tmpcatch;
	return (*head);
}

/**
 * free_dlistint - ofcource he doubly linked list
 * @head: accept head of list
 * Return: no complain return
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
