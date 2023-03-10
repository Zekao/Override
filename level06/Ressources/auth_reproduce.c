#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/ptrace.h>
#include <unistd.h>

int auth(char *username,unsigned int serial)
{
  size_t len;
  int uVar1;
  long lVar2;
  int i;
  uint crypted_pwd;
  
  len = strcspn(username,"\n");
  username[len] = '\0';
  len = strnlen(username,0x20);
  if ((int)len < 6) {
    uVar1 = 1;
  }
  else {
    lVar2 = ptrace(PTRACE_TRACEME);
    if (lVar2 == -1) {
      puts("\x1b[32m.---------------------------.");
      puts("\x1b[31m| !! TAMPERING DETECTED !!  |");
      puts("\x1b[32m\'---------------------------\'");
      uVar1 = 1;
    }
    else {
      crypted_pwd = ((int)username[3] ^ 0x1337U) + 0x5eeded;
      for (i = 0; i < (int)len; i = i + 1) {
        if (username[i] < ' ') {
          return 1;
        }
        crypted_pwd = crypted_pwd + ((int)username[i] ^ crypted_pwd) % 0x539;
      }
      printf("Serial: %d\n", serial);
      printf("Crypted pwd: %d\n", crypted_pwd);
      if (serial == crypted_pwd) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

int main(int argc, char **argv)
{
    printf("return value: %d\n", auth(argv[1], atoi(argv[2])));
}