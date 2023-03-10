# gdb writeup
```bash
level09@OverRide:~$ gdb ./level09 -q
Reading symbols from /home/users/level09/level09...(no debugging symbols found)...done.
(gdb) b main
Breakpoint 1 at 0xaac
(gdb) r
Starting program: /home/users/level09/level09 
warning: no loadable sections found in added symbol-file system-supplied DSO at 0x7ffff7ffa000

Breakpoint 1, 0x0000555555554aac in main ()
(gdb) disas secret_backdoor 
Dump of assembler code for function secret_backdoor:
   0x000055555555488c <+0>:     push   %rbp
   0x000055555555488d <+1>:     mov    %rsp,%rbp
   0x0000555555554890 <+4>:     add    $0xffffffffffffff80,%rsp
   0x0000555555554894 <+8>:     mov    0x20171d(%rip),%rax        # 0x555555755fb8
   0x000055555555489b <+15>:    mov    (%rax),%rax
   0x000055555555489e <+18>:    mov    %rax,%rdx
   0x00005555555548a1 <+21>:    lea    -0x80(%rbp),%rax
   0x00005555555548a5 <+25>:    mov    $0x80,%esi
   0x00005555555548aa <+30>:    mov    %rax,%rdi
   0x00005555555548ad <+33>:    callq  0x555555554770 <fgets@plt>
   0x00005555555548b2 <+38>:    lea    -0x80(%rbp),%rax
   0x00005555555548b6 <+42>:    mov    %rax,%rdi
   0x00005555555548b9 <+45>:    callq  0x555555554740 <system@plt>
   0x00005555555548be <+50>:    leaveq 
   0x00005555555548bf <+51>:    retq   
End of assembler dump.
(gdb)
```
We can see that the function `secret_backdoor` is calling `system`

So we will enter the address of the function `secret_backdoor` after our segfault and see what happend

[Go back](readme.md)