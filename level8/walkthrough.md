# Level8
---


Objectif de ce level et d'allouer la memoir dans la stack pour que la zone memoire Auth + 32 soit allouer.

En lancant le level 8 un prompt s'ouvre.
Ce prompt attend 4 command different.

"auth ": qui alloue la memoire de la variable auth de 9 
"service": qui alloue la memoire de la variable service de 13
"reset": qui free la memoire de la variable auth
"login": qui check si auth + 32 et allouer . Si oui alors lance un sh

voici la combinaison a suivre:
```bash 
./level8
	auth |
	service
	service
	login
```

Dans le terminal on execute la commande suivante pour récupérer le password du level9:

```bash
cat /home/user/level9/.pass
```