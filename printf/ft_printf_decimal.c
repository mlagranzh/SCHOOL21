#include "./Libft/libft.h"
#include "ft_printf.h"

void printf_decimal(t_list *list, va_list argptr)
{
  int a;

  a = va_arg(argptr, int);
  int count_zero;
  int count_space;
  if (list->flags == '-' ||  ((list-> width < 0 && list -> width_true)))
  {
    if (list-> width < 0 && list -> width_true)
      list-> width = -(list-> width);
    count_zero = list->precision - ft_len_int_10(a);
    count_space = list->width - ft_len_int_10(a) - max(count_zero, 0);
    if (a < 0)
    {
      ft_putchar_list('-', list);
      count_space--;
    }
    while (count_zero-- > 0)
      ft_putchar_list('0', list);
    if (a == 0 && list->precision == 0)
      count_space = list->width;
    else
      ft_put_int_list(a, list);
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
  }
  else if (list->flags == '0')
  {
    if (list-> width < 0 && list -> width_true)
      list-> width = -(list-> width);
    if (list->precision >= 0)
      count_zero = list->precision - ft_len_int_10(a);
    else
      count_zero = list->width - ft_len_int_10(a) - ft_sign(a);
    count_space = list->width - max(0,count_zero) - ft_len_int_10(a) - ft_sign(a) ;
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
    if (a < 0)
      ft_putchar_list('-', list);
    while (count_zero-- > 0)
      ft_putchar_list('0', list);
    if (a != 0 || list->precision != 0)
      ft_put_int_list(a, list);
    else if (list->width > 0)
      ft_putchar_list(' ', list);
  }
  else
  {
    if (list->precision >= 0)
      count_zero = list->precision - ft_len_int_10(a);
    else
      count_zero = 0;
    count_space = list->width - max(0,count_zero) - ft_len_int_10(a) - ft_sign(a) + printable(list, a) ;
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
    if (a < 0)
      ft_putchar_list('-', list);
    while (count_zero-- > 0)
      ft_putchar_list('0', list);
    if (a != 0 || list->precision != 0)
      ft_put_int_list(a, list);
  }
}