## Malloc

Il n'est pas nécessaire d'ajuste les allocations mémoire, un "gros" malloc peut faire l'affaire. Note, ceci est valable uniquement pour les exams.
Cela peut souvent éviter de faire de longs calculs pour avoir la taille optimale.
Exemple: dans count island, les maps ne ferons jamais plus de 1000x1000.
```
	char **map;

	map = malloc(sizeof(char *) * 1001);
	while (i < 1000)
		map[i] = malloc(sizeof(char) * 1001);
```
