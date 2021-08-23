#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	k;
	size_t	len;

	k = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (k < (size - 1) && src[k] != '\0')
		{
			dst[k] = src[k];
			k++;
		}
		dst[k] = '\0';
	}
	while (src[len] != '\0')
		len++;
	return (len);
}
