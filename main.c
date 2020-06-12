#include <unistd.h>

/**
 * Wrapper method for write() system call.
 */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

/**
 * Method mimics strcmp from <string.h>.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	value;
	int	i;

	if (!s1 || !s2)
		return (0);
	value = 0;
	i = -1;
	while (value == 0 && (s1[++i] || s2[i]))
		value += ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	return (value);
}

/**
 * Custom putstr method which detects "\c" bytes as it prints str.
 */
int	ft_putstr_echo(char *str, int *nl)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = -1;
	while (str[++i])
	{
		if (str[i] == 92 && str[++i] == 99)
		{
			*nl = 1;
			return (1);
		}
		ft_putchar(str[i]);
	}
	return (0);
}

/**
 * Method mimics the echo Linux system call.
 */
int	ft_echo(char **argv)
{
	int	i;
	int	nl;
	int	hit;
	
	nl = 0;
	if (ft_strcmp(argv[1], "-n") == 0)
		nl = 1;
	i = (nl) ? 1 : 0;
	hit = 0;
	while (argv[++i]) 
	{
		if (hit) // Adds spaces in between args
			ft_putchar(' ');
		hit = 1;
		if (ft_putstr_echo(argv[i], &nl)) // Prints argument
			break;
	}
	if (!nl)
		ft_putchar('\n');
	return (0);
}

int	main(int argc, char **argv) 
{
	return ((argc > 1) ? ft_echo(argv) : ft_putchar('\n'));
}
