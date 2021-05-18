#include "./Libft/libft.h"
#include "ft_printf.h"

int	ft_char_in_string(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

void printf_pointer(t_list *list, va_list argptr)
{
  unsigned int a;
  char *to_write;
  int count_zero;
  a = va_arg(argptr, unsigned int);
  to_write = ft_itoa_16_X(a);
  int count_space;
  if (list->flags == '0')
  {
    count_zero = list->width - ft_strlen(to_write);
    count_space = 0;
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(ft_strjoin("0x",to_write), 1);
  }
  else if (list->flags == '-')
  {
    count_zero = list->precision - ft_strlen(to_write);
    count_space = list->width - ft_strlen(to_write);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(ft_strjoin("0x",to_write), 1);
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
  }
  else
  {
    count_zero = list->precision - ft_strlen(to_write);
    count_space = list->width - ft_strlen(to_write);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(ft_strjoin("0x",to_write), 1);
  }
}

void printf_hexadecimal_X(t_list *list, va_list argptr)
{
  unsigned int a;
  char *to_write;
  int count_zero;
  a = va_arg(argptr, unsigned int);
  to_write = ft_itoa_16_X(a);
  int count_space;
  if (list->flags == '0')
  {
    count_zero = list->width - ft_strlen(to_write);
    count_space = 0;
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(to_write, 1);
  }
  else if (list->flags == '-')
  {
    count_zero = list->precision - ft_strlen(to_write);
    count_space = list->width - ft_strlen(to_write);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(to_write, 1);
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
  }
  else
  {
    count_zero = list->precision - ft_strlen(to_write);
    count_space = list->width - ft_strlen(to_write);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(to_write, 1);
  }
}

void printf_hexadecimal_x(t_list *list, va_list argptr)
{
  unsigned int a;
  char *to_write;
  int count_zero;
  a = va_arg(argptr, unsigned int);
  to_write = ft_itoa_16_x(a);
  int count_space;
  if (list->flags == '0')
  {
    count_zero = list->width - ft_strlen(to_write);
    count_space = 0;
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(to_write, 1);
  }
  else if (list->flags == '-')
  {
    count_zero = list->precision - ft_strlen(to_write);
    count_space = list->width - ft_strlen(to_write);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(to_write, 1);
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
  }
  else
  {
    count_zero = list->precision - ft_strlen(to_write);
    count_space = list->width - ft_strlen(to_write);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putstr_fd(to_write, 1);
  }
}

char	*ft_itoa_16_X(unsigned int n)
{
	int				count_bytes;
	char			*p;
  unsigned int to_write;

	count_bytes = ft_len_int_16(n);
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
      p[count_bytes] = 'A';
    else if (to_write == 11)
      p[count_bytes] = 'B';
    else if (to_write == 12)
      p[count_bytes] = 'C';
    else if (to_write == 13)
      p[count_bytes] = 'D';
    else if (to_write == 14)
      p[count_bytes] = 'E';
    else if (to_write == 15)
      p[count_bytes] = 'F';
    else
		  p[count_bytes] = to_write + '0';
		n /= 16;
	}
	return (p);
}

char	*ft_itoa_16_x(unsigned int n)
{
	int				count_bytes;
	char			*p;
  unsigned int to_write;

	count_bytes = ft_len_int_16(n);
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
      p[count_bytes] = 'a';
    else if (to_write == 11)
      p[count_bytes] = 'b';
    else if (to_write == 12)
      p[count_bytes] = 'c';
    else if (to_write == 13)
      p[count_bytes] = 'd';
    else if (to_write == 14)
      p[count_bytes] = 'e';
    else if (to_write == 15)
      p[count_bytes] = 'f';
    else
		  p[count_bytes] = to_write + '0';
		n /= 16;
	}
	return (p);
}

void ft_putnstr_fd(char *a, int fd, int n)
{
  while (n-- > 0)
  {
    write(fd, &(*a), 1);
    a++;
  }
}

void printf_string(t_list	*list, va_list argptr)
{
  char *a;
  int count_space;

  count_space = 0;
  a = va_arg(argptr, char *);
  if (list->flags == '-')
  {
    if (list->precision >= 0)
      ft_putnstr_fd(a, 1, list->precision);
    else
      ft_putstr_fd(a, 1);
    count_space = list->width - ft_strlen(a);
    if (list->precision == 0)
      count_space--;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
  }
  else
  {
    count_space = list->width - ft_strlen(a);
    if (list->precision == 0)
      count_space = list->width;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    if (list->precision >= 0)
      ft_putnstr_fd(a, 1, list->precision);
    else
      ft_putstr_fd(a, 1);
  }
}

static int	ft_len_int_16(unsigned int n)
{
	int				count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

void printf_decimal(t_list *list, va_list argptr)
{
  int a;

  a = va_arg(argptr, int);
  int count_zero;
  int count_space;
  if (list->flags == '-' || list->width < 0)
  {
    list->width = -list->width;
    count_zero = list->precision - ft_len_int_10(a);
    count_space = list->width - ft_len_int_10(a);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    if (a < 0)
      ft_putchar_fd('-', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    if (a != 0 || list->precision != 0)
      ft_put_int_nbr_fd(a, 1);
    else if (list->width > 0)
      ft_putchar_fd(' ', 1);
    if (a < 0)
      count_space--;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
  }
  else if (list->flags == '0')
  {
    count_zero = list->width - ft_len_int_10(a);
    if (list->precision > -1)
      count_space = list->width - list->precision;
    else
      count_space = list->width;
    if (list->precision > 0 && list->precision < list->width)
      count_zero = list->precision - ft_len_int_10(a);
    if (a < 0)
      count_space -= 1;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    if (a < 0)
      ft_putchar_fd('-', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    if (a != 0 || list->precision != 0)
      ft_put_int_nbr_fd(a, 1);
    else if (list->width > 0)
      ft_putchar_fd(' ', 1);
  }
  else
  {
    count_zero = list->precision - ft_len_int_10(a);
    count_space = list->width - ft_len_int_10(a);
    if (list->precision > 0 && list->precision <= list->width)
      count_space = list->width - list->precision;
    if (a < 0)
      count_space -= 1;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    if (a < 0)
      ft_putchar_fd('-', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    if (a != 0 || list->precision != 0)
      ft_put_int_nbr_fd(a, 1);
    else if (list->width > 0)
      ft_putchar_fd(' ', 1);
  }
}

void printf_char(t_list *list, va_list argptr)
{
  char a;

  a = (char) va_arg(argptr, int);
  ft_putchar_fd(a, 1);
}

void	ft_put_int_nbr_fd(int n, int fd)
{
  unsigned int number;

  if (n < 0)
    number = -n;
  else
    number = n;
  ft_putnbr_unsigned_fd(number, 1); 
}

void ft_putnbr_unsigned_fd(unsigned int a, int fd)
{
  char ch;

	if (a >= 10)
		ft_putnbr_fd(a / 10, fd);
	ch = a % 10 + '0';
	write(fd, &ch, 1);
}

void printf_unsigned(t_list *list, va_list argptr)
{
  unsigned int a;

  a = va_arg(argptr, unsigned int);
  int count_zero;
  int count_space;
  if (list->flags == '0')
  {
    count_zero = list->width - ft_len_unsigned_10(a);
    count_space = list->width - list->precision;
    if (list->precision > 0 && list->precision < list->width)
      count_zero = list->precision - ft_len_unsigned_10(a);
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putnbr_unsigned_fd(a, 1);
  }
  else if (list->flags == '-')
  {
    count_zero = list->precision - ft_len_unsigned_10(a);
    count_space = list->width - ft_len_unsigned_10(a);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - max(ft_len_unsigned_10(a), list->precision);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putnbr_unsigned_fd(a, 1);
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
  }
  else
  {
    count_zero = list->precision - ft_len_unsigned_10(a);
    count_space = list->width - ft_len_unsigned_10(a);
    if (list->precision > 0 && list->precision < list->width)
      count_space = list->width - list->precision;
    while (count_space-- > 0)
      ft_putchar_fd(' ', 1);
    while (count_zero-- > 0)
      ft_putchar_fd('0', 1);
    ft_putnbr_unsigned_fd(a, 1);
  }
}

static int	ft_len_int_10(int n)
{
	int				count;

	count = 0;
  unsigned int number;
	if (n == 0)
		return (1);
  if (n < 0)
    number = -n;
  else
    number = n;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static int	ft_len_unsigned_10(unsigned number)
{
	int				count;

	count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}
