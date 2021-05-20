#include "ft_printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	printable(t_list *list, unsigned int a)
{
	if (list->precision == 0 && a == 0)
		return (1);
	else
		return (0);
}

int	ft_sign(int a)
{
	if (a < 0)
		return (1);
	else
		return (0);
}

void	ft_put_int_list(int n, t_list *list)
{
	unsigned int	number;

	if (n < 0)
		number = -n;
	else
		number = n;
	ft_put_unsigned_list(number, list);
}
