#include "push_swap.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	is_valid_input(char *str)
{
	int i;
	
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char **parcing (char **av)
{
	int i;
	char *joined;
	char *temp;
	char **splited;

	i = 1;
	joined = ft_strdup("");

	while (av[i])
	{
		temp = ft_strjoin(joined, av[i]);
		free(joined);
		joined = ft_strjoin(joined, " ");
		free(temp);
		i++;
	}

	printf("Joined string: [%s]\n", joined);
	splited = ft_split(joined, ' ');
	free(joined);
	// is_valid_input(splited);
	return(splited);
}