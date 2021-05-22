#include "./Libft/libft.h"
#include "ft_printf.h"

t_list	*ft_list_print(t_list	*list, va_list argptr)
{
	if (list->specificator == 's')
		list = ft_printf_string(list, argptr);
	if (list->specificator == 'c')
		list = ft_printf_char(list, argptr);
	if (list->specificator == 'x')
		list = ft_printf_he(list, argptr, 'x');
	if (list->specificator == 'X')
		list = ft_printf_he(list, argptr, 'X');
	if (list->specificator == 'i' || list->specificator == 'd')
		list = ft_printf_decimal(list, argptr);
	if (list->specificator == 'u')
		list = ft_printf_unsigned(list, argptr);
	if (list->specificator == 'p')
		list = ft_printf_pointer(list, argptr);
	if (list->specificator == '%')
		list = ft_printf_procent(list);
	return (list);
}

t_list	*ft_zero_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->flags = (char) NULL;
	list->width = (int) NULL;
	list->precision = (int) NULL;
	list->specificator = (char) NULL;
	list->length = 0;
	return (list);
}

void	ft_putchar_list(char c, t_list *list)
{
	write(1, &c, 1);
	list->length++;
}

t_list	*ft_create_print_list(const char *string, va_list argptr, t_list *list)
{
	list->flags = ft_parser_flag(string);
	list->width = ft_parser_width(string, argptr);
	list->precision = ft_parser_precision(string, argptr);
	list->specificator = ft_parser_specificator(string);
	list->length = 0;
	string++;
	if (*string == ' ')
		ft_putchar_list(' ', list);
	list = ft_list_print(list, argptr);
	return (list);
}

int	ft_printf(const char *string, ...)
{
	va_list	argptr;
	char	*specificators;
	t_list	*list;
	int		output;

	output = 0;
	specificators = "cspdiuxX%";
	va_start(argptr, string);
	while (*string != '\0')
	{
		list = ft_zero_list();
		if (*string == '%')
		{
			list = ft_create_print_list(string++, argptr, list);
			while (!ft_strchr(specificators, *(string)))
				string++;
		}
		else
			ft_putchar_list(*string, list);
		output += list->length;
		string++;
		free(list);
	}
	va_end(argptr);
	return (output);
}
