#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h> 

typedef struct s_stack
{
	int				flag;
	int				value;
	int				order;
	struct s_stack	*next;
}	t_stack;

typedef struct s_main_struct
{
	int	next;
	int	mid;
	int	max;
	int	flag;
	int	*array;
	int	count;
	int	i;
}	t_main;

void	push(t_stack **stack_A, t_stack **stack_B, char which_stack);
void	reverse_rotate(t_stack **lst, char which_stack);
void	rotate(t_stack **lst, char which_stack);
void	swap(t_stack **lst, char which_stack);
void	reverse_rotate_r(t_stack **stack_A, t_stack **stack_B);
void	rotate_r(t_stack **stack_A, t_stack **stack_B);

t_stack	*simple_sort(t_stack *stack_A);
t_stack	*simple_sort_2(t_stack *stack_A);

void	step_0(t_stack **stack_A, t_stack **stack_B, t_main **main_struct);
void	step_1(t_stack **stack_A, t_stack **stack_B, t_main **main_struct);
void	step_2(t_stack **stack_A, t_stack **stack_B, t_main **main_struct);
t_stack	*advanced_sort(t_stack *stack_A);
void	for_step_1(t_stack **stack_A, t_stack **stack_B, t_main **main_struct);

int		size_stack(t_stack *stack);
int		max_order(t_stack *stack);
int		check_sort_stack(t_stack *stack_A);
int		check_sort_stack_2(t_stack *stack_A, int i);
t_stack	*addelem(t_stack *lst, int number);

int		*sort_array(int *array, int count);
int		order_elem(int *array, int number);
int		*copy_array(int *array1, int size);
t_stack	*init_list(t_stack *lst, int *array, int size);
int		count_not_sort(t_stack *stack);

long	int	my_atoi(char *str);
int		my_isdigit(char	*string);
int		dublicate(int *array, int number, int i);
int		check_sort(int *array, int size);
void	for_step_1(t_stack **stack_A, t_stack **stack_B, t_main **main_struct);

int		ft_check_arguments(int argc, char **argv, int *array);
void	my_free(t_stack *stack_A, int *array);

#endif