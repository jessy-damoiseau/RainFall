
# Level 1

---

- On telecharge tout d'abord l'executable.

- Une fois decompile, on trouve l'utilisation d'une fonction deprecate qui est gets.

- gets demande au user une chaine de charatere et la stocke dans une variable, mais elle ne verifie pas que ce qui est entree par l'utilisateur rentre dans la variable.

- On peut aussi trouver, apres decompilation, l'addresse de la fonction "run" qui est "08048444".

- On lance ensuite la commande suivante :
```python
(python -c 'print "a" * 76 + "\x44\x84\x04\x08"'; cat -) | ./level1
```

- Le code vas ecrire suffisament de characteres pour ecrire sur l'ensemble du buffer, sans laisser de '\0' puis, on ajoute l'addresse de la fonciton recherche, run, pour ecraser l'addresse de retour pour y acceder.

- La commande cat est presente pour eviter que python, a la fin du programme, ne ferme le fd et empeche l'utilisation du shell que l'on as pu obtenir.