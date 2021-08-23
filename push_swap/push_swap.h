#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "LIBFT/libft.h"

typedef struct s_stack {
    int flag;
    int value;
    int order;
    struct s_stack *next;
    struct s_stack *prev;
    struct s_stack *top;
} t_stack;


typedef struct s_main_struct
{
    int next;
    int mid;
    int max;
    int flag;
    int *array;
    int count;
}  t_main;
