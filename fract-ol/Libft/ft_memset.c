#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			k;

	k = 0;
	p = (unsigned char *) b;
	while (k != len)
	{
		p[k] = (unsigned char)c;
		k++;
	}
	return (b);
}
