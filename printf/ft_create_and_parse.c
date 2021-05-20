#include "./Libft/libft.h"
#include "ft_printf.h"

char	parser_flag(const char *string)
{
	int	i;

	i = 0;
	if (string[i + 1] == '-')
		return ('-');
	if (string[i + 1] == '0')
		return ('0');
	return ('/');
}

int	parser_width(const char *string, va_list argptr)
{
	int		width;
	char	*specificators;

	specificators = "cspdiuxX";
	while (!ft_strchr(specificators, *string) && *string != '.')
	{
		string++;
		if (*string == '*')
		{
			width = va_arg(argptr, int);
			return (width);
		}
		if (ft_isdigit(*string) && *string != '0')
		{
			width = ft_atoi((char *)string);
			return (width);
		}
	}
	return (-1);
}

int	parser_precision(const char *string, va_list argptr)
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

char	parser_specificator(const char *string)
{
	char	*specificators;

	specificators = "cspdiuxX%";
	string++;
	while (!ft_strchr(specificators, *string))
		string++;
	return (*string);
}

int	parser_width_true(const char *string)
{
	char	*specificators;

	specificators = "cspdiuxX";
	while (!ft_strchr(specificators, *string) && *string != '.')
	{
		string++;
		if (*string == '*')
		{
			return (1);
		}
		if (ft_isdigit(*string) && *string != '0')
		{
			return (1);
		}
	}
	return (0);
}

t_list	*ft_create_print_list(const char *string, va_list argptr)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->flags = parser_flag(string);
	list->width = parser_width(string, argptr);
	list->precision = parser_precision(string, argptr);
	list->specificator = parser_specificator(string);
	list->length = 0;
	list -> width_true = parser_width_true(string);
	list_print(list, argptr);
	return (list);
}
