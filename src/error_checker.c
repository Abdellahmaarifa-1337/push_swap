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
        if(atoi(s) == atoi(av[i]))
            count++;
        i++;
    }
    if (count > 1)
        return (1);
    return (0);
}
static int check_max(char *s)
{
     if((s[0] == '-' && atoi(s) > 0) || (s[0] != '-' && atoi(s) < 0))
        return (1);
     return(0);
}

int checker(int ac, char **av)
{
    int i;
    int n;
    n = 0;
    i = 1;
    if (ac < 2)
        throw_err();
    while(i < ac)
    {
        if(!is_digit(av[i]))
            throw_err();
        if(is_duplicate(av[i], av, ac))
            throw_err();
        if(check_max(av[i]))
            throw_err();
        i++;
    }
    return 0;
}