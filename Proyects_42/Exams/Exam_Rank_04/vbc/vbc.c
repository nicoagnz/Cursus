#include <stdio.h>
#include <stdlib.h>    // MOD: usamos <stdlib.h> para calloc/free en lugar de <malloc.h>
#include <ctype.h>

typedef struct node {
    enum { 
        ADD, 
        MULTI,
        VAL 
    }   type;
    int           val;
    struct node   *l;
    struct node   *r;
} node;

node *new_node(node n)
{
    node *ret = calloc(1, sizeof(*ret));  // MODIFICADO: sizeof(*ret) en lugar de sizeof(n)
    if (!ret)
        return NULL;
    *ret = n;
    return ret;
}

void destroy_tree(node *n)
{
    if (!n)
        return;
    if (n->type != VAL) {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");  // MODIFICADO: mensaje correcto según el enunciado
}

/* MODIFICADO: accept/expect vuelven a la firma original, sin global */
int accept(char **s, char c)
{
    if (**s == c) {
        (*s)++;
        return 1;
    }
    return 0;
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return 1;
    unexpected(**s);
    return 0;
}

/* AÑADIDO: declaraciones de las funciones de parsing recursivo */
static node *parse_expr_r(char **s);
static node *parse_term   (char **s);
static node *parse_factor (char **s);

/* AÑADIDO: parsing de un factor (dígito o paréntesis) */
static node *parse_factor(char **s)
{
    node *n;

    if (isdigit(**s))
    {
        n = new_node((node){VAL, **s - '0', NULL, NULL});
        (*s)++;
        return n;
    }
    if (accept(s, '('))
    {
        n = parse_expr_r(s);
        if (!n || !expect(s, ')'))
        {
            destroy_tree(n);
            return NULL;
        }
        return n;
    }
    unexpected(**s);
    return NULL;
}

/* AÑADIDO: parsing de un término (multiplicaciones) */
static node *parse_term(char **s)
{
    node *left = parse_factor(s);
    node *right;

    if (!left)
        return NULL;

    while (accept(s, '*'))
    {
        right = parse_factor(s);
        if (!right)
            return (destroy_tree(left), NULL);
        left = new_node((node){MULTI, 0, left, right});
    }
    return left;
}

/* AÑADIDO: parsing de una expresión (sumas) */
/* ESTA FUNCIÓN ES UN COPY-PASTE DE PARSE_TERM, SOLO TIENES QUE CAMBIAR '*' POR '+' Y 'MULTI' POR 'ADD' !!!!!*/
static node *parse_expr_r(char **s)
{
    node *left = parse_term(s);
    node *right;

    if (!left)
        return NULL;

    while (accept(s, '+'))
    {
        right = parse_term(s);
        if (!right)
            return (destroy_tree(left), NULL);
        left = new_node((node){ADD, 0, left, right});
    }
    return left;
}

/* MODIFICADO: parse_expr inicializa un puntero local y verifica el final de la cadena */
node *parse_expr(char *s)
{
    char *p = s;
    node *ret = parse_expr_r(&p);
    if (!ret)
        return NULL;
    if (*p) {                          
        unexpected(*p);
        destroy_tree(ret);
        return NULL;
    }
    return ret;
}

int eval_tree(node *tree)
{
    switch (tree->type) {
        case ADD:   return eval_tree(tree->l) + eval_tree(tree->r);
        case MULTI: return eval_tree(tree->l) * eval_tree(tree->r);
        case VAL:   return tree->val;
    }
    return 0;  // no debería ocurrir, pero quién sabe
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return 1;
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return 0;
}
