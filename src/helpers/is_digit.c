int is_digit(char *s)
{
    // skip white spaces
    int i = 0;
    while(s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    if(s[i] == '+' || s[i] == '-')
        i++;
    while(s[i])
    {
        if(s[i] <= '9' && s[i] >= '0')
            i++;
        else
            return 0;
    }
    return (1);
}