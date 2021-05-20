#include "./Libft/libft.h"
#include "ft_printf.h"

void printf_pointer(t_list *list, va_list argptr)
{
  list->width -= 2;
  printf_hexadecimal(list, argptr, 'p');
}

void printf_hexadecimal(t_list *list, va_list argptr, char ch)
{
  unsigned int a;
  char *to_write;
  int count_zero;
  a = va_arg(argptr, unsigned int);
  if (ch == 'X')
    to_write = ft_itoa_16(a, 32);
  else
      to_write = ft_itoa_16(a, 0);
  int count_space;
  if (list->flags == '-' ||  (list-> width < 0 && list -> width_true))
  {
    if (list-> width < 0 && list -> width_true)
      list-> width = -(list-> width);
    count_zero = list->precision - ft_strlen(to_write);
    count_space = list->width - ft_strlen(to_write) - max(count_zero, 0) + printable(list, a);
    while (count_zero-- > 0)
      ft_putchar_list('0', list);
    if (ch == 'p')
      ft_putnstr_list("0x", 2, list);
    if (a != 0 || list->precision != 0)
      ft_putnstr_list(to_write, ft_strlen(to_write), list);
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
  }
  else if (list->flags == '0' )
  {
    if (list->precision >= 0)
      count_zero = list->precision - ft_strlen(to_write);
    else
      count_zero = list->width - ft_strlen(to_write);
    count_space = list->width - max(0,count_zero) - ft_strlen(to_write) + printable(list, a);
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
    while (count_zero-- > 0)
      ft_putchar_list('0', list);
    if (ch == 'p')
      ft_putnstr_list("0x", 2, list);
    if (a != 0 || list->precision != 0)
      ft_putnstr_list(to_write, ft_strlen(to_write), list);
  }
  else
  {
    if (list->precision >= 0)
      count_zero = list->precision - ft_strlen(to_write);
    else
      count_zero = 0;
    count_space = list->width - max(0,count_zero) - ft_strlen(to_write) + printable(list, a);
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
    while (count_zero-- > 0)
      ft_putchar_list('0', list);
    if (ch == 'p')
      ft_putnstr_list("0x", 2, list);
    if (a != 0 || list->precision != 0)
      ft_putnstr_list(to_write, ft_strlen(to_write), list);
  }
}

char	*ft_itoa_16(unsigned int n, int ch)
{
	int				count_bytes;
	char			*p;
  unsigned int to_write;

	count_bytes = ft_len_unsigned_16(n);
	p = malloc(sizeof(char) * (count_bytes + 1));
	if (p == NULL)
		return (NULL);
	p[count_bytes] = '\0';
	if (n == 0)
		p[0] = '0';
	while (n > 0)
	{
		count_bytes--;
    to_write = n % 16;
    if (to_write == 10)
      p[count_bytes] = 'a' - ch;
    else if (to_write == 11)
      p[count_bytes] = 'b' - ch;
    else if (to_write == 12)
      p[count_bytes] = 'c' - ch;
    else if (to_write == 13)
      p[count_bytes] = 'd' - ch;
    else if (to_write == 14)
      p[count_bytes] = 'e' - ch;
    else if (to_write == 15)
      p[count_bytes] = 'f' - ch;
    else
		  p[count_bytes] = to_write + '0';
		n /= 16;
	}
	return (p);
}