#include "push_swap.h"

void	reverse_step(t_stack **stack_A, t_stack	**stack_B, t_main *main_struct)
{
	int	k;

	if (main_struct -> i != 2)
	{
		k = count_not_sort((*stack_A));
		while (k--)
		{
			if ((*stack_B)-> order != main_struct->next)
			{
				reverse_rotate_r(&(*stack_A), &(*stack_B));
				continue ;
			}
			reverse_rotate(&(*stack_A), 'A');
		}
	}
}

void	step_0(t_stack **stack_A, t_stack **stack_B, t_main **main_struct)
{
	int	number;

	number = (*main_struct)-> max - (*main_struct)-> next + 1;
	while (number--)
	{
		if ((*stack_A)-> order <= (*main_struct)-> mid)
			push(&(*stack_A), &(*stack_B), 'B');
		else
			rotate(&(*stack_A), 'A');
	}
	reverse_step(&(*stack_A), &(*stack_B), (*main_struct));
}

void	step_1(t_stack **stack_A, t_stack **stack_B, t_main **main_struct)
{
	int	number;

	while ((*stack_B) != NULL)
	{
		(*main_struct)->max = max_order(*stack_B);
		(*main_struct)->mid = ((*main_struct)->max - (*main_struct)->next) / 2 \
								+ (*main_struct)->next;
		number = size_stack((*stack_B));
		while (number--)
		{
			for_step_1(&(*stack_A), &(*stack_B), &(*main_struct));
		}
		(*main_struct)-> flag++;
	}
}

void	step_2(t_stack **stack_A, t_stack **stack_B, t_main **main_struct)
{
	int	flag;

	(*main_struct)-> max = max_order((*stack_A));
	(*main_struct)-> mid = ((*main_struct)-> max - (*main_struct)-> next) / 2 \
							+ (*main_struct)-> next;
	flag = (*stack_A)-> flag;
	while ((*stack_A)-> flag == flag)
	{
		if ((*stack_A)-> order > (*main_struct)-> mid)
		{
			rotate(&(*stack_A), 'A');
		}
		else
			push(&(*stack_A), &(*stack_B), 'B');
	}
	reverse_step(&(*stack_A), &(*stack_B), (*main_struct));
}

t_stack	*advanced_sort(t_stack *stack_A)
{
	t_stack	*stack_B;
	t_main	*main_struct;

	main_struct = malloc(sizeof(t_main));
	stack_B = NULL;
	main_struct -> next = 1;
	main_struct -> flag = 1;
	main_struct -> i = 2;
	while (!check_sort_stack(stack_A))
	{
		main_struct -> max = size_stack(stack_A);
		main_struct -> mid = (main_struct-> max - main_struct-> next) \
								/ 2 + main_struct-> next;
		step_0(&stack_A, &stack_B, &main_struct);
		step_1(&stack_A, &stack_B, &main_struct);
		while (!check_sort_stack_2(stack_A, main_struct-> i))
		{
			step_2(&stack_A, &stack_B, &main_struct);
			step_1(&stack_A, &stack_B, &main_struct);
		}
		main_struct-> i += 2;
	}
	free(main_struct);
	return (stack_A);
}
