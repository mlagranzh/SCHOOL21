#include "libft.h"

void	*ft_memchr (const void *arr, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;
	size_t			k;

	k = 0;
	p = (unsigned char *)arr;
	ch = (unsigned char)c;
	while (k < n)
	{
		if (*p == ch)
			return (p);
		k++;
		p++;
	}
	return (NULL);
}
