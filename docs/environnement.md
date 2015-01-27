
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
