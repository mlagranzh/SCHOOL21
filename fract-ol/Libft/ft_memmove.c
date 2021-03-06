#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((!dest && !src) || n == 0)
		return ((void *)dest);
	if (src <= dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}
