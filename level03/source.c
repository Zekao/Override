#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void decrypt(unsigned int key) {
        unsigned int len;
        char str[] = "Q}|u`sfg~sf{}|a3";

        len = strlen(str);

        for (int i = 0; i < len; i++)
            str[i] ^= key;

        for (int i = 0; i < len; i++)
                printf("%c", str[i]);

        if (!strcmp(str, "Congratulations!"))
                system("/bin/sh");
        else
                printf("\nInvalid Password\n");
}

void test(unsigned int input, unsigned int secret) 
{
    int     res;
    res = secret - input;
    switch (res) {
            case 0x1:
                    decrypt(res);
                    break;
            case 0x2:
                    decrypt(res);
                    break;
            case 0x3:
                    decrypt(res);
                    break;
            case 0x4:
                    decrypt(res);
                    break;
            case 0x5:
                    decrypt(res);
                    break;
            case 0x6:
                    decrypt(res);
                    break;
            case 0x7:
                    decrypt(res);
                    break;
            case 0x8:
                    decrypt(res);
                    break;
            case 0x9:
                    decrypt(res);
                    break;
            case 0x10:
                    decrypt(res);
                    break;
            case 0x11:
                    decrypt(res);
                    break;
            case 0x12:
                    decrypt(res);
                    break;
            case 0x13:
                    decrypt(res);
                    break;
            case 0x14:
                    decrypt(res);
                    break;
            case 0x15:
                    decrypt(res);
                    break;
            default:
                    decrypt(rand());
                    break;
    }
}

int main(void)
{
    int             input;

    srand(time(NULL));
    puts("***********************************\n");
    puts("*               level03         **\n");
    puts("***********************************\n");

    printf("Password:");
    scanf("%d", &input);

    test(input, 0x1337d00d); // 322424845
    return 0;

}