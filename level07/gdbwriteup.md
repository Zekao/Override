# gdb writeup

## Buffer Size

```asm
(gdb) b *main+520
Breakpoint 1 at 0x804892b
(gdb) r
Starting program: /home/users/level07/level07
----------------------------------------------------
  Welcome to wil's crappy number storage service!
----------------------------------------------------
 Commands:
    store - store a number into the data storage
    read  - read a number from the data storage
    quit  - exit the program
----------------------------------------------------
   wil has reserved some storage :>
----------------------------------------------------

Input command: read

Breakpoint 1, 0x0804892b in main ()
(gdb) info register
eax            0xffffd544       -10940
ecx            0xffffd600       -10752
edx            0xffffd600       -10752
ebx            0xffffd544       -10940
esp            0xffffd520       0xffffd520
ebp            0xffffd708       0xffffd708
esi            0xffffd6dc       -10532
edi            0x8048d65        134516069
eip            0x804892b        0x804892b <main+520>
eflags         0x246    [ PF ZF IF ]
cs             0x23     35
ss             0x2b     43
ds             0x2b     43
es             0x2b     43
fs             0x0      0
gs             0x63     99
(gdb) info frame
Stack level 0, frame at 0xffffd710:
 eip = 0x804892b in main; saved eip 0xf7e45513
 Arglist at 0xffffd708, args:
 Locals at 0xffffd708, Previous frame's sp is 0xffffd710
 Saved registers:
  ebx at 0xffffd6fc, ebp at 0xffffd708, esi at 0xffffd700, edi at 0xffffd704,
  eip at 0xffffd70c
(gdb)
```

So we can see that the buffer size is 0xffffd70c - 0xffffd544 = 456 