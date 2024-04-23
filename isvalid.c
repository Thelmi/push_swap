// Task: Command-Line Argument Validation

// Create a program that validates command-line arguments for conversion to integers. Follow these guidelines:

// Input: Accept any number of command-line arguments.
// Validation: Check each argument to ensure it can be converted to an integer.
// Conversion: Convert valid arguments to integers.
// Output: Provide clear feedback for each argument:
// Valid integers: Print the integer value.
// Invalid inputs: Print an error message indicating the reason.
// Examples:

// "1" - Convert and print: 1
// "-1" - Convert and print: -1
// "-" - Invalid input: "Error: Invalid input: -"
// " " - Invalid input: "Error: Invalid input: "
// "3 2 4 5 6" - Convert and print: 3, 2, 4, 5, 6
// "++1" - Invalid input: "Error: Invalid input: ++1"
// Objective: Develop a program that accurately validates and converts
//  command-line arguments, providing clear feedback for each input.

// This condensed version retains the essential elements of the task 
// while making the description shorter and more straightforward. It still provides clear examples
//  and guidelines for the required functionality,
//  helping users understand the task efficiently.
#include <unistd.h>
// int t_defence(char *str)
// {
// 	int i = 0;
// 	int flag = 0;

// 	while (str[i] == ' ')
// 		i++;
// 	while (str[i])
// 	{
// 		while (str[i] == '-' || str[i] == '+')
// 		{
// 				i++;
// 			if ((!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-' && str[i] != ' ' ) || str[i] == '\0')
// 				return 0;
// 		}
// 		while (str[i] >= '0' && str[i] <= '9')
// 			{
// 				flag = 1;
// 				i++;
// 				if (str[i] == '\0')
// 					return (1);
// 			}
		
// 		// if (flag && str[i] == ' ')
// 		// 	flag = 1;
// 		// else 
// 		// 	return 0;
// 		if (!flag || str[i] != ' ')
// 			 return 0;
// 		i++;
// 	}
// 		return (flag);
// }
int isnot_term(char *str)
{
	int i = 0;
	while (str[i])
	{
		while(str[i] >= '0' && str[i] <= '9' && (str[i + 1] == '+' || str[i + 1] == '-'))
			return 0;
		i++;
	}
	return (1);
}

int t_defence(char *str)
{
	int i = 0;
	int flag = 0;
	while(str[i] == ' ')
		i++;	
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
		 (str[i] == '-' || str[i] == '+' ) && str[i + 1] >= '0' && str[i + 1] <= '9')
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
	while (i < ac)
	{
		if (t_defence(av[1]) && isnot_term(av[1]))
		{
			write(2, "Amazing work\n",13);
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
