#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    int fd3 = open("file3.txt", O_RDONLY);
    
    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("Error abriendo archivos");
        return (1);
    }

    char *line1;
    char *line2;
    char *line3;

    printf("Leyendo archivos simultáneamente:\n");
    for (int i = 0; i < 5; i++) // Leer 5 líneas de cada archivo
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        line3 = get_next_line(fd3);

        printf("file1.txt: %s", line1 ? line1 : "(EOF)\n");
        printf("file2.txt: %s", line2 ? line2 : "(EOF)\n");
        printf("file3.txt: %s", line3 ? line3 : "(EOF)\n");
        
        free(line1);
        free(line2);
        free(line3);
    }

    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}
