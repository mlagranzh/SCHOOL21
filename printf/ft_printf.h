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
}					t_list;

t_list	*ft_printf_string_minus(t_list	*list, char *a);
t_list	*ft_printf_he_minus(t_list *list, char *to_write, \
							char ch, unsigned long a);
t_list	*ft_printf_he_zero(t_list *list, char *to_write, \
							char ch, unsigned long a);
t_list	*ft_printf_he_nozerominus(t_list *list, char *to_write, \
								 char ch, unsigned long a);
int		ft_sign(int a);
t_list	*ft_printf_unsigned_minus(t_list *list, unsigned int a);
t_list	*ft_printf_unsigned_zero(t_list *list, unsigned int	a);
int		ft_its_pointer(char ch);
t_list	*ft_printf_decimal_minus(t_list *list, int a);
t_list	*ft_printf_decimal_zero(t_list *list, int a);
void	ft_putchar_list(char c, t_list *list);
void	ft_putnstr_list(char *s, int n, t_list *list);
t_list	*ft_printf_procent(t_list *list);
int		ft_min(int a, int b);
int		ft_printable(t_list *list, int a);
int		ft_printf(const char *string,	...);
t_list	*ft_list_print(t_list	*list, va_list argptr);
char	ft_parser_flag(const char *string);
int		ft_parser_width(const char *string, va_list argptr);
int		ft_parser_precision(const char *string, va_list argptr);
char	ft_parser_specificator(const char *string);
t_list	*ft_create_print_list(const char *string, va_list argptr, t_list *list);
t_list	*ft_printf_pointer(t_list *list, va_list argptr);
t_list	*ft_printf_he(t_list *list, va_list argptr, char ch);
char	*ft_itoa_16(unsigned long n, int ch);
t_list	*ft_printf_string(t_list	*list, va_list argptr);
t_list	*ft_printf_decimal(t_list *list, va_list argptr);
t_list	*ft_printf_char(t_list *list, va_list argptr);
void	ft_put_int_list(int n, t_list *list);
t_list	*ft_printf_unsigned(t_list *list, va_list argptr);
int		ft_len_int(int n);
int		ft_len_unsigned(unsigned long number, int base);
int		ft_max(int a, int b);
void	ft_put_unsigned_list(unsigned int a, t_list *list);
#endif
