#include "push_swap.h"

long int	my_atoi(char *str)
{
	int			i;
	long int	output;
	int			minus;

	i = 0;
	output = 0;
	minus = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + str[i] - '0';
		i++;
	}
	return (output * minus);
}

int	my_isdigit(char *string)
{
	if (*string == '-' || *string == '+')
		string++;
	while (*string != '\0')
	{
		if (!(*string >= 48 && *string <= 57))
			return (0);
		string++;
	}
	return (1);
}

int	check_sort(int *array, int size)
{
	int	i;

	i = 0;
	while (--size)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	dublicate(int *array, int number, int i)
{
	while (--i)
	{
		if (number == array[i - 1])
			return (1);
	}
	return (0);
}

void	for_step_1(t_stack **stack_A, t_stack **stack_B, t_main **main_struct)
{
	if ((*stack_B)-> order == (*main_struct)-> next)
	{
		push(&(*stack_A), &(*stack_B), 'A');
		(*stack_A)-> flag = -1;
		rotate(&(*stack_A), 'A');
		(*main_struct)->next += 1;
	}
	else if ((*stack_B)-> order < (*main_struct)-> mid)
		rotate(&(*stack_B), 'B');
	else
	{
		push(&(*stack_A), &(*stack_B), 'A');
		(*stack_A)-> flag = (*main_struct)-> flag;
	}
}
