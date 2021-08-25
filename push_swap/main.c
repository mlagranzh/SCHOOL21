#include "push_swap.h"

int	ft_check_arguments(int argc, char **argv, int *array)
{
	int			i;
	long int	number;

	i = 1;
	if (argc == 1)
		return (1);
	while (i != argc)
	{
		argv++;
		if (!my_isdigit(*argv))
			return (1);
		number = my_atoi(*argv);
		if (number > 2147483647 || number < -2147483648)
			return (1);
		if (dublicate(array, number, i))
			return (1);
		array[i - 1] = number;
		i++;
	}
	return (0);
}

void	my_free(t_stack *stack_A, int *array)
{
	while (stack_A -> next != NULL)
	{
		free(stack_A);
		stack_A = stack_A -> next;
	}
	free(stack_A);
	free(array);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_stack	*stack_A;

	array = malloc((argc - 1) * sizeof(int));
	if (ft_check_arguments(argc, argv, array) && argc != 1)
	{
		write(2, "Error\n", 6);
		free(array);
		return (0);
	}
	if (check_sort(array, (argc - 1)) || argc == 1)
	{
		free(array);
		return (0);
	}
	stack_A = NULL;
	stack_A = init_list(stack_A, array, (argc - 1));
	if ((argc - 1) <= 3)
		stack_A = simple_sort(stack_A);
	else if ((argc - 1) <= 5)
		stack_A = simple_sort_2(stack_A);
	else
		stack_A = advanced_sort(stack_A);
	my_free(stack_A, array);
	return (0);
}
