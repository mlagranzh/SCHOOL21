#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include "LIBFT/libft.h"

typedef struct s_stack
{
	int				flag;
	int				value;
	int				order;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*top;
	int				sort;
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

void	push(t_stack **stack_A, t_stack **stack_B, char *which_stack);
void	reverse_rotate(t_stack **lst, char *which_stack);
void	rotate(t_stack **lst, char *which_stack);
void	swap(t_stack **lst, char *which_stack);
void	reverse_rotate_r(t_stack **stack_A, t_stack **stack_B);
void	rotate_r(t_stack **stack_A, t_stack **stack_B);

t_stack	*simple_sort(t_stack *stack_A);
t_stack	*simple_sort_2(t_stack *stack_A);

int	size_stack(t_stack *stack);
int	max_stack(t_stack *stack_A);

#endif