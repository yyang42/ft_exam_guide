"Trucs et astuces pour réussir ton exam."

# Preparer son environnement de travail

## Vim

```
	vim ~/.myvimrc

	syntax on
	set number
	set mouse=a
	set paste
```

## .zprofile

	alias gw = gcc -Wall -Wextra -Werror

## .gitignore dans à la racine du rendu

contenu du .gitignore
```
__*
```
Vous pourrez de cette façon créer des fichiers de tests commençant par "__" sans prendre le risque de les push.

# Quand vous codez

## Malloc

Il n'est pas nécessaire d'ajuste les allocations mémoire, un "gros" malloc peut faire l'affaire. Note, ceci est valable uniquement pour les exams.
Cela peut souvent éviter de faire de longs calculs pour avoir la taille optimale.
Exemple: dans count island, les maps ne ferons jamais plus de 1000x1000.
```
	char **map;

	map = malloc(sizeof(char *) * 1001);
	while (i < 1000)
	{
		map[i] = malloc(sizeof(char) * 1001);
	}
```

# Vérifiez votre rendu
## Rendu

**Rendu global**
- Fichier auteur present?

**Par projets**
- Nom des fichiers a rendre sont correctes?
- Comparer avec les examples + des tests.


## Exercice levels

1. Facile
	strdup
	rotXX

2. Intermedaire
	inter
	union

3. Difficile
	count island
	maxlenoc
	gdiam
