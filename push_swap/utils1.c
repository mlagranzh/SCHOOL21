#include "push_swap.h"

int	count_not_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack -> flag != -1)
		stack = stack -> next;
	while (stack -> next != NULL)
	{
		if (stack -> order != (stack -> next -> order - 1))
		{
			while (stack -> next != NULL)
			{
				i++;
				stack = stack -> next;
			}
			return (i);
		}
		stack = stack -> next;
	}
	return (i);
}

int	*sort_array(int *array, int count)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 1;
	while (i < count)
	{
		j = 0;
		while (j < (count - i))
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	order_elem(int *array, int number)
{
	int	i;

	i = 0;
	while (array[i] != number)
		i++;
	return (i);
}

int	*copy_array(int *array1, int size)
{
	int	*array2;
	int	i;

	array2 = malloc(sizeof(int) * size);
	i = 0;
	while (size--)
	{
		array2[i] = array1[i];
		i++;
	}
	return (array2);
}

t_stack	*init_list(t_stack *lst, int *array, int size)
{
	int		*sorted_arr;
	t_stack	*p;
	int		i;

	i = 0;
	sorted_arr = copy_array(array, size);
	sorted_arr = sort_array(sorted_arr, size);
	lst = addelem(lst, array[i]);
	lst -> order = order_elem(sorted_arr, array[i]) + 1;
	lst -> flag = 0;
	p = lst;
	while (--size > 0)
	{
		i++;
		lst = addelem(lst, array[i]);
		lst -> order = order_elem(sorted_arr, array[i]) + 1;
		lst -> flag = 0;
	}
	free(sorted_arr);
	return (p);
}
