#include "push_swap.h"

int parcing_main (char **av)
{
	int i = 0;
	int j = 1;
	while (av[j])
	{
		while (av[j][i])
		{
			if (!(av[j][i] >= '0' && av[j][i] <= '9') && (!(av[j][i] == '-' || av[j][i] == '+')) && (!(av[j][i] == ' ' || av[j][i] == '\t')))
				return 1;
			if ((av[j][i] == '-' || av[j][i] == '+') && !(av[j][i + 1] >= '0' && av[j][i + 1] <= '9') && !(av[j][i - 1] == ' ' || av[j][i - 1] == '\t' || av[j][i - 1] == '\0'))
				return (1);
			printf(":: %c\n", av[j][i]);
			i++;
		}
		j++;
	}
	return 0;
}

// && (av[j][i + 1] >= '0' && av[j][i + 1] <= '9')) || (!(av[j][i] == '-' || av[j][i] == '+') && (av[j][i - 1] == ' ' || av[j][i - 1] == '\t' || av[j][i - 1] == '\0')