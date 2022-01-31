
#include "push_swap.h"
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
void throw_err()
{
    printf("Error\n");
    exit(0);
}
int is_duplicate(char *s, char **av, int ac)
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
int check_max(char *s)
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
void print_stack(stack *a, char stack)
{
    int i;
    i = 0;
    while(i < a->size)
        printf("%d\n", a->stack[i++]);
    printf("-------\nstack %c\n", stack);
}
int main(int ac, char **av)
{
    //int *a;
    //int *b;
    int i;
	stack *a;
	stack *b;
	a = (stack *)malloc(sizeof(stack));
	b = (stack *)malloc(sizeof(stack));
    checker(ac, av);
    a->stack = (int *)malloc(sizeof(int) * (ac));
    b->stack = (int *)malloc(sizeof(int) * (ac));
    i = 0;
    while (i < ac - 1)
	{
       	a->stack[i] = atoi(av[i + 1]);
		i++;
	}
	a->size = ac - 1;
    b->size = 0;
     //swap_stack(a, b, "as");
     //push_stack(a, b, "pb");
     //push_stack(a, b, "pb");
    // push_stack(&a, &b, "pb");
     //rotate_stack(a, b, "ra");
    // rotate_stack(&a, &b, "rrr");

	// sort the stack
	sort_stack(a, b);
	// print stacks
  //  print_stack(a, 'a');
   //print_stack(b, 'b');
    return (0);
}