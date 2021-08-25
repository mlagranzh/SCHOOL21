#include "push_swap.h"

int	ft_dublicate(int *array, int number, int i)
{
	while (--i)
	{
		if (number == array[i - 1])
			return (1);
	}
	return (0);
}

t_stack * init(int a) // а- значение первого узла
{
    t_stack *lst;

    // выделение памяти под корень списка
    lst = malloc(sizeof(t_stack));
    lst->value = a;
    lst->next = NULL; // это последний узел списка
    lst->prev = NULL; // указатель на предыдущий узел
    return(lst);
}

t_stack *addelem(t_stack *lst, int number)
{
    if (lst == NULL)
    {
        t_stack *lst;

        // выделение памяти под корень списка
        lst = malloc(sizeof(t_stack));
        lst->value = number;
        lst->next = NULL; // это последний узел списка
        lst->prev = NULL; // указатель на предыдущий узел
        return(lst);
    }
    t_stack *temp, *p;
    temp = (struct list*)malloc(sizeof(t_stack));
    p = lst->next; // сохранение указателя на следующий узел
    lst->next = temp; // предыдущий узел указывает на создаваемый
    temp->value = number; // сохранение поля данных добавляемого узла
    temp->next = p; // созданный узел указывает на следующий узел
    temp->prev = lst; // созданный узел указывает на предыдущий узел
    if (p != NULL)
        p->prev = temp;
    return(temp);
}

void listprint(t_stack *lst) //печатает с конца
{
    t_stack *p;
    p = lst;
    do {
        printf("%d\n", lst->value); // вывод значения элемента p
        lst = lst->next; // переход к следующему узлу
    } while (lst != NULL);
}

int	ft_check_arguments(int argc, char **argv, int *array)
{
	int	i;
	int	number;

	i = 1;
	if (argc == 1)
		return (1);
	while (i != argc)
	{
		argv++;
		if (ft_isdigit(*argv))
			return (1);
		number = ft_atoi(*argv);
		if (ft_dublicate(array, number, i))
			return (1);
		array[i - 1] = number;
		i++;
	}
	return (0);
}

int	index_element_in_array(int *array, int number)
{
	int	i;

	i = 0;
	while (array[i] != number)
		i++;
	return (i);
}

int	*ft_sort_array(int *array, int count)
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

int *copy_array(int *array1, int size)
{
    int *array2 = malloc(sizeof(int) * size);
    int i = 0;
    while (size--)
    {
        array2[i] = array1[i];
        i++;
    }
    return (array2);
}

t_stack	*init_list(t_stack *lst, int *array, int size)
{
	int		*sort_array;
	t_stack	*p;

	sort_array = copy_array(array, size);
	sort_array = ft_sort_array(sort_array, size);
	lst = init(array[--size]);
	lst -> order = index_element_in_array(sort_array, array[size]) + 1;
	lst -> flag = 0;
	p = lst;
	while (--size >= 0)
	{
		lst = addelem(lst, array[size]);
		lst -> order = index_element_in_array(sort_array, array[size]) + 1;
		lst -> flag = 0;
	}
	free(sort_array);
	return (p);
}

int check_sort(int *array, int size)
{
    int i;

    i = 1;
    while (--size)
    {
        if (array[i] > array[i - 1])
            return (0);
        i++;
    }
    return (1);
}

int check_sort_stack(t_stack *stack_A)
{
  while (stack_A -> next -> next != NULL)
  {
    if (stack_A -> order != (stack_A -> next -> order - 1))
      return (0);
    stack_A = stack_A -> next;
  }
  return (1);
}


int max_order(t_stack *stack_B)
{
  int i = 0;

  while (stack_B != NULL)
  {
    if (i < stack_B -> order)
      i = stack_B -> order;
    stack_B = stack_B -> next;
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

//посмотреть эту функцию внимательно багована мне кажется
int	check_sort_stack_2(t_stack *stack_A, int i, t_main	*main_struct)
{
	int	number;
	
	number = size_stack(stack_A) / i;
	if (i != size_stack(stack_A))
		while (number--)
			stack_A = stack_A -> next;
	while (stack_A -> next -> next != NULL)
	{
		if (stack_A -> order  != (stack_A -> next -> order -1))
			return (0);
		stack_A = stack_A -> next;
	}
	return (1);
}
void	reverse_rotate_r(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*stack_A);
	while ((*stack_A)-> next != NULL)
		(*stack_A) = (*stack_A)-> next;
	(*stack_A)-> next = tmp1;
	tmp2 = (*stack_A);
	while ((*stack_A)-> next != tmp2)
		(*stack_A) = (*stack_A)-> next;
	(*stack_A)-> next = NULL;
	(*stack_A) = tmp2;
	tmp1 = (*stack_B);
	while ((*stack_B)-> next != NULL)
		(*stack_B) = (*stack_B)-> next;
	(*stack_B)-> next = tmp1;
	tmp2 = (*stack_B);
	while ((*stack_B)-> next != tmp2)
		(*stack_B) = (*stack_B)-> next;
	(*stack_B)-> next = NULL;
	(*stack_B) = tmp2;
	write(1, "rrr\n", 4);
}

void	rotate_r(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack_A;
	tmp2 = (*stack_A)-> next;
	while ((*stack_A)-> next != NULL)
		(*stack_A) = (*stack_A)-> next;
	tmp1 -> next = NULL;
	(*stack_A)-> next = tmp1;
	(*stack_A) = tmp2;
	tmp1 = *stack_B;
	tmp2 = (*stack_B)-> next;
	while ((*stack_B)-> next != NULL)
		(*stack_B) = (*stack_B)-> next;
	tmp1 -> next = NULL;
	(*stack_B)-> next = tmp1;
	(*stack_B) = tmp2;
	write(1, "rr\n", 3);
}

 void step_0(t_stack **stack_A, t_stack **stack_B, t_main **main_struct)
{
  int number = (*main_struct)->max - (*main_struct)->next + 1;
  while (number--)
  {
    
    if ((*stack_A) -> order <= (*main_struct)->mid)
      push(&(*stack_A), &(*stack_B), "B");
    else
	{
			if (size_stack((*stack_B)) >= 2 && ((*stack_B)-> order != (*main_struct) -> next))
			{
					rotate_r(&(*stack_A), &(*stack_B));
					continue;
			}
			rotate(&(*stack_A), "A");
	}
  }
}

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
//По условию в стек могут быть поданы только числа входящие в диапазон int, проверяйте на переполнение.
//Если в чекер подадут пустую строку он должен вывести \n.

int next_element(t_stack *stack_A)
{
  int i = 1;
  while (stack_A -> next != NULL)
  {
    if (stack_A -> order == (stack_A -> next -> order - 1))
      i++;
    else 
      i = 1;
    stack_A = stack_A -> next;
  }
  return (i);
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
		// if (((*main_struct) -> max / (*main_struct)-> i + 1) == size_stack((*stack_B)))
		// 	break;
		if ((*stack_A)-> order > (*main_struct)-> mid)
		{
			// if (size_stack((*stack_B)) >= 2 && ((*stack_B)-> order != (*main_struct) -> next))
			// {
			// 		rotate_r(&(*stack_A), &(*stack_B));
			// 		continue;
			// }
			rotate(&(*stack_A), "A");
		}
		else
			push(&(*stack_A), &(*stack_B), "B");
	}
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
			if ((*stack_B)-> order == (*main_struct)-> next)
			{
				push(&(*stack_A), &(*stack_B), "A");
				(*stack_A)-> flag = -1;
				rotate(&(*stack_A), "A");
				(*main_struct)->next += 1;
			}
			else if ((*stack_B)-> order < (*main_struct)-> mid)
				rotate(&(*stack_B), "B");
			else
			{
				push(&(*stack_A), &(*stack_B), "A");
				(*stack_A)-> flag = (*main_struct)-> flag;
			}
		}
		(*main_struct)->flag++;
	}
}
// 5 3 2 1 4 6
// 6 5 2 3 1 4
t_stack	*middle_sort(t_stack *stack_A)
{
	t_stack	*stack_B;
	t_main	*main_struct;

	main_struct = malloc(sizeof(t_main));
	stack_B = NULL;
	main_struct->next = 1;
	main_struct->flag = 1;

    main_struct-> i = 2;
    int k;
    int p = 0;
	if (stack_A->order == stack_A->next->order + 1)
		swap(&stack_A, "A");
	while (!check_sort_stack(stack_A))
	{
		write(1, "A", 1);
		main_struct->max = size_stack(stack_A);
		main_struct-> mid = (main_struct-> max - main_struct-> next) / 2 + main_struct-> next;
		step_0(&stack_A, &stack_B, &main_struct);
		if (p != 0)
		{
			k = count_not_sort(stack_A);
			while (k--)
			{
				// if (k == size_stack(stack_A))
				// {
				// 	rotate(&(*stack_A), "A");
				// 	break;
				// }
				if (stack_B -> order != main_struct->next)
				{
					reverse_rotate_r(&stack_A, &stack_B);
					continue ;
				}
				reverse_rotate(&stack_A, "A");
			}
		}
		step_1(&stack_A, &stack_B, &main_struct);
		if (check_sort_stack(stack_A))
			break;
		while (!check_sort_stack_2(stack_A, main_struct-> i, main_struct))
		{
			step_2(&stack_A, &stack_B, &main_struct);
					if (p != 0)
		{
			k = count_not_sort(stack_A);
			while (k--)
			{
				// if (k == size_stack(stack_A))
				// {
				// 	rotate(&(*stack_A), "A");
				// 	break;
				// }
				if (stack_B -> order != main_struct->next)
				{
					reverse_rotate_r(&stack_A, &stack_B);
					continue ;
				}
				reverse_rotate(&stack_A, "A");
			}
		}

			step_1(&stack_A, &stack_B, &main_struct);
		}
		main_struct-> i += 2;
		p++;
	}
	free(main_struct);
    //  listprint(stack_A);
    return (stack_A);
}

t_stack *advanced_sort(t_stack *stack_A)
{

}

int max_stack(t_stack *stack_A)
{
    int k;
    k = stack_A -> value;
    while (stack_A != NULL)
    {
        if (stack_A -> value > k)
            k = stack_A -> value;
        stack_A = stack_A -> next;
    }
    return (k);
}

void	all_free(t_stack *stack_A, int *array)
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
	int		size;
	t_stack	*stack_A;

	size = argc - 1;
	array = malloc((argc - 1) * sizeof(int));
	if (ft_check_arguments(argc, argv, array))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_sort(array, size))
		return (0);
	stack_A = init_list(stack_A, array, size);
	if (size <= 3)
		stack_A = simple_sort(stack_A);
	else if (size <= 5)
		stack_A = simple_sort_2(stack_A);
	else
		stack_A = middle_sort(stack_A);
	all_free(stack_A, array);
	return (0);
}