#include <stdio.h>
#include <assert.h>
#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && (val) <= (max))

void setLevel(int level)
{
    ASSERT_IN_RANGE(level, 1, 10);
    // Thiết lập cấp độ
}

int main()
{
    int x = 5;

    assert(x == 5);

    // Chương trình sẽ tiếp tục thực thi nếu điều kiện là đúng.
    printf("X is: %d\n", x);
    ASSERT_IN_RANGE(11, 1, 10);
    return 0;
}
