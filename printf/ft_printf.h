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
}					t_list;

int	ft_printf(const char *, ...);
int	count_arg(const char *string);
void	list_print(t_list	*list, va_list argptr);
char	parser_flag(const char *string);
int	parser_width(const char *string, va_list argptr);
int	parser_precision(const char *string, va_list argptr);
char	parser_specificator(const char *string);
t_list	*ft_create_list(const char *string, va_list argptr);
void printf_pointer(t_list *list, va_list argptr);
void printf_hexadecimal_X(t_list *list, va_list argptr);
void printf_hexadecimal_x(t_list *list, va_list argptr);
int	ft_char_in_string(const char *s, int c);
char	*ft_itoa_16_X(unsigned int n);
char	*ft_itoa_16_x(unsigned int n);
void ft_putnstr_fd(char *a, int fd, int n);
void printf_string(t_list	*list, va_list argptr);
int	ft_len_int_16(unsigned int n);
void printf_decimal(t_list *list, va_list argptr);
void printf_char(t_list *list, va_list argptr);
void	ft_put_int_nbr_fd(int n, int fd);
void printf_unsigned(t_list *list, va_list argptr);
int	ft_len_int_10(int n);
int	ft_len_unsigned_10(unsigned number);
int max(int a, int b);
void ft_putnbr_unsigned_fd(unsigned int a, int fd);

#endif