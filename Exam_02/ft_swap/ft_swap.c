void	ft_swap(int *a, int *b)
{
	int tmp = 0;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
#include <stdio.h>

int main(void)
{
	int a = 9;
	int b = 6;
	ft_swap(&a, &b);
	printf("a = %i\nb = %i\n", a, b);
	return(0);
}
*/
