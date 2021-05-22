#include "./Libft/libft.h"
#include "ft_printf.h"

t_list	*ft_printf_decimal_minus(t_list *list, int a)
{
	int	count_zero;
	int	count_space;

	if (list-> width < 0)
		list-> width = -(list-> width);
	count_zero = list->precision - ft_len_int(a);
	count_space = list->width - ft_len_int(a) - ft_max(count_zero, 0);
	if (a < 0)
	{
		ft_putchar_list('-', list);
		count_space--;
	}
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (a == 0 && list->precision == 0)
		count_space = list->width;
	else
		ft_put_int_list(a, list);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	return (list);
}

t_list	*ft_printf_decimal_zero(t_list *list, int a)
{
	int	count_space;
	int	count_zero;

	if (list-> width < 0)
		list-> width = -(list-> width);
	if (list->precision >= 0)
		count_zero = list->precision - ft_len_int(a);
	else
		count_zero = list->width - ft_len_int(a) - ft_sign(a);
	count_space = list->width - ft_max(0, count_zero) \
	                          - ft_len_int(a) - ft_sign(a);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	if (a < 0)
		ft_putchar_list('-', list);
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (a != 0 || list->precision != 0)
		ft_put_int_list(a, list);
	else if (list->width > 0)
		ft_putchar_list(' ', list);
	return (list);
}

t_list 	*ft_printf_decimal(t_list *list, va_list argptr)
{
	int	a;
	int	count_zero;
	int	count_space;

	a = va_arg(argptr, int);
	count_zero = 0;
	if (list->flags == '-' || list-> width < 0 )
		return (ft_printf_decimal_minus(list, a));
	else if (list->flags == '0')
		return (ft_printf_decimal_zero(list, a));
	if (list->precision >= 0)
		count_zero = list->precision - ft_len_int(a);
	count_space = list->width - ft_max(0, count_zero) - ft_len_int(a) \
	                          - ft_sign(a) + ft_printable(list, a);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	if (a < 0)
		ft_putchar_list('-', list);
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (a != 0 || list->precision != 0)
		ft_put_int_list(a, list);
	return (list);
}
