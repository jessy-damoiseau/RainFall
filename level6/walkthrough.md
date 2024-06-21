


# Level5

---
###### Étape 1 : -- Décompiler le programme --

En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme trois fonctions N, M et Main.

Dans le Main on voit deux variable malloc. 
- la premiere a 64 que sert a stocker un str.
- la deuxieme a 4 qui sert a stocker un pointer de fonction.

la fonction N contient un system call pour lire le .pass du prochain level sauf quel n'est jamais appeler. 

l 'objectif vas etre d'overflow le str[64] pour cette l'addresse de la fonction N dans la variable pointant vers une fonction. Sachant que cette variable et appeler a la fin du programe.

###### Étape 2: -- Récuperation d'information --

Depuis __GDB__, on cherche où ce situe la limite de la variable malloc a 64 avec la fonction __strcpy__, ce qui nous permet de calculer un _offset_ qui nous permetra d'overflow la fonction. On obtient un offset de ==72==.

on cherche ensuite l'addresse de la fonction __N__ dans __GDB__ -> ==0x08048454==.

###### Étape 3: -- Execution --

On crée un one-liner python pour executer un payload pour un overflow la variable pointer sur fonction qui nous permetra d'accéder à la fonction ___N___.

Contruction du payload: 
> (python - c 'print "A" + [offset] + [function_address]'; cat -) | ./binary

Payload final :

```bash
./level6 $(python -c 'print "A" * 72 + "\x54\x84\x04\x08"')
```