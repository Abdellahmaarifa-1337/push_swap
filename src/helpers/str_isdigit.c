#include  "../push_swap.h"

int str_isdigit(char *s)
{
    // skip white spaces
    int i = 0;
    while(s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '+' || s[i] == '-')
        i++;
	if (!s[i])
	 	return 0;
    while(s[i])
    {
        if (ft_isdigit(s[i]))
            i++;
        else
            return 0;
    }
    return (1);
}