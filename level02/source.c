#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASS_LEN 41

int main(int argc, char **argv)
{
    char username[100] = {0};
    char real_pass[PASS_LEN] = {0};
    char in_pass[100] = {0};
    FILE *pass_file = NULL;
    int size = 0;

    pass_file = fopen("/home/users/level03/.pass", "r");
    if (pass_file == NULL) 
    {
        printf("ERROR: failed to open password file\n");
        exit(1);
    }

    size = fread(real_pass, 1, PASS_LEN, pass_file);
    real_pass[strcspn(real_pass, "\n")] = '\0';
    if (size != PASS_LEN)
    {
        printf("ERROR: failed to read password file\n");
        exit(1);
    }

    fclose(pass_file);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\**************************************/");

    printf("--[ Username: ");
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = '\0';    
    printf("--[ Password: ");
    fgets(in_pass, sizeof(in_pass), stdin);
    in_pass[strcspn(in_pass, "\n")] = '\0';

    puts("*****************************************");

    if(!strncmp(real_pass, in_pass, PASS_LEN)){
        printf("Greetings, %s!\n", username);
        system("/bin/sh");
    } else {
        printf(username);
        printf(" does not have access!\n");
        exit(1);
    }
    return 0;
}
