#include "./Libft/libft.h"
#include "ft_printf.h"

t_list	*ft_printf_pointer(t_list *list, va_list argptr)
{
	list = ft_printf_he(list, argptr, 'p');
	return (list);
}

t_list	*ft_printf_string_minus(t_list	*list, char *a)
{
	int	count_space;

	count_space = 0;
	if (list-> width < 0)
		list->width = -list->width;
	if (list->precision >= 0)
	{
		write(1, a, ft_min(ft_strlen(a), list->precision));
		list->length += ft_min(ft_strlen(a), list->precision);
		count_space = list->width - ft_min(ft_strlen(a), list->precision);
	}
	else
	{
		ft_putnstr_list(a, ft_strlen(a), list);
		count_space = list->width - ft_strlen(a);
	}
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	return (list);
}

t_list	*ft_printf_string(t_list	*list, va_list argptr)
{
	char	*a;
	int		count_space;

	count_space = 0;
	a = va_arg(argptr, char *);
	if (a == NULL)
		a = "(null)";
	if (list->flags == '-' || list-> width < 0 )
		return (ft_printf_string_minus(list, a));
	else
	{
		count_space = list->width - ft_strlen(a);
		if (list->precision >= 0)
			count_space = list->width - ft_min(ft_strlen(a), list->precision);
		while (count_space-- > 0)
			ft_putchar_list(' ', list);
		if (list->precision >= 0)
		{
			write(1, a, ft_min(ft_strlen(a), list->precision));
			list->length += ft_min(ft_strlen(a), list->precision);
		}
		else
			ft_putnstr_list(a, ft_strlen(a), list);
	}
	return (list);
}
