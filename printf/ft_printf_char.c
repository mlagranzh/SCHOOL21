#include "./Libft/libft.h"
#include "ft_printf.h"

t_list	*ft_printf_procent(t_list	*list)
{
	int		count_space;
	char	a;

	a = '%';
	if (list->width < 0)
		list->width = -list->width;
	count_space = list->width - 1;
	if (list->flags == '-' || list->width < 0)
	{
		ft_putchar_list(a, list);
		while (count_space-- > 0)
			ft_putchar_list(' ', list);
		return (list);
	}
	else if (list -> flags == '0')
	{
		while (count_space-- > 0)
			ft_putchar_list('0', list);
		ft_putchar_list(a, list);
		return (list);
	}
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	ft_putchar_list(a, list);
	return (list);
}

t_list	*ft_printf_char(t_list *list, va_list argptr)
{
	int		count_space;
	char	a;

	a = (char) va_arg(argptr, int);
	count_space = 0;
	if (list->flags == '-' || list->width < 0)
	{
		if (list->width < 0)
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
	return (list);
}
