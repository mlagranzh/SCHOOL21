#include "./Libft/libft.h"
#include "ft_printf.h"

void printf_string(t_list	*list, va_list argptr)
{
  char *a;
  int count_space;

  count_space = 0;
  a = va_arg(argptr, char *);
  if (a == NULL)
    a = "(null)";
  if (list->flags == '-' || (list-> width < 0 && list -> width_true))
  {
    if (list-> width < 0 && list -> width_true)
      list->width = -list->width;
    if (list->precision >= 0)
    {
      write(1, a, min(ft_strlen(a), list->precision));
     list->length += min(ft_strlen(a), list->precision);
         count_space = list->width - min(ft_strlen(a), list->precision);
    }
    else
    {
          ft_putnstr_list(a, ft_strlen(a), list);
          count_space = list->width - ft_strlen(a);
    }
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
  }
  else
  {
    count_space = list->width - ft_strlen(a);
    if (list->precision >= 0)
      count_space = list->width - min(ft_strlen(a), list->precision);
    while (count_space-- > 0)
      ft_putchar_list(' ', list);
    if (list->precision >= 0)
    {
      write(1, a, min(ft_strlen(a), list->precision));
      list->length += min(ft_strlen(a), list->precision);
    }
    else
      ft_putnstr_list(a, ft_strlen(a), list);
  }
}
