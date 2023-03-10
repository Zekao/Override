# level06

In this level, we have an executable waiting for a login and a password

With ghidra, we can see an auth function
```c
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
```

We will just run it with an username and a serial and we will see the serial needed to respect the correct condition

```bash
➜  level06 git:(master) ✗ ./a.out override 4242   
Serial: 4242
Crypted pwd: 6234511
return value: 1
```

We can see that if the username is override, the serial needed is 6234511

Let's try it on the real program

```bash
level06@OverRide:~$ ./level06
***********************************
*               level06           *
***********************************
-> Enter Login: override
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6234511
Authenticated!
$ whoami
level07
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```