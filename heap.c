#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n = 5;

    // Cấp phát bộ nhớ ban đầu
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Cấp phát bộ nhớ thất bại\n");
        return 1;
    }

    // Gán giá trị ban đầu
    for (int i = 0; i < n; i++)
    {
        ptr[i] = i + 1;
    }

    // Mở rộng vùng nhớ lên 10 phần tử
    ptr = (int *)realloc(ptr, 10 * sizeof(int));

    if (ptr == NULL)
    {
        printf("Không thể mở rộng bộ nhớ\n");
        return 1;
    }

    // Gán thêm giá trị cho phần tử mới
    for (int i = 5; i < 10; i++)
    {
        // ptr[i] = (i + 1) * 2;
    }

    // In ra giá trị
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr); // Giải phóng bộ nhớ
    return 0;
}
