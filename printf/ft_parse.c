#include "./Libft/libft.h"
#include "ft_printf.h"

char	ft_parser_flag(const char *string)
{
	if (string[1] == '-')
		return ('-');
	if (string[1] == '0')
		return ('0');
	return ('/');
}

int	ft_parser_width(const char *string, va_list argptr)
{
	char	*specificators;
	int		i;

	i = 1;
	specificators = "cspdiuxX%";
	while (string[i] == '-' || string[i] == '0')
		i++;
	while (!ft_strchr(specificators, string[i]) && string[i] != '.')
	{
		if (string[i] == '*')
		{
			if (string[i - 1] == '-' && string[i - 2] != '%')
				return (-(va_arg(argptr, int)));
			return (va_arg(argptr, int));
		}
		if (ft_isdigit(string[i]) || string[i] == '-')
		{
			if (string[i - 1] == '-' && string[i - 2] != '%')
				return (-(ft_atoi((char *)(string + i))));
			return (ft_atoi((char *)(string + i)));
		}
		i++;
	}
	return (0);
}

int	ft_parser_precision(const char *string, va_list argptr)
{
	int		precision;
	char	*specificators;

	specificators = "cspdiuxX";
	while (!ft_strchr(specificators, *string) && *string != '.')
		string++;
	if (*string == '.')
	{
		string++;
		if (*string == '*')
		{
			precision = va_arg(argptr, int);
			return (precision);
		}
		if (ft_isdigit(*string))
		{
			precision = ft_atoi((char *)string);
			return (precision);
		}
		return (0);
	}
	return (-1);
}

char	ft_parser_specificator(const char *string)
{
	char	*specificators;

	specificators = "cspdiuxX%";
	string++;
	while (!ft_strchr(specificators, *string))
		string++;
	return (*string);
}
