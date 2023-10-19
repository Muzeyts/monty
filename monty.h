#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: this is integer
 * @prev: yeah the previous element of stack
 * @next: next to the next element of queue
 *
 * Description: structure of  doubly linked list
 * for stack, queues, LIFO, FIFO 
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - functions in global structure 
 * @lifo: this is queue or stack
 * @cont: this is current line
 * @arg: cont second parameter 
 * @head: list doubly linked
 * @fd: this is  file descriptor
 * @buffer: input text
 *
 * Description: structure of doubly linked list
 * for stack, queues, LIFO, FIFO  
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - function opcode
 * @opcode: this is  opcode
 * @f: handle opcode will be
 *
 * Description: lwts see opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t vglo;

/* opcode_instructuions*/
void _push(stack_t **stack, unsigned int line_number);
void _queue(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _pall(stack_t **stack, unsigned int line_number);
void _stack(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _pint(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _pchar(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*imported functions*/
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void free_vglo(void);

#endif
