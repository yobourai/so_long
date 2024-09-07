#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		i++;
	return (i);
}

char ft_pop(char *str)
{
    char **tmp;
    tmp = (char *)malloc(ft_strlen(str)+1);
    if(!tmp)
        return NULL ;
        int i = 0;
    while(str[i])
    {
        tmp[i] = &str[i];
        i++;
    }
    tmp[i] = '\0';
    return tmp;
}
#include <stdio.h>
int main()
{
    char str[] ="0000000001111111";
    char *tmp = ft_pop(str);
    printf("%s\n",tmp); 
}