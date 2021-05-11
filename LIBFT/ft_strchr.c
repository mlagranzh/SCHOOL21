#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	while (*s != '\0')
	{
		if (*s == c)
		{
			p = (char *) s;
			return (p);
		}
		s++;
	}
	if (c == '\0')
	{
		p = (char *) s;
		return (p);
	}
	return (NULL);
}
