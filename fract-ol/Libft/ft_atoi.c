#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	output;
	int	minus;

	i = 0;
	output = 0;
	minus = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + str[i] - '0';
		i++;
	}
	if (minus == 1)
		return (output * (-1));
	return (output);
}
