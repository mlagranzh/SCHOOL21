#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	size_t			k;

	k = 0;
	p = (unsigned char *)dest;
	if (!(dest) && !(src))
		return (NULL);
	while (k != n)
	{
		p[k] = ((unsigned char *)src)[k];
		k++;
	}
	return (p);
}
