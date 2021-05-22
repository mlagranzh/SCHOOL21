#include "ft_printf.h"

int	ft_len_unsigned(unsigned long number, int base)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= base;
		count++;
	}
	return (count);
}

int	ft_len_int(int n)
{
	unsigned int	number;
	int				count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		number = -n;
	else
		number = n;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

void	ft_putnstr_list(char *s, int n, t_list *list)
{
	while (n-- > 0)
	{
		write(1, &(*s), 1);
		s++;
		list->length++;
	}
}

void	ft_put_unsigned_list(unsigned int a, t_list *list)
{
	char	ch;

	if (a >= 10)
		ft_put_unsigned_list(a / 10, list);
	ch = a % 10 + '0';
	write(1, &ch, 1);
	list->length++;
}

int	ft_its_pointer(char ch)
{
	if (ch == 'p')
		return (2);
	else
		return (0);
}
