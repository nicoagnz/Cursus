#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int i = 1;
	int j = 0;

	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}

// ./megaphone "shhhhh... I think the students are asleep..."
// ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// ./megaphone
