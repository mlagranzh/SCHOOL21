#include "libft.h"

int	ft_memcmp (const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			k;

	a = (unsigned char *) arr1;
	b = (unsigned char *) arr2;
	k = 0;
	while (k < n)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
		k++;
	}
	return (0);
}
