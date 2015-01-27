
# Quand vous codez

## Bien connaître vos fonctions de base

e.g. strcat, strdup,


# Approche exo

## Facile
e.g. strdup, rotXX
1. Revoir le dossier srcs
2. Ecrivez et testez vos fonction en utilisant un fichier srcs/__lib.c par exemple.

## Intermediaire
e.g. strsplit, inter, union
1. Diviser le probleme en plusieurs fonctions.

## Difficulte

e.g. strcat, strdup,

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









## Exercice levels

1. Facile



2. Intermedaire

- inter
- union

3. Difficile

- count island
- maxlenoc
- gdiam
