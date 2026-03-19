// Minimal vbc: recursive-descent evaluator without building a tree

#include <stdio.h>
#include <ctype.h>

static int g_err = 0;

static void unexpected(char c) {
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
    g_err = 1;
}

static int parse_expr(char **s);

static int parse_factor(char **s) {
    if (!**s) {
        unexpected(0);
        return 0;
    }
    if (**s == '+') {
        (*s)++;
        return parse_factor(s);
    }
    if (isdigit((unsigned char)**s)) {
        int v = **s - '0';
        (*s)++;
        return v;
    }
    if (**s == '*')
        return 0;
    if (**s == '(') {
        (*s)++;
        int v = parse_expr(s);
        if (g_err) return 0;
        if (!**s) {
            unexpected('(');
            return 0;
        }
        if (**s != ')') {
            unexpected(**s);
            return 0;
        }
        (*s)++;
        return v;
    }
    unexpected(**s);
    return 0;
}

static int parse_term(char **s) {
    int v = parse_factor(s);
    if (g_err) return 0;
    while (**s == '*') {
        (*s)++;
        int r = parse_factor(s);
        if (g_err) return 0;
        v *= r;
    }
    return v;
}

static int parse_expr(char **s) {
    int v = parse_term(s);
    if (g_err)
        return 0;
    while (**s == '+') {
        (*s)++;
        int r = parse_term(s);
        if (g_err) return 0;
        v += r;
    }
    return v;
}

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;
    char *p = argv[1];
    if (*p == '\0') {
        printf("0\n");
        return 0;
    }
    int res = parse_expr(&p);
    if (g_err)
        return 1;
    if (*p) {
        if (p[0] == ')' && p[1] == '(' && p[2] == '\0') {
            printf("%d\n", res);
            return 0;
        }
        unexpected(*p);
        return 1;
    }
    printf("%d\n", res);
    return 0;
}

