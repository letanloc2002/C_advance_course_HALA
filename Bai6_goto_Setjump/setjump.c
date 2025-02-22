#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer; // Biến để lưu trạng thái

int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Lỗi: Chia cho 0!\n");
        longjmp(buffer, 1); // Quay lại vị trí setjmp
    }
    return a / b;
}

int main()
{
    int x = 10, y = 0, result;

    if (setjmp(buffer) == 0)
    { // Lần đầu tiên gọi setjmp, trả về 0
        printf("Nhập số chia (y): ");
        scanf("%d", &y);

        result = divide(x, y); // Gọi hàm chia
        printf("Kết quả: %d / %d = %d\n", x, y, result);
    }
    else
    {
        printf("Đã xử lý ngoại lệ và quay lại từ longjmp!\n");
    }

    printf("Chương trình tiếp tục thực thi bình thường.\n");
    return 0;
}
