#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	p = malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i != len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
