#include "vbc.h"

static void unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
	exit(1);
}

static int factor(char **s)
{
	if (!**s)
		unexpected(0);
	if (isdigit(**s))
	{
		int r = **s - '0';
		(*s)++;
		return r;
	}
	if (**s == '(')
	{
		(*s)++;
		int r = parse_expr(s);
		if (**s != ')')
			unexpected(**s);
		(*s)++;
		return r;
	}
	unexpected(**s);
	return 0;
}

static int term(char **s)
{
	int r = factor(s);
	while (**s == '*')
	{
		(*s)++;
		if (!**s)
			unexpected(0);
		r *= factor(s);
	}
	return r;
}

int parse_expr(char **s)
{
	int r = term(s);
	while (**s == '+')
	{
		(*s)++;
		if (!**s)
			unexpected(0);
		r += term(s);
	}
	return r;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char *p = av[1];
	if (!*p)
	{
		puts("0");
		return 0;
	}
	int r = parse_expr(&p);
	if (*p)
		unexpected(*p);
	printf("%d\n", r);
	return 0;
}

