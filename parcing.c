#include "push_swap.h"

int	is_valid_number(char *str)
{
	int i = 0;

	// Skip spaces
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	// Check for optional '+' or '-'
	if (str[i] == '+' || str[i] == '-')
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		i++;
	}

	// At least one digit
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);

	// Check all characters are digits after sign
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_node *head)
{
	t_node *current = head;
	t_node *checker;

	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

void	push_stack(t_node **stack, int value)
{
	t_node *new_node = malloc(sizeof(t_node));
	if (!new_node)
		return;
	new_node->value = value;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		t_node *temp = *stack;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}
