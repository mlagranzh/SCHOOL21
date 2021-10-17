/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:17:33 by celys             #+#    #+#             */
/*   Updated: 2021/10/17 18:17:35 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

int	ft_atoi(char *str)
{
	int	i;
	int	output;
	int	minus;

	i = 0;
	output = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + str[i] - '0';
		i++;
	}
	return (output * minus);
}

long int	my_atoi(char *str)
{
	int			i;
	long int	output;
	int			minus;

	i = 0;
	output = 0;
	minus = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + str[i] - '0';
		i++;
	}
	return (output * minus);
}

int	my_isdigit(char *string)
{
	if (*string == '-' || *string == '+')
		string++;
	while (*string != '\0')
	{
		if (!(*string >= '0' && *string <= '9'))
			return (0);
		string++;
	}
	return (1);
}

int	parse_error(int argc, char **argv)
{
	int			i;
	long int	number;

	if (!(argc == 5 || argc == 6))
		return (1);
	i = 1;
	while (i != argc)
	{
		argv++;
		if (!my_isdigit(*argv))
			return (1);
		number = my_atoi(*argv);
		if (number > 2147483647 || number < -2147483648)
			return (1);
		i++;
	}
	return (0);
}
