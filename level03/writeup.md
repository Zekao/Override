# level03

In this level, we have an executable that takes an input and gives it to a function called `test` with `0x1337d00d` as second argument.

This function is creating a variable that will be equal to the first argument minus `0x1337d00d`.
This variable will be used for a switch case that will call a function decrypt

In the decrypt function, we can see a comparaison between a string and 'Congratulations!'. If it's equal, we will get a shell.

We can see that the string is encrypted with a XOR operation with the variable created before in the `test` function.

So we will have to find a way to make our string equal to 'Congratulations!' after the XOR operation.

With [this tool](https://www.cryptool.org/en/cto/xor) we can enter the encrypted string and the some keys to try to get "Congratulations!".

After some tries, we found that the value of the key is 18

so our input must be 322424827 (322424845 - 322424827 = 18)

```bash
level03@OverRide:~$ ./level03 
***********************************
*		level03		**
***********************************
Password:322424827
$ whoami
level04
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```