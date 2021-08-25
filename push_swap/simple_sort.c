#include "push_swap.h"

t_stack	*simple_sort(t_stack *stack_A)
{
	int	max;

	if (size_stack(stack_A) == 1)
		return (stack_A);
	else if (size_stack(stack_A) == 2)
	{
		if (stack_A -> order > stack_A -> next -> order)
			swap(&stack_A, 'A');
		return (stack_A);
	}
	max = max_order(stack_A);
	if (stack_A -> order == max)
		rotate(&stack_A, 'A');
	if (stack_A -> next -> order == max)
		reverse_rotate(&stack_A, 'A');
	if (stack_A -> order > stack_A -> next -> order)
		swap(&stack_A, 'A');
	return (stack_A);
}

t_stack	*simple_sort_2(t_stack *stack_A)
{
	t_stack	*stack_B;

	if (size_stack(stack_A) == 5)
	{
		while ((stack_A -> order != 1) && (stack_A -> order != 2))
			rotate(&stack_A, 'A');
		push(&stack_A, &stack_B, 'B');
		while ((stack_A -> order != 1) && (stack_A -> order != 2))
			rotate(&stack_A, 'A');
		push(&stack_A, &stack_B, 'B');
		stack_A = simple_sort(stack_A);
		if (stack_B -> order < stack_B -> next -> order)
			swap(&stack_B, 'B');
		push(&stack_A, &stack_B, 'A');
		push(&stack_A, &stack_B, 'A');
	}
	else
	{
		while (stack_A->order != 1)
			rotate(&stack_A, 'A');
		push(&stack_A, &stack_B, 'B');
		stack_A = simple_sort(stack_A);
		push(&stack_A, &stack_B, 'A');
	}
	return (stack_A);
}
