/***************************************************************************************

|***libft.h in my libftprintf.h should called "libft/" and in the root of repository***|

***************************************************************************************/
#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Your ft_printf prototype
int ft_printf(const char *format, ...);

int main(void)
{
    int ret_ft, ret_std;
    int failures = 0;
    int i;

    char *strings[] = { "Hello", "", NULL, "StressTest123", "LongStringForTesting" };
    int ints[] = { 0, 1, -1, 42, INT_MAX, INT_MIN };
    unsigned int uints[] = { 0, 1, 42, UINT_MAX };
    char chars[] = { 'a', 'Z', '\0' };

    void *pointers[] = { (void*)0, (void*)1, (void*)ints, (void*)&ints[0] };

    for (i = 0; i < 1000; i++)
    {
        // Integer
        ret_ft = ft_printf("Int: %d\n", ints[i % 6]);
        ret_std = printf("Int: %d\n", ints[i % 6]);
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }

        // Unsigned
        ret_ft = ft_printf("Unsigned: %u\n", uints[i % 4]);
        ret_std = printf("Unsigned: %u\n", uints[i % 4]);
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }

        // Hex
        ret_ft = ft_printf("Hex lowercase: %x\n", uints[i % 4]);
        ret_std = printf("Hex lowercase: %x\n", uints[i % 4]);
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }

        ret_ft = ft_printf("Hex uppercase: %X\n", uints[i % 4]);
        ret_std = printf("Hex uppercase: %X\n", uints[i % 4]);
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }

        // Char
        ret_ft = ft_printf("Char: %c\n", chars[i % 3]);
        ret_std = printf("Char: %c\n", chars[i % 3]);
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }

        // String
        ret_ft = ft_printf("String: %s\n", strings[i % 5]);
        ret_std = printf("String: %s\n", strings[i % 5]);
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }

        // Pointer
        ret_ft = ft_printf("Pointer: %p\n", pointers[i % 4]);
        ret_std = printf("Pointer: %p\n", pointers[i % 4]);
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }

        // Percent
        ret_ft = ft_printf("Percent: %%\n");
        ret_std = printf("Percent: %%\n");
        if (ret_ft != ret_std) { printf("FAIL #%d: ret_ft=%d | ret_std=%d\n", i+1, ret_ft, ret_std); failures++; }
    }

    printf("Total tests: %d | Failures: %d\n", 1000*8, failures);
    return 0;
}

