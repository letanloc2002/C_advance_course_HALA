#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
char *error_msg;
int exception_code;

typedef enum
{
    NO_ERROR,
    SENSOR_ERROR,
    DATA_ERROR,
    CONNECT_ERROR,
} ErrorCodes;

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(code, msg)    \
    do                      \
    {                       \
        error_msg = msg;    \
        longjmp(buf, code); \
    } while (0)
void readSensor()
{
    THROW(SENSOR_ERROR, "Loi: sensor fail");
}
void readData()
{
    THROW(DATA_ERROR, "Loi: data fail");
}
void Connect()
{
    THROW(CONNECT_ERROR, "Loi: connect fail");
}
int main(int argc, char const *argv[])
{
    int buf_err[] = {
        SENSOR_ERROR,
        DATA_ERROR,
        CONNECT_ERROR,
    };

    int size = sizeof(buf_err) / sizeof(buf_err[0]);
    for (int i = 0; i < size; i++)
    {
        exception_code = NO_ERROR;
        TRY
        {
            switch (buf_err[i])
            {
            case SENSOR_ERROR:
                readSensor();
                break;
            case DATA_ERROR:
                readData();
                break;
            case CONNECT_ERROR:
                Connect();
                break;
            }
        }
        CATCH(SENSOR_ERROR)
        {
            printf("%s\n", error_msg);
        }
        CATCH(DATA_ERROR)
        {
            printf("%s\n", error_msg);
        }
        CATCH(CONNECT_ERROR)
        {
            printf("%s\n", error_msg);
        }
    }
    /*
    TRY
    {
        printf("Ket qua: %0.3f\n", divide(0, 0));
    }
    CATCH(NO_EXIT)
    {
        printf("ERROR! Không tồn tại\n");
    }
    CATCH(DIVIDE_BY_0)
    {
        printf("ERROR! Chia cho 0\n");
    }
    */

    // thêm code ở đây
    printf("Hello world\n");
    return 0;
}
