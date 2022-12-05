#include "ft_printf.h"
#include <stdio.h>

int ft_check_specifier(char c, va_list args)
{
    int print_length;

    print_length = 0;
    if (c == 'c')
        print_length = print_char(va_arg(args, int));
    else if (c == '%')
        print_length = print_char(%);
    else if (c == 's')
        print_length = print_string(va_arg(args, char *));
    else if (c == 'i' || c == 'd')
        print_length = print_numb(va_arg(args, int));
    else if (c == 'u')
        print_length = print_unsigned(va_arg(args, unsigned int));
    else if (c == 'X' || c == 'x')
        print_length = print_hexadecimal(va_arg(args, unsigned long long), c);
    else if (c == 'p')
        print_length = print_adress(va_arg(args, unsigned long long));
    return (print_length);
}

int ft_printf(char *format, ...)
{
    va_list args;
    int print_length;
    int i;

    i = 0;
    print_length = 0;
    va_start(args, format);
    while (formart[i] != '\0')
    {
        if (format[i] != '%')
            print_length += print_char(format[i]);
        else
        {
            i++;
            print_length += ft_check_specifier(format[i], args);
        }
        i++;
    }
    va_end(args);
    return (print_lengths);
}
