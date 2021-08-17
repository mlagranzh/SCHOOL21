#include "libft.h"

static int	ft_len_int(int n)
{
	unsigned int	number;
	int				count;

	count = 0;
	number = n;
	if (n < 0)
	{
		count++;
		number = -n;
	}
	else if (n == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	int				count_bytes;
	char			*p;

	count_bytes = ft_len_int(n);
	p = malloc(sizeof(char) * (count_bytes + 1));
	number = n;
	if (p == NULL)
		return (NULL);
	p[count_bytes] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		number = -n;
	}
	else if (n == 0)
		p[0] = '0';
	while (number > 0)
	{
		count_bytes--;
		p[count_bytes] = number % 10 + '0';
		number /= 10;
	}
	return (p);
}
