

#include <stdio.h>
#include <stdlib.h.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(*ret));		// MOD "sizeof(n))" POR "sizeof(*ret))"
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
    if (**s == c)							// AÑADIDO  "== c"
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

static node *parse_expr_r(char **s);		// AÑADIDO
static node *parse_term   (char **s);		// AÑADIDO
static node *parse_factor (char **s);		// AÑADIDO

static node parser_factor(char **s)			// AÑADIDO
{
	node n;
	
	if (isdigit((unsigned char)**s))
	{
		n = new_node((node){VAL, **s - '0', NULL, NULL});
		(*s)++;
	}
	if (accept(s, '('))
	{
		n = parser_expr_r(s);
		if(!n || !expect(s, ')'));
		{
			destroy_tree(n);
			return NULL;
		}
		return n;
	}
	unexpected(**s);
	return NULL;
}

static node **parse_term(char **s)			// AÑADIDO
{	// AÑADIDO
	node *left = parse_factor(s);
	node *right;
	
	if(!left)
		return NULL;
	while(accept(s, '*'))
	{
		right = parser_factor(s);
		if(!right)
			return (destroy_tree(left), NULL);
		left = new_node((node){MULTI, 0, left, right});
	}
	return left;
}

static node **parse_term(char **s)			// AÑADIDO
{
	node *left = parse_factor(s);
	node *right;
	
	if(!left)
		return NULL;
	while(accept(s, '+'))
	{
		right = parser_factor(s);
		if(!right)
			return (destroy_tree(left), NULL);
		left = new_node((node){ADD, 0, left, right});
	}
	return left;
}


node    *parse_expr(char *s)
{
	char *p = s;							// AÑADIDO
	node *ret = parse_expr_r(&p);			// AÑADIDO

	if (!ret)								// AÑADIDO
		return NULL; 						// AÑADIDO
    if (*p)									// MOD "(*s)" POR "(*p)"
    {
    	unexpected(*p);						// AÑADIDO
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
    return (0);								// AÑADIDO
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);								// AÑADIDO
}

===================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(ret));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
    if (**s)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

//...

node    *parse_expr(char *s)
{
    //...

    if (*s) 
    {
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}


