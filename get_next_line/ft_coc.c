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
int ft_error(char **str)
{
    int i = 0;
    int j = 0;
    int res = 0;
    int coin = 0;
    int player = 0;
    int zayd = 0;
        while(str[i])
        {
            while(str[i][j])
            {
                if(str[i][j] == 'P')
                    player++;
                if(str[i][j] == 'E')
                    res++;
                if(str[i][j] == 'C')
                    coin++;
                if(str[i][j] != '1' &&str[i][j] != '0' &&str[i][j] != 'C' && str[i][j] != 'P' && str[i][j] != 'E' && str[i][j] != '\n'  )
                            zayd++;
                j++;
            }
            j = 0;
            i++;
        }
        if(res !=1 || coin < 1 || player != 1 || zayd != 0 )
        {
            printf("error inside the map");
            exit(1);
        }
        return 0;

}

int ft_jidar(char **tmp)
{
    int i = 0;
    int j = 0;
    while (tmp[i])
    {
        j=0;
        while(tmp[i][j])
        {
            if(tmp[0][j] == '1' || tmp[0][j] == '\n')
                   j++;
            else
            {
                    printf("error in the wall");
                        exit(1);
            }
        
        }
        
            i++;
    }
        
    return 0;
    
}

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
    ft_error(map);
    ft_jidar(map);

    int j = 0;
    while( j < i)
    {
        printf("%s", map[j]);
        j++;
    }
}