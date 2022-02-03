#include "push_swap.h"


static void throw_err()
{
    printf("Error\n");
    exit(0);
}
static int is_duplicate(char *s, char **av, int ac)
{
    int i = 1;
    int count = 0;
    char *str;
    while(i < ac)
    {
        if(ft_atoi(s) == ft_atoi(av[i]))
            count++;
        i++;
    }
    if (count > 1)
        return (1);
    return (0);
}
static int check_max(char *s)
{
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
    if((s[0] == '-' && ft_atoi(s) > 0) || (s[0] != '-' && ft_atoi(s) < 0))
        return (1);
    return(0);
}

int error_checker(int ac, char **av)
{
    int i;
    int n;
    n = 0;
    i = 1;
    while(i < ac)
    {
        if(!str_isdigit(av[i]))
            throw_err();
        if(is_duplicate(av[i], av, ac))
            throw_err();
        if(check_max(av[i]))
            throw_err();
        i++;
    }
    return 0;
}