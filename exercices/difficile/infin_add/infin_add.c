// annguyen

#include <unistd.h>
#include <stdlib.h>

int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return (i);
}

void    ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}

void    ft_bzero(char *res, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        res[i] = 0;
        i++;
    }
}

void    res_print(char *res, int n)
{
    int i;
    char c;

    i = 0;
    while (res[i] == 0)
        i++;
    while (i < n)
    {
        c = res[i] + '0';
        write(1, &c, 1);
        i++;
    }
}

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_putnbr(int n)
{
    char c;

    if (n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else
    {
        c = n + '0';
        ft_putchar(c);
    }
}

int     ft_sum(int a, int b)
{
    return (a + b);
}

int     ft_sub(int a, int b)
{
    return (a - b);
}

void    add(char *res, int res_i, int i1, int i2, char *n1, char *n2, int do_sum)
{
    int unit_i;
    int dec_i;
    int a;
    int b;

    unit_i = res_i;
    dec_i = res_i - 1;
    if (i1 < 0)
        a = 0;
    else
        a = n1[i1] - '0';
    if (i2 < 0)
        b = 0;
    else
        b = n2[i2] - '0';

    if (do_sum)
    {
        res[unit_i] += ft_sum(a, b);
        res[dec_i] += res[unit_i] / 10;
        res[unit_i] %= 10;
    }
    else
    {
        b += res[unit_i];
        if (a >= b)
        {
/*
            ft_putstr("\nmini_sub --> ");
            ft_putnbr(a);
            ft_putstr(" - ");
            ft_putnbr(b);
*/
            res[unit_i] = ft_sub(a, b);
/*
            ft_putstr(" --> res[unit_i] = ");
            ft_putchar(res[unit_i] + '0');
            ft_putstr("\n");
*/
        }
        else
        {
            a += 10;
/*
            ft_putstr("\nmini_sub -->");
            ft_putnbr(a);
            ft_putstr(" - ");
            ft_putnbr(b);
            ft_putstr("\n");
*/
            res[unit_i] = ft_sub(a, b);
            res[dec_i] = 1;
/*
            ft_putstr(" --> res[dec_i] = ");
            ft_putchar(res[dec_i] + '0');
            ft_putstr(" --> res[unit_i] = ");
            ft_putchar(res[unit_i] + '0');
            ft_putstr("\n");
*/
        }
    }
}

void    infin_add(char *n1, char *n2, int do_sum)
{
    char *res;
    int res_size;

    res_size = ft_strlen(n1) + ft_strlen(n2);
    res = malloc(sizeof(char) * (res_size + 1));
    ft_bzero(res, res_size);
/*
    ft_putstr("res_bzero : ");
    res_print(res, res_size);
    ft_putstr("\n");
*/
    int i1, i2, res_i;

    i1 = ft_strlen(n1) - 1;
    i2 = ft_strlen(n2) - 1;
    res_i = i1 + i2 + 1;
    while (i1 >= 0 || i2 >= 0)
    {
/*
        ft_putstr("\ndigit_ope : ");
        if (i1 >= 0)
            ft_putchar(n1[i1]);
        if (do_sum)
            ft_putstr(" + ");
        else
            ft_putstr(" - ");
        if (i2 >= 0)
            ft_putchar(n2[i2]);
        ft_putstr("\n");
*/
        add(res, res_i, i1, i2, n1, n2, do_sum);
        res_i--;
        i1--;
        i2--;
    }

//  ft_putstr("\nres_final = ");

    res_print(res, res_size);
}

char    *ft_strdup(char *s)
{
    char *t;
    int i;

    i = 0;
    t = malloc(sizeof(char) * (ft_strlen(s) + 1));
    while (s[i])
    {
        t[i] = s[i];
        i++;
    }
    t[i] = 0;
    return (t);
}

int     ft_strcmp(char  *s1, char *s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == 0)
            return (0);
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

int     put_in_abs_increase_order(char **n1, char **n2)
{
    char *t;

    if (ft_strlen(*n1) > ft_strlen(*n2))
        return (0);
    else if (ft_strlen(*n2) > ft_strlen(*n1))
    {
/*
        ft_putstr(*n1);
        ft_putstr(" | ");
        ft_putstr(*n2);
        ft_putstr("\t");
*/
        t = *n2;
        *n2 = *n1;
        *n1 = t;
/*
        ft_putstr(*n1);
        ft_putstr(" | ");
        ft_putstr(*n2);
        ft_putstr("\n");
*/
        return (1);
    }
    else if (ft_strlen(*n1) == ft_strlen(*n2) && ft_strcmp(*n1, *n2) > 0)
        return (0);
    else if (ft_strlen(*n2) == ft_strlen(*n1) && ft_strcmp(*n1, *n2) < 0)
    {
/*
        ft_putstr(*n1);
        ft_putstr(" | ");
        ft_putstr(*n2);
        ft_putstr("\t");
*/
        t = *n2;
        *n2 = *n1;
        *n1 = t;
/*
        ft_putstr(*n1);
        ft_putstr(" | ");
        ft_putstr(*n2);
        ft_putstr("\n");
*/
        return (1);
    }
    return (0);
}

void    add_wrap(char *n1, char *n2)
{
    int     do_sum = 1;
    int     did_swap;

    if (*n1 == '0' && *n2 == '0')
    {
        ft_putchar('0');
        return ;
    }
    if (n1[0] == '-' && n2[0] == '-')
    {
        n1++;
        n2++;
        ft_putchar('-');
    }
    else if (n2[0] == '-')
    {
        n2++;
        did_swap = put_in_abs_increase_order(&n1, &n2);
        if (did_swap == 1)
            ft_putchar('-');
        do_sum = 0;
/*
        ft_putstr(n1);
        ft_putstr(" || ");
        ft_putstr(n2);
        ft_putstr("\n");
*/
    }
    else if (n1[0] == '-')
    {
        n1++;
        did_swap = put_in_abs_increase_order(&n1, &n2);
        if (did_swap == 0)
            ft_putchar('-');

//      ft_putstr(n1);
//      ft_putstr(" || ");
//      ft_putstr(n2);
//      ft_putstr("\n");

        do_sum = 0;
    }

/*
    ft_putstr(n1);
    if (do_sum == 1)
        ft_putstr(" + ");
    else
        ft_putstr(" - ");
    ft_putstr(n2);
    ft_putstr("\n");
    ft_putstr("do_sum : ");
    if (do_sum)
        ft_putstr("1");
    else
    ft_putstr("0");
    ft_putstr("\n");
*/

    infin_add(n1, n2, do_sum);
}

int     main(int ac, char **av)
{
    if (ac == 3)
        add_wrap(av[1], av[2]);
    ft_putstr("\n");
    return  (0);
}
