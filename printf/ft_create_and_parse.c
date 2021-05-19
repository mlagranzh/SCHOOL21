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
	while (!ft_char_in_string(specificators, *string) && *string != '.')
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
	while (!ft_char_in_string(specificators, *string) && *string != '.')
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
	return (-1); //значит флаг отсутствует
}

char	parser_specificator(const char *string)
{
	char	*specificators;

	specificators = "cspdiuxX";
	while (!ft_char_in_string(specificators, *string))
		string++;
	return (*string);
}

char *parser_parameters(char *string)
{
	char	*specificators;
	char output[3];
	specificators = "cspdiuxX";
	while (!ft_char_in_string(specificators, *string) && *string != '.')
	{
	string++;
	if (*string == '*')
	{
					output[0] = 'w';
	}
	if (ft_isdigit(*string) && *string != '0')
	{
					output[0] = 'w';
		}
}
	while (!ft_char_in_string(specificators, *string))
	{
	if (*string == '.')
	{
		string++;
		if (*string == '*')
		{
					output[1] = '.';

		}
		if (ft_isdigit(*string))
		{
					output[1] = '.';

		}
	}
			string++;
	}
		output[2] = '\0';
	return ("");
}
t_list	*ft_create_list(const char *string, va_list argptr)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->flags = parser_flag(string);
	list->width = parser_width(string, argptr);
	list->precision = parser_precision(string, argptr);
	list->specificator = parser_specificator(string);
	list->length = 0;
	list->parameters = parser_parameters((char *)string);
	return (list);
}
