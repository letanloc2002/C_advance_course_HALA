#include <stdio.h>

#define STRINGIZE_RESULT(x) STRINGIZE(x)
#define STRINGIZE(x) #x
#define DATA 40

int main()
{

    // Sử dụng toán tử #
    printf("The value is: %s\n", STRINGIZE_RESULT(DATA)); // 40-string-not int

    return 0;
}