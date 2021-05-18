#include "./Libft/libft.h"
#include "ft_printf.h"

int	count_arg(const char *string)
{
	int		i;
	int		count;
	char	*specificators;

	specificators = "cspdiuxX";
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			while (ft_isdigit(string[i]) || string[i] == '-' || \
			string[i] == '.' || string[i] == '*')
			{
				if (string[i] == '*')
					count++;
				i++;
			}
			if (ft_strchr(specificators, string[i]))
				count++;
		}
		i++;
	}
	return (count);
}

void	list_print(t_list	*list, va_list argptr)
{
	if (list->specificator == 's')
		printf_string(list, argptr);
	if (list->specificator == 'c')
		printf_char(list, argptr);
	if (list->specificator == 'x')
		printf_hexadecimal_x(list, argptr);
	if (list->specificator == 'X')
		printf_hexadecimal_X(list, argptr);
	if (list->specificator == 'i' || list->specificator == 'd')
		printf_decimal(list, argptr);
	if (list->specificator == 'u')
		printf_unsigned(list, argptr);
	if (list->specificator == 'p')
		printf_pointer(list, argptr);
	if (list->specificator == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *string, ...)
{
	va_list	argptr;
	char	*specificators;
	t_list	*list;

	specificators = "cspdiuxX%";
	string = (char *)string;
	va_start(argptr, string);
	while (*string != '\0')
	{
		if (*string == '%')
		{
			list = ft_create_list(string, argptr);
			list_print(list, argptr);
			string++;
			while (!ft_char_in_string(specificators, *string))
				string++;
		}
		else
			ft_putchar_fd(*string, 1);
		string++;
	}
	va_end(argptr);
	return (0);
}
