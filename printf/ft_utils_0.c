#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_printable(t_list *list, int a)
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
