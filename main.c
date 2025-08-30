/***************************************************************************************

|***libft.h in my libftprintf.h should called "libft/" and in the root of repository***|

***************************************************************************************/
#include <stdio.h>
#include <limits.h>

int ft_printf(const char *format, ...);

void *get_pointer() {
    static int x = 42;
    return &x;
}

int main(void)
{
    int ret1, ret2;

    char c = 'A';
    char *str = "Hello, ft_printf!";
    char *null_str = NULL;
    int n = 123456789;
    int neg = -2147483648; // INT_MIN
    unsigned int u = 4294967295U; // UINT_MAX
    unsigned int hex = 0xdeadbeef;

    void *ptr = get_pointer();

    printf("\n=== Testing ft_printf with all formats ===\n");

    // Test %ld
    ret1 = ft_printf("Char: [%c]\n", c);
    ret2 =   printf("Char: [%c]\n", c);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);
    // Test %c
    ret1 = ft_printf("Char: [%c]\n", c);
    ret2 = printf("Char: [%c]\n", c);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);
    // Test %%
    ret1 = ft_printf("Percent: [%%]\n");
    ret2 = printf("Percent: [%%]\n");
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // Test %s
    ret1 = ft_printf("String: [%s]\n", str);
    ret2 = printf("String: [%s]\n", str);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // Test NULL string
    ret1 = ft_printf("Null string: [%s]\n", null_str);
    ret2 = printf("Null string: [%s]\n", null_str);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // Test %d and %i
    ret1 = ft_printf("Int: [%d], Negative: [%i], INT_MAX: [%d], INT_MIN: [%i]\n", n, neg, INT_MAX, INT_MIN);
    ret2 = printf("Int: [%d], Negative: [%i], INT_MAX: [%d], INT_MIN: [%i]\n", n, neg, INT_MAX, INT_MIN);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // Test %u
    ret1 = ft_printf("Unsigned: [%u], Zero: [%u]\n", u, 0);
    ret2 = printf("Unsigned: [%u], Zero: [%u]\n", u, 0);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // Test %x and %X
    ret1 = ft_printf("Hex lowercase: [%x], Hex uppercase: [%X]\n", hex, hex);
    ret2 = printf("Hex lowercase: [%x], Hex uppercase: [%X]\n", hex, hex);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // Test %p
    ret1 = ft_printf("Pointer: [%p], NULL pointer: [%p]\n", ptr, NULL);
    ret2 = printf("Pointer: [%p], NULL pointer: [%p]\n", ptr, NULL);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    // Mixed all together
    ret1 = ft_printf("Mixed: [%c][%s][%d][%i][%u][%x][%X][%p][%%]\n", c, str, n, neg, u, hex, hex, ptr);
    ret2 = printf("Mixed: [%c][%s][%d][%i][%u][%x][%X][%p][%%]\n", c, str, n, neg, u, hex, hex, ptr);
    printf("Return: ft_printf=%d, printf=%d\n\n", ret1, ret2);

    return 0;
}

