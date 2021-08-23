#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			p = (char *) s;
		s++;
	}
	if (c == '\0')
	{
		p = (char *) s;
		return (p);
	}
	return (p);
}
