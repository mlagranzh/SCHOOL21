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

void	swap(t_stack **lst, char *which_stack)
{
	t_stack	*tmp;

	tmp = *lst;
	*lst = (*lst)-> next;
	tmp -> next = (*lst)-> next;
	tmp -> prev = *lst;
	(*lst)-> next = tmp;
	(*lst)-> prev = NULL;
	if (which_stack == "A")
		write(1, "sa\n", 3);
	if (which_stack == "B")
		write(1, "sb\n", 3);
}

void	rotate(t_stack **lst, char *which_stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *lst;
	tmp2 = (*lst)-> next;
	while ((*lst)-> next != NULL)
		(*lst) = (*lst)-> next;
	tmp1 -> next = NULL;
	(*lst)-> next = tmp1;
	(*lst) = tmp2;
	if (which_stack == "A")
		write(1, "ra\n", 3);
	if (which_stack == "B")
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **lst, char *which_stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*lst);
	while ((*lst)-> next != NULL)
		(*lst) = (*lst)-> next;
	(*lst)-> next = tmp1;
	tmp2 = (*lst);
	while ((*lst)-> next != tmp2)
		(*lst) = (*lst)-> next;
	(*lst)-> next = NULL;
	(*lst) = tmp2;
	if (which_stack == "A")
		write(1, "rra\n", 4);
	if (which_stack == "B")
		write(1, "rrb\n", 4);
}

void	push(t_stack **stack_A, t_stack **stack_B, char *which_stack) //pop + add list
{
	t_stack	*tmp;

	if (which_stack == "A")
	{
		tmp = *stack_B;
		(*stack_B) = (*stack_B)-> next;
		tmp -> next = (*stack_A);
		(*stack_A) = tmp;
		(*stack_A)-> top = (*stack_A);
		write(1, "pa\n", 3);
	}
	if (which_stack == "B")
	{
		tmp = *stack_A;
		(*stack_A) = (*stack_A)-> next;
		tmp -> next = (*stack_B);
		(*stack_B) = tmp;
		(*stack_B)-> top = (*stack_B);
		write(1, "pb\n", 3);
	}
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
  while (stack_A -> next != NULL)
  {
    if (stack_A -> value > stack_A -> next -> value)
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

int	check_sort_stack_2(t_stack *stack_A, int i)
{
	int	number;
	
	number = size_stack(stack_A) / i;
	while (number--)
		stack_A = stack_A -> next;
	while (stack_A -> next -> next != NULL)
	{
		if (stack_A -> order > stack_A -> next -> order)
			return (0);
		stack_A = stack_A -> next;
	}
	return (1);
}

 void step_0(t_stack **stack_A, t_stack **stack_B, t_main **main_struct)
{
  int number = (*main_struct)->max - (*main_struct)->next + 1;
  while (number--)
  {
    
    if ((*stack_A) -> order <= (*main_struct)->mid)
      push(&(*stack_A), &(*stack_B), "B");
    else
      rotate(&(*stack_A), "A");
  }
}

int	count_not_sort(t_stack *stack)
{
	int	i;

	i = 0;
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
			rotate(&(*stack_A), "A");
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

t_stack	*middle_sort(t_stack *stack_A)
{
	t_stack	*stack_B;
	t_main	*main_struct;

	main_struct = malloc(sizeof(t_main));
	stack_B = NULL;
	main_struct->next = next_element(stack_A);
	main_struct->flag = 1;

    int i = 2;
    int k;
    int p = 0;
	while (!check_sort_stack(stack_A))
	{
		main_struct->max = size_stack(stack_A);
		main_struct->mid = (main_struct->max - main_struct->next) / 2 + main_struct->next;
		step_0(&stack_A, &stack_B, &main_struct);
		if (p != 0)
		{
			k = count_not_sort(stack_A);
			while (k--)
				reverse_rotate(&stack_A, "A");
		}
		step_1(&stack_A, &stack_B, &main_struct);
		while (!check_sort_stack_2(stack_A, i))
		{
			step_2(&stack_A, &stack_B, &main_struct);
			step_1(&stack_A, &stack_B, &main_struct);
		}
		i += 2;
		p++;
	}
	free(main_struct);
    // listprint(stack_A);
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

t_stack	*simple_sort(t_stack *stack_A)
{
	int	max;

	if (size_stack(stack_A) == 1)
		return (stack_A);
	else if (size_stack(stack_A) == 2)
	{
		if (stack_A -> value > stack_A -> next -> value)
			swap(&stack_A, "A");
		return (stack_A);
	}
	max = max_stack(stack_A);
	if (stack_A -> value == max)
		rotate(&stack_A, "A");
	if (stack_A -> next -> value == max)
		reverse_rotate(&stack_A, "A");
	if (stack_A -> value > stack_A -> next -> value)
		swap(&stack_A, "A");
	return (stack_A);
}

t_stack	*simple_sort_2(t_stack *stack_A)
{
	t_stack	*stack_B;

	if (size_stack(stack_A) == 5)
	{
		while ((stack_A -> order != 1) && (stack_A -> order != 2))
			rotate(&stack_A, "A");
		push(&stack_A, &stack_B, "B");
		while ((stack_A -> order != 1) && (stack_A -> order != 2))
			rotate(&stack_A, "A");
		push(&stack_A, &stack_B, "B");
		stack_A = simple_sort(stack_A);
		if (stack_B -> value < stack_B -> next -> value)
			swap(&stack_B, "B");
		push(&stack_A, &stack_B, "A");
		push(&stack_A, &stack_B, "A");
	}
	else
	{
		while (stack_A->order != 1)
			rotate(&stack_A, "A");
		push(&stack_A, &stack_B, "B");
		stack_A = simple_sort(stack_A);
		push(&stack_A, &stack_B, "A");
	}
	return (stack_A);
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
	else if (size <= 100)
		stack_A = middle_sort(stack_A);
	else
		stack_A = middle_sort(stack_A);
	all_free(stack_A, array);
	return (0);
}
