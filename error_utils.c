#include "push_swap.h"

void	print_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	free_all(stack);
	exit(1);
}

void	free_stack(t_node *head)
{
	t_node *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_all(t_stack *stack)
{
	if (stack)
	{
		free_stack(stack->a);
		free_stack(stack->b);
		free(stack); // Free the struct itself
	}
}

