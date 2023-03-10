#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_struct {
        char message[140];
        char username[40];
        int size;
};

void secret_backdoor(void) {
        char cmd[128];
        fgets(cmd, 128, stdin);
        system(cmd);
}

void handle_msg(void)
{
  struct s_struct content;
  bzero(&content.username, 40);
  content.size = 140;
  set_username(&content);
  set_msg(&content);
  puts(">: Msg sent!");
}

void set_msg(struct s_struct *content)
{
  char readbuf[1024];
  bzero(&readbuf, 1024);
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(readbuf, 1024, stdin);
  strncpy(content->message, readbuf, content->size);
}

void set_username(struct s_struct * content)
{
  int i;
  char readbuf[128];
  bzero(&readbuf, 128);
  puts(">: Enter your username");
  printf(">>: ");
  fgets(readbuf, 128, stdin);
  for(i = 0; i <= 40 && readbuf[i]; i++)
    content->username[i] = readbuf[i];
  printf(">: Welcome, %s", content->username);
}

int main(void)
{

  puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------\n");
  handle_msg();
  return 0;
}