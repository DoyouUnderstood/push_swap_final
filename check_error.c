#include "push_swap.h"

int	is_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_int(char *str)
{
	int	sign = 1;
	long long num = 0;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (!isdigit(*str) || num > (long long)INT_MAX + 1) // +1 pour gérer INT_MIN
			return (0);
		num = num * 10 + (*str - '0');
		str++;
	}
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	has_duplicates(char **argv, int len, char *str)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (strcmp(argv[i], str) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	validate_args(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]) || has_duplicates(argv, i, argv[i]) || !is_valid_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

