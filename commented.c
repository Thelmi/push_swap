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
// int doublechecker(char *str1, int index)
// {
//     int i = 0;
//     while (i < index)
//     {
//         if (str1[i] == str1[index])
//             return 0;
//         i++;
//     }
//     return 1; 
// }

// void inter (char *s1, char *s2)
// {
//     int i = 0;
//     while(s1[i])
//     {
//         if(doublechecker(s1, i) && checker(s1[i], s2))
//             write(1, &s1[i], 1);
//         i++;
//     }
// }