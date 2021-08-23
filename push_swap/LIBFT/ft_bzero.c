#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	size_t	k;

	k = 0;
	while (k != len)
	{
		((char *)b)[k] = 0;
		k++;
	}
}
