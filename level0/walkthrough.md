## 1 - Clone executable file :
```sh
scp -P 4242 level0@<Target_IP>:level0 .
```

---

## 2 - Decompile downloaded file

Can use tools like Ghidra locally or Dogbolt online.

After finding where the main is, we can analyse and see a flaw :
```c
setresgid(local_14,local_14,local_14);
setresuid(local_18,local_18,local_18);
execv("/bin/sh",&local_20);
```
These lines let us open a new shell as the next user (here, level1).

But before accessing it, there is a check :
```c
if (iVar1 == 423)
{...}
```
So we just have to run the file with the following argument :
```bash
./level0 423
```

---

## 3 - Exploit

Lastly, since that new shell opened by the program is technically used by user level1, we can get the content of it's .pass file :
```bash
cat /home/user/level1/.pass
```

