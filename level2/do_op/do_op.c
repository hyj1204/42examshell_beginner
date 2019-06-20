#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		if (*argv[2] == '+')
			printf("%d",atoi(argv[1]) + atoi(argv[3]));
		else if (*argv[2] == '-')
			printf("%d",atoi(argv[1]) - atoi(argv[3]));
	    else if (*argv[2] == '*')
			printf("%d",atoi(argv[1]) * atoi(argv[3]));
		else if (*argv[2] == '/')
			printf("%d",atoi(argv[1]) / atoi(argv[3]));
		else if (*argv[2] == '%')
			printf("%d",atoi(argv[1]) % atoi(argv[3]));
	}
	printf("\n");
	return (0);
}
