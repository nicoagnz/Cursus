#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *f, char *const a[], char t)
{
    int p[2];
    if (!f || !a || (t != 'r' && t != 'w') || pipe(p) || fork())
        ;
    else
    {
        dup2(p[t == 'r'], t == 'r' ? 1 : 0);
        close(p[0]);
        close(p[1]);
        execvp(f, a);
        exit(1);
    }
    close(p[t == 'r']);
    return (p[t != 'r']);
}

