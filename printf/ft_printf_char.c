#include "./Libft/libft.h"
#include "ft_printf.h"

void	printf_char(t_list *list, va_list argptr)
{
	int		count_space;
	char	a;

	a = (char) va_arg(argptr, int);
	count_space = 0;
	if (list->flags == '-' || list->width < -1)
	{
		if (list->width < -1)
			list->width = -list->width;
		ft_putchar_list(a, list);
		count_space = list->width - 1;
		while (count_space-- > 0)
			ft_putchar_list(' ', list);
	}
	else
	{
		count_space = list->width - 1;
		while (count_space-- > 0)
			ft_putchar_list(' ', list);
		ft_putchar_list(a, list);
	}
}
