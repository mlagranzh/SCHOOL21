#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	char			flags;
	int				width;
	int				precision;
	char			specificator;
	int				length;
	int				width_true;
}					t_list;
int     parser_width_true(const char *string);
  int ft_sign(int a);
void	ft_putchar_list(char c, t_list *list);
void ft_putnstr_list(char *s, int n, t_list *list);
  int min(int a, int b);
int printable(t_list *list, unsigned int a);
int	ft_printf(const char *, ...);
int	count_arg(const char *string);
void	list_print(t_list	*list, va_list argptr);
char	parser_flag(const char *string);
int	parser_width(const char *string, va_list argptr);
int	parser_precision(const char *string, va_list argptr);
char	parser_specificator(const char *string);
t_list * ft_create_print_list(const char *string, va_list argptr);
void printf_pointer(t_list *list, va_list argptr);
void printf_hexadecimal(t_list *list, va_list argptr, char ch);
char	*ft_itoa_16(unsigned int n, int ch);
void printf_string(t_list	*list, va_list argptr);
int	ft_len_unsigned_16(unsigned int number);
void printf_decimal(t_list *list, va_list argptr);
void printf_char(t_list *list, va_list argptr);
void	ft_put_int_list(int n, t_list *list);
void printf_unsigned(t_list *list, va_list argptr);
int	ft_len_int_10(int n);
int	ft_len_unsigned_10(unsigned number);
int max(int a, int b);
void	ft_put_unsigned_list(unsigned int a, t_list *list);
#endif