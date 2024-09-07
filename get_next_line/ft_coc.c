#include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int county_line(int fd) 
{
    char *buffer;
    int nline = 1;
    int nbytes;
    int i;

    while ((nbytes = read(fd, buffer, sizeof(buffer))) > 0 )
    {
        if(ft_strchr(buffer))
        {
            nline++;
            i = -1;
        }
        i++;
    }
    return nline;
}
#include <fcntl.h>
#include <unistd.h>


int main() 
{
    int fd = open("txt.txt", O_RDONLY);
    int line_count = county_line(fd);

    close(fd);
    fd = open("txt.txt", O_RDONLY);
    char **map = malloc((line_count + 1) * sizeof(char *));
    int i = 0;
    char *line;
    while ((line = get_next_line(fd)) != NULL) 
    {
        map[i] = line;
        i++;
    }
    map[i] = NULL;

    int j = 0;
    while( j < i)
    {
        printf("%s", map[j]);
        j++;
    }
}