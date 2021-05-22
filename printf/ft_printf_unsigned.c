#include "./Libft/libft.h"
#include "ft_printf.h"

t_list	*ft_printf_unsigned_minus(t_list *list, unsigned int	a)
{
	int				count_zero;
	int				count_space;

	if (list-> width < 0)
		list-> width = -(list-> width);
	count_zero = list->precision - ft_len_unsigned(a, 10);
	count_space = list->width - ft_len_unsigned(a, 10) \
	                          - ft_max(count_zero, 0) + ft_printable(list, a);
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (a != 0 || list->precision != 0)
		ft_put_unsigned_list(a, list);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	return (list);
}

t_list	*ft_printf_unsigned_zero(t_list *list, unsigned int	a)
{
	int				count_zero;
	int				count_space;

	if (list->precision >= 0)
		count_zero = list->precision - ft_len_unsigned(a, 10);
	else
		count_zero = list->width - ft_len_unsigned(a, 10);
	count_space = list->width - ft_max(0, count_zero) \
	                          - ft_len_unsigned(a, 10) + ft_printable(list, a);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (a != 0 || list->precision != 0)
		ft_put_unsigned_list(a, list);
	return (list);
}

t_list	*ft_printf_unsigned(t_list *list, va_list argptr)
{
	int				count_zero;
	int				count_space;
	unsigned int	a;

	a = va_arg(argptr, unsigned int);
	if (list->flags == '-' || list-> width < 0)
		return (ft_printf_unsigned_minus(list, a));
	else if (list->flags == '0')
		return (ft_printf_unsigned_zero(list, a));
	else
	{
		if (list->precision >= 0)
			count_zero = list->precision - ft_len_unsigned(a, 10);
		else
			count_zero = 0;
		count_space = list->width - ft_max(0, count_zero) - ft_len_unsigned(a, 10) \
		                          + ft_printable(list, a);
		while (count_space-- > 0)
			ft_putchar_list(' ', list);
		while (count_zero-- > 0)
			ft_putchar_list('0', list);
		if (a != 0 || list->precision != 0)
			ft_put_unsigned_list(a, list);
	}
	return (list);
}
