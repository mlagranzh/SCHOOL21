#include "push_swap.h"

int	max_order(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (i < stack -> order)
			i = stack -> order;
		stack = stack -> next;
	}
	return (i);
}

int	size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack -> next;
	}
	return (i);
}

int	check_sort_stack(t_stack *stack_A)
{
	while (stack_A -> next -> next != NULL)
	{
		if (stack_A -> order != (stack_A -> next -> order - 1))
			return (0);
		stack_A = stack_A -> next;
	}
	return (1);
}

int	check_sort_stack_2(t_stack *stack_A, int i)
{
	int	number;

	if (check_sort_stack(stack_A))
		return (1);
	number = size_stack(stack_A) / i;
	if (i != size_stack(stack_A))
		while (number--)
			stack_A = stack_A -> next;
	while (stack_A -> next -> next != NULL)
	{
		if (stack_A -> order != (stack_A -> next -> order - 1))
			return (0);
		stack_A = stack_A -> next;
	}
	return (1);
}

t_stack	*addelem(t_stack *lst, int number)
{
	t_stack	*temp;
	t_stack	*p;

	if (lst == NULL)
	{
		lst = malloc(sizeof(t_stack));
		lst -> value = number;
		lst -> next = NULL;
		return (lst);
	}
	temp = malloc(sizeof(t_stack));
	p = lst->next;
	lst -> next = temp;
	temp -> value = number;
	temp -> next = p;
	return (temp);
}
