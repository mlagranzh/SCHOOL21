#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;
	char			ch;

	if (n < 0)
	{
		write(fd, "-", 1);
		number = -n;
	}
	else
		number = n;
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ch = number % 10 + '0';
	write(fd, &ch, 1);
}
