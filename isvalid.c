
#include "list.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > INT_MAX / 10)
			|| (sign == 1  && result == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)
			|| (sign == -1 && result > INT_MAX / 10)
			|| (result == INT_MAX / 10 && str[i] - '0' > (INT_MAX % 10) + 1))
			return (-1 * (sign == 1));
		result = (result * 10) + (str[i++] - '0');
	}
	return (result * sign);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src || dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1) + 1;
	s2 = malloc(sizeof(char) * i);
	ft_strlcpy(s2, s1, i);
	return (s2);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || start >= ft_strlen(s) || !len)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
	{
		str = malloc((sizeof(char) * (ft_strlen(s) - start + 1)));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, ft_strlen(s) - start + 1);
	}
	else
	{
		str = malloc((sizeof(char) * len + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
	}
	return (str);
}

static int	wordcount(char *str, char sep)
{
	int	i;
	int	word;

	word = 0;
	i = 1;
	if (!*str)
		return (0);
	while (str[i])
	{
		if ((str[i] == sep && str[i - 1] != sep)
			|| (str[i] != sep && str[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**getwords(char **arr, char *s, char c, int word)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i] && k < word)
	{
		j = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			arr[k] = ft_substr(s, i, j);
			if (!arr[k])
				return (free_arr(arr));
			k++;
			i += j;
		}
		else
			i++;
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;

	if (!s)
		return (NULL);
	word = wordcount((char *)s, c);
	arr = malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (NULL);
	return (getwords(arr, (char *)s, c, word));
}
int	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] || (unsigned char)c == '\0')
	{
		if ((unsigned char)c == (unsigned char)s[i])
			return 1;
		i++;
	}
	return 0;
}

int is_integer(char *str)
{
	 if (ft_strlen(str) > 2 && ft_atoi(str) == 0 || ft_atoi(str) == -1)
	 			return (0);
		return (1);
}
int isnot_term(char *str)
{
	int i = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9' && (str[i + 1] == '+' || str[i + 1] == '-'))
			return 0;
		i++;
	}
	return (1);
}

int t_defence(char *str)
{
	int i = 0;
	int flag = 0;

	if (ft_strlen(str) > 2 && ft_atoi(str) == 0 || ft_atoi(str) == -1)
		return 0;
	while(str[i] == ' ')
		i++;	
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
		 (str[i] == '-' || str[i] == '+') && str[i + 1] >= '0' && str[i + 1] <= '9')
			flag = 1;
		 else if (flag && str[i] == ' ')
			flag = 1;
		else 
			return 0;
		i++;
	}
		return (flag);
}

int	main(int ac, char **av)
{
	int i;

	i = 1;
	char **splitted;
	t_list *node;
	while (i < ac)
	{
		if (t_defence(av[1]) && isnot_term(av[1]))
		{
			if (ft_strchr(av[1], ' '))
			{
				splitted = ft_split(av[1], ' ');
				while (splitted[i])
				{
					if (is_integer(av[1]) && is_double(av[1]))
					{
						node = malloc(sizeof(t_list));
						if (!node)
								return ;
						node -> next = NULL;
						while (node != NULL)
						{
							 -> data = ft_atoi(splitted[i]);
							point = point -> next;
						}	
						node -> data = ft_atoi(splitted[i]);
					}
					else
						write(2, "Error\n", 6);
				}
			}
				if (is_integer(av[1]))
				{
					node = malloc(sizeof(t_list));
					if (!node)
							return ;
					node -> data = ft_atoi(av[1]);
				}
				else 
					write(2, "Error\n", 6);
		}
		else
			write(2, "Error\n", 6);
		i++;
	}
}

// Notes:
		// examples:
// "1" convert 
// "+1"
// "-1" convert 
// "-" error
// " " error 
// "-1-" error
// "3 2 4 5 6" convert
// "3 2 3 4 5 6" error
// " 1- 1" error
// "1-1" error
// "1 -1" convert
// "1 - 1" error
// "++1" error 
// "--1" error
