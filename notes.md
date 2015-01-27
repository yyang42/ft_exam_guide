Rendu global
1. Fichier auteur present?

Par projets
1. Nom des fichiers a rendre sont correctes?
2. Comparer avec les examples + des tests.

Notes:

## Malloc

Il n'est pas nécessaire d'ajuste les allocations mémoire, un "gros" malloc peut faire l'affaire. Note, ceci est valable uniquement pour les exams.
Cela peut souvent éviter de faire de longs calculs pour avoir la taille optimale.
Exemple: dans count island, les maps ne ferons jamais plus de 1000x1000.

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

## Makefile

	Si vous avez juste un fichier .c
	Vous pouvez utiliser 'make nom_du_fichier.c' pour le compiler

## .gitignore dans à la racine du rendu

contenu du .gitignore
```
__*
```
Vous pourrez de cette façon créer des fichiers de tests commençant par "__" sans prendre le risque les push.


