#include <iostream>

static bool	is_alpha_lower(char c)
{
	if (c >= 97 && c <= 122)
		return (true);
	return (false);
}

static char	capitalize(char c)
{
	if (is_alpha_lower(c))
		return (c - 32);
	return (c);
}
std::size_t strlen(char *string)
{
	std::size_t i;
	i = 0;
	while (string[i])
		i++;
	return (i);
}

static void	print_word(std::string word)
{
	size_t	i;

	i = 0;
	while (i < word.length())
	{
		std::cout << capitalize(word[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		print_word(argv[i]);
		if (i + 1 < argc)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
