# Bonus 3
---

Pour ce level en decompilant le binaire on vois une str __ptr__ set a ```ptr[atoi(argv[1])] = 0```

plus loin dans le code on ce rend compte que si __ptr__ et __argv[1]__ son egale alors le programe lance un sh

pour ce faire on cette argv[1] a "" (string vide)

ce qui a pour effet dans le atoi de renvoyer 0. Ce qui set ptr a vide.

alors de la comparaison __ptr__ et __argv[1]__ son tout les deux set a ___None___ ce qui lance le sh.

```bash
./bonus3 ""
```

Dans le terminal on execute la commande suivante pour récupérer le password de end:

```bash
cat /home/user/end/.pass
```
