/*
#include <unistd.h>

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 0, j = 0;
		char *res;
		while(av[1][i])
		{
			if(av[1][i] == '_')
			{
				i++;
				av[1][i] -= 32;
				res[j] = av[1][i];
			}
			else
				res[j] = av[1][i];
			j++;
			i++;
		}
		write(1, res, j);
	}
	write(1, "\n", 1);
	return 0;
}
*/

#include <unistd.h>

int toUpper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int ft_putchar(char c)
{
    return write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i;
    
    // do things only if there is only one argument
    if (ac == 2)
    {
        i = 0;
        // looping over the whole string
        while (av[1][i])
        {
            // If we encounter a _, we have to make the
            // next letter uppercase and not print the _
            // so we only print the uppercase letter
            if (av[1][i] == '_')
                // here we use the ++i operator to
                // increment i before accessing the value
                // that way we skip the _
                ft_putchar(toUpper(av[1][++i]));
            else
                // in all other cases, we simply write
                // the character to the screen
                ft_putchar(av[1][i]);
            i++;
        }
    }
    // and finally, we have our newline
    // putting it here makes us only need one in all the 
    // cases 
    ft_putchar('\n');
}

