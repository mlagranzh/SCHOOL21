#include "./Libft/libft.h"
#include "ft_printf.h"

t_list	*ft_printf_he_minus(t_list *list, char *to_write, \
													  char ch, unsigned long a)
{
	int	count_zero;
	int	count_space;

	if (list-> width < 0)
		list-> width = -(list-> width);
	count_zero = list->precision - ft_strlen(to_write);
	count_space = list->width - ft_strlen(to_write) - ft_max(count_zero, 0) \
	                          + ft_printable(list, a) - ft_its_pointer(ch);
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (ch == 'p')
		ft_putnstr_list("0x", 2, list);
	if (a != 0 || list->precision != 0)
		ft_putnstr_list(to_write, ft_strlen(to_write), list);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	return (list);
}

t_list	*ft_printf_he_zero(t_list *list, char *to_write, \
											     char ch, unsigned long a)
{
	int	count_zero;
	int	count_space;

	if (list->precision >= 0)
		count_zero = list->precision - ft_strlen(to_write);
	else
		count_zero = list->width - ft_strlen(to_write);
	count_space = list->width - ft_max(0, count_zero) - ft_strlen(to_write) \
	                          + ft_printable(list, a) - ft_its_pointer(ch);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (ch == 'p')
		ft_putnstr_list("0x", 2, list);
	if (a != 0 || list->precision != 0)
		ft_putnstr_list(to_write, ft_strlen(to_write), list);
	return (list);
}

t_list	*ft_printf_he_nozerominus(t_list *list, char *to_write, \
											     char ch, unsigned long a)
{
	int	count_zero;
	int	count_space;

	if (list->precision >= 0)
		count_zero = list->precision - ft_strlen(to_write);
	else
		count_zero = 0;
	count_space = list->width - ft_max(0, count_zero) - ft_strlen(to_write) \
	                          + ft_printable(list, a) - ft_its_pointer(ch);
	while (count_space-- > 0)
		ft_putchar_list(' ', list);
	while (count_zero-- > 0)
		ft_putchar_list('0', list);
	if (ch == 'p')
		ft_putnstr_list("0x", 2, list);
	if (a != 0 || list->precision != 0)
		ft_putnstr_list(to_write, ft_strlen(to_write), list);
	return (list);
}

t_list	*ft_printf_he(t_list *list, va_list argptr, char ch)
{
	unsigned long	a;
	char			*to_write;

	if (ch == 'p')
		a = va_arg(argptr, unsigned long);
	else
		a = va_arg(argptr, unsigned int);
	if (ch == 'X')
		to_write = ft_itoa_16(a, 32);
	else
		to_write = ft_itoa_16(a, 0);
	if (list->flags == '-' || list-> width < 0)
		list = ft_printf_he_minus(list, to_write, ch, a);
	else if (list->flags == '0' )
		list = ft_printf_he_zero(list, to_write, ch, a);
	else
		list = ft_printf_he_nozerominus(list, to_write, ch, a);
	free(to_write);
	return (list);
}

char	*ft_itoa_16(unsigned long n, int ch)
{
	int				count_bytes;
	char			*p;
	unsigned long	to_write;

	count_bytes = ft_len_unsigned(n, 16);
	p = malloc(sizeof(char) * (count_bytes + 1));
	if (p == NULL)
		return (NULL);
	p[count_bytes] = '\0';
	if (n == 0)
		p[0] = '0';
	while (n > 0)
	{
		count_bytes--;
		to_write = n % 16;
		if (to_write == 10 || to_write == 11 || to_write == 12 || \
				to_write == 13 || to_write == 14 || to_write == 15)
			p[count_bytes] = 'a' + to_write % 10 - ch;
		else
			p[count_bytes] = to_write + '0';
		n /= 16;
	}
	return (p);
}
