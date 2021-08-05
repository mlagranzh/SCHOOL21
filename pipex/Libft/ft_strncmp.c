#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	iter;

	iter = 0;
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && iter < n)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		iter++;
		s1++;
		s2++;
	}
	if (iter != n)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
