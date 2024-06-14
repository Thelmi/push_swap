

#include <stdio.h>
#include "list.h"
static size_t ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
static int 	ft_atoi(const char *str)
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
static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
static char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1) + 1;
	s2 = malloc(sizeof(char) * i);
	ft_strlcpy(s2, s1, i);
	return (s2);
}
static char	*ft_substr(char const *s, unsigned int start, size_t len)
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

static char	**ft_split(char const *s, char c)
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
static int	ft_strchr(const char *s, int c)
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

static int is_integer(char *str)
{
	 if (ft_strlen(str) > 2 && (ft_atoi(str) == 0 || ft_atoi(str) == -1))
	 			return (0);
		return (1);
}
static int isnot_term(char *str)
{
	int i = 0;                //0                                    1                                2                                                 3                                              4
 	while (str[i])          // i = '-'         i + 1 = '1'         i = 1      i + 1 = ' '             i = ' '              i + 1 = '-'                  i = '-'              i + 1 = 2                 i = 2
	{
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == '+' || str[i + 1] == '-'))
			return 0;
		i++;
	}
	return (1);
}

static int t_defence(char *str)
{
	int i = 0;
	int flag = 0;


	//if (ft_strlen(str) > 2 && (ft_atoi(str) == 0 || ft_atoi(str) == -1))   // it only checks number - '0' 
	//	return 0;
	while(str[i] == ' ')
		i++;	
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
		 ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9')))
			flag = 1;
		 else if (flag && str[i] == ' ')
			flag = 1;
		else
		{

			return 0;
		}
		i++;
	}
	return (flag);
}
 Node* createNode(int value)
{
	Node* newnode = malloc(sizeof(Node));
	if(!newnode)
	{
		return NULL;
	}
	newnode -> data = value;
	newnode -> next = NULL;
	return newnode;
}
// void printlist(Node* list)
// {
// 	Node *tmp = list;
// 	while (tmp != NULL)
// 	{
// 		printf("data: %d\n max: %d\n min: %d\n ", tmp -> data, tmp ->bmax, tmp -> bmin);
// 		tmp = tmp -> next;
// 	}
// }
static void freelist(Node* list)
{
	Node *tmp = list;
	while(tmp != NULL)
	{
		tmp = list -> next;
		free(list);
		list = tmp;
	}
}
static void isdouble(Node* list)
{
	Node *tmp = list -> next;
	Node *store = list;
	while (list != NULL)
	{
		while (tmp != NULL)
		{
			if (list -> data == tmp -> data)
			{
				printf("error\n");
			    freelist(store);
			    exit(1);
			}	
			tmp = tmp -> next;
		}
		list = list ->next;
		if (list)
			tmp = list ->next;
	}
}
// int main(int ac ,char **av)
// {
// 	int i = 1;
// 	char **splitted;
// 	Node *head = NULL;
// 	Node *tmp;
// 	Node *nextnode;

// 	int j = 0;
// 	while(i < ac)
// 	{
// 		if (t_defence(av[i]) && isnot_term(av[i]))
// 		{
// 			if (ft_strchr(av[i], ' '))
// 			{
// 				splitted = ft_split(av[i], ' ');
// 				if(!head)
// 				{
// 			    	head = createNode(ft_atoi(splitted[0]));
// 					tmp = head;
// 					j = 1;
// 				}
// 				while (splitted[j])
// 				{
// 					nextnode = createNode(ft_atoi(splitted[j]));
// 					tmp -> next = nextnode;
// 					tmp = tmp -> next;
// 					j++;
// 				}
// 				j = 0;
// 				while (splitted[j])
// 				{
// 					free(splitted[j]);
// 					j++;
// 				}
// 				free(splitted);
// 				j = 0;
// 			}
// 			else 
// 			{
// 				if(!head)
// 				{
// 					head = createNode(ft_atoi(av[i]));
// 					tmp = head;
// 				}
// 				else 
// 				{
// 					nextnode = createNode(atoi(av[i]));
// 					tmp -> next = nextnode;
// 					tmp = nextnode;
// 				}
// 			}
// 		}
// 		else 
// 		{
// 			printf("error\n");
// 			freelist(head);
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	isdouble(head);
// 	printlist(head);
// 	freelist(head);
// }
Node *is_valid(int ac, char **av)
{
	int i = 1;
	char **splitted;
	int checked = 1;
	Node *head = NULL;
	Node *tmp;
	Node *nextnode;

	int j = 0;
	if (ac <= 1)
		exit(1);
	while(i < ac)
	{
		if (t_defence(av[i]) && isnot_term(av[i]))
		{
			if (ft_strchr(av[i], ' '))
			{
				splitted = ft_split(av[i], ' ');
				if (checked)
				{
				while (splitted[j] && checked)
				{
					if (!is_integer(splitted[j]))
					{
						printf("error");
						exit(0);
					}
					j++;
				}
					checked = 0;
				}
				j = 0;
				if(!head)
				{
			    	head = createNode(ft_atoi(splitted[0]));
					tmp = head;
					j = 1;
				}
				while (splitted[j])
				{
					nextnode = createNode(ft_atoi(splitted[j]));
					tmp -> next = nextnode;
					tmp = tmp -> next;
					j++;
				}
				j = 0;
				while (splitted[j])
				{
					free(splitted[j]);
					j++;
				}
				free(splitted);
				j = 0;
			}
			else 
			{
				if(!head)
				{
					head = createNode(ft_atoi(av[i]));
					tmp = head;
				}
				else 
				{
					nextnode = createNode(atoi(av[i]));
					tmp -> next = nextnode;
					tmp = nextnode;
				}
			}
		}
		else 
		{
			printf("error\n");
			freelist(head);
			exit(1);
		}
		i++;
	}
	isdouble(head);
	// printlist(head);
	return head;
	// freelist(head);
}
// int main(int ac, char **av)
// {
// 	is_valid(ac, av);
// }































































































// int	main(int ac, char **av)
// {
// 	int i = 1;
// 	char **splitted;
	
// 	while (i < ac)
// 	{
// 		if (t_defence(av[1]) && isnot_term(av[1]))
// 		{
// 			if (ft_strchr(av[1], ' '))
// 			{
// 				splitted = ft_split(av[1], ' ');
// 				while (splitted[i])
// 				{
// 					if (is_integer(av[1]) && is_double(av[1]))
// 					{
// 						while ()
// 						{

// 						}
// 					}
// 					else
// 						write(2, "Error\n", 6);
// 				}
// 			}
// 				if (is_integer(av[1]))
// 				{

// 				}
// 				else 
// 					write(2, "Error\n", 6);
// 		}
// 		else
// 			write(2, "Error\n", 6);
// 		i++;
// 	}
// }

// Notes:
// 		examples:
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