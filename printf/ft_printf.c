#include "./Libft/libft.h"
#include "ft_printf.h"

void	list_print(t_list	*list, va_list argptr)
{
	if (list->specificator == 's')
		printf_string(list, argptr);
	if (list->specificator == 'c')
		printf_char(list, argptr);
	if (list->specificator == 'x')
		printf_hexadecimal(list, argptr, 'x');
	if (list->specificator == 'X')
		printf_hexadecimal(list, argptr, 'X');
	if (list->specificator == 'i' || list->specificator == 'd')
		printf_decimal(list, argptr);
	if (list->specificator == 'u')
		printf_unsigned(list, argptr);
	if (list->specificator == 'p')
		printf_pointer(list, argptr);
	if (list->specificator == '%')
		ft_putchar_list('%', list);//printf_procent(list);
}

void printf_procent(t_list *list)
{
  int count_space;

  count_space = 0;
  if (list->flags == '-' || (list-> width < 0 && list -> width_true))
  {
	count_space = list->width - 1;
    if (list-> width < 0 && list -> width_true)
      list->width = -list->width;
	ft_putchar_list('%', list);
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
  }
  else
  {
    count_space = list->width - 1;
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
	ft_putchar_list('%', list);
  }
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
	list->width_true = 0;
	return (list);
}

void	ft_putchar_list(char c, t_list *list)
{
	write(1, &c, 1);
	list->length++;
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
			list = ft_create_print_list(string, argptr);
			string++;
			while (!ft_strchr(specificators, *string))
				string++;
		}
		else
			ft_putchar_list(*string, list);
		output += list->length;
		string++;
	}
	va_end(argptr);
	return (output);
}
