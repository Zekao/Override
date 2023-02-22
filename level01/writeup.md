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

`\xf7\xe6\xae\xd0` `\x70\xeb\xe5\xf7` `\xec\x97\xf8\xf7`
