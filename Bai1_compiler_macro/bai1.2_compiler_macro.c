#include <stdio.h>
#define PRINT_MENU_ITEM(number, item) printf("%d. %s\n", number, item)
#define PRINT_MENU(...)                           \
    do                                            \
    {                                             \
        const char *items[] = {__VA_ARGS__};      \
        int n = sizeof(items) / sizeof(items[0]); \
        for (int i = 0; i < n; i++)               \
        {                                         \
            PRINT_MENU_ITEM(i + 1, items[i]);     \
        }                                         \
    } while (0)
// function
int main()
{
    PRINT_MENU("Option A", "Option B", "Option C", "Option D", "Option E", "Option G");
    return 0;
}