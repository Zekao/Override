#include <stdio.h>

char user_name[100];

int verify_user_name(void)
{
    puts("verifying username....\n");
    return strncmp(user_name, "dat_wil", 7);
}

int verify_user_pass(char *user_pass)
{
    return strncmp(user_pass, "admin", 5); 
}

int main()
{
    char user_pass[64];
    int x = 0;

    printf("********* ADMIN LOGIN PROMPT *********\n");
    printf("Enter Username: ");
    fgets(user_name, 0x100, stdin);

    x = verify_user_name();
    if (x != 0){
        puts("nope, incorrect username...\n");
        return 1;
    }

    printf("Enter Password: \n");
    fgets(user_pass, 0x64, stdin);

    x = verify_user_pass(user_pass);
    if (x == 0 || x != 0){
        puts("nope, incorrect password...\n");
        return 1;
    }

    return 0;
}
