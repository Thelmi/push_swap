// create a program that takes any number of arguements and checks if each argument is valid 
// or not to convert to an integer... if its valid turn it to an integers if it not write
// error 

// Note: doubles counted as an error

// examples:
// "1" convert 
// "-1" convert 
// "-" error
// " " error 
// "-1-" error
// "3 2 4 5 6" convert
// "3 2 3 4 5 6" error
// " 1- 1" error
// "1 -1" convert
// "1 - 1" error
// "++1" error 
// "--1" error


t_defence(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' || str[i] <= '9' ))
		{

		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (t_defence(av[i]))
		{
			
		}
		i++;
	}
}

