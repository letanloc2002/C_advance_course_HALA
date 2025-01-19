#include <stdio.h>
#include <stdarg.h>
#define tong(...) Addnumber(__VA_ARGS__, 0)
int Addnumber(int n, ...)
{
    // int Sum = 0;
    va_list ptr;
    va_start(ptr, n);
    int result = n;
    int value;
    while ((value = va_arg(ptr, int)) != 0)
    {
        result += value;
    }
    va_end(ptr, n);
    return result;
}

int main()
{
    printf("Tong:%d\n", tong(3, 1, 1, 1, 5));

    return 0;
}
