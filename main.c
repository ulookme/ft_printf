/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:34:26 by chajjar           #+#    #+#             */
/*   Updated: 2022/03/23 22:34:35 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int    main(void)
{
    int        a, b;

    char    *str = "cause";
    int        i = -30;
    int        y = 69;
    int        *ptr = &i;

    /* PART ONE */
    printf("\033[0;34;1mORIGINAL:\033[2m\n");
    a = printf("I like turtles %s %d%%\nError %cdata at %p -> %x %X\nPwease wait %i%u seconds.. %s\n\n", str, y, '\0', ptr, i, -i, -y, -y, (char *) 0);

    printf("\033[0;35;1mREMAKE:\033[2m\n");
    b = ft_printf("I like turtles %s %d%%\nError %cdata at %p -> %x %X\nPwease wait %i%u seconds.. %s\n\n", str, y, '\0', ptr, i, -i, -y, -y, (char *) 0);
    b++;
    
    printf("\033[0;33;1mCOMPARAISONS:\033[2m\n");
    printf("Original: [%d] VS Function: [%d] ", a, b);
    if (a == b)
        printf("\033[0;32m(Good)\033[0m\n\n");
    else
    {
        printf("\033[0;31m(Bad: %d diff)\n\n", b - a);
        printf("\033[0;33mChecking issues..");

        printf("\n < Origin [%%%%] Func > ");
        a = printf("%%");
        b = ft_printf("%%");
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%c] Func > ");
        a = printf("%c", 'a');
        b = ft_printf("%c", 'a');
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%d] Func > ");
        a = printf("%d", 6886);
        b = ft_printf("%d", 6886);
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%u] Func > ");
        a = printf("%u", -460);
        b = ft_printf("%u", -460);
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%s] Func > ");
        a = printf("%s", "je suis le %s");
        b = ft_printf("%s", "je suis le %s");
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%i] Func > ");
        a = printf("%i", 324);
        b = ft_printf("%i", 324);
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%x] Func > ");
        a = printf("%x", 46798);
        b = ft_printf("%x", 46798);
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%X] Func > ");
        a = printf("%X", -413);
        b = ft_printf("%X", -413);
        printf("\nOrigin: %d // Func: %d // Diff: %d\n", a, b, b - a);

        printf("\n < Origin [%%p] Func > ");
        a = printf("%p", ptr);
        b = ft_printf("%p", ptr);
        printf("\nOrigin: %d // Func: %d // Diff: %d\n\n", a, b, b - a);
    }

    printf("\033[33;1mHANDLES NULL STRING?\033[0;31m\n");
    ft_printf(0);
    printf("\033[32mNull Format Handled!\033[0m\n");
    return (0);
}
