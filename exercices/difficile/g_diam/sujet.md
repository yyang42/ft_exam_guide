Le programme prend en paramètre une chaine de caractères. Cette chaine représente un graphe et est composée d’une suite d’arêtes entre les noeuds de ce graphe. Les arêtes sont séparées par un espace. Les noeuds sont représentées par des nombres et les arête par deux noeuds séparés par ’-’. Par exemple, s’il éxiste une arête entre le noeud 2 et le noeud 3, les representations possibles de cette arête seront soit
 "2-3", soit "3-2"
.Le programme devra aﬃcher la longueur du plus long chemin suivit d’un ’\n’
 sachantqu’il est impossible de revenir en arrière. c’est-à-dire de passer par un noeud plus d’une fois.
 Si le nombre de paramètres transmis est diﬀérent de 1, le programme aﬃche ’\n’
.
$>./g_diam "17-5 5-8 8-2 2-8 2-8 17-21 21-2 5-2 2-6 6-14 6-12 12-19 19-14 14-42" | cat -e
10$
$>./g_diam "1-2 2-3 4-5 5-6 6-7 7-8 9-13 13-10 10-2 10-11 11-12 12-8 16-4 16-11 21-8 21-12 18-10 18-13 21-18" | cat -e
15$



EX: g_diam
= G_DIAM =======================================================================

== Test 1
$ ./user_exe "9-23 9-2122 2122-23 2122-24 31-2122 31-41 71-31 8-71 42-71"

$ diff --suppress-common-lines user.out test1.output | cat -e
Good !

== Test 2
$ ./user_exe "5-56 9-56 7-9 49-9 49-36 7-36 21-7 21-17"

$ diff --suppress-common-lines user.out test2.output | cat -e
Good !

== Test 3
$ ./user_exe "0-4 0-3 0-1 0-2 1-2 1-0 1-4 1-5 2-4 3-2 3-4 3-0 3-1 4-0 4-1 4-5 4-2 5-4 5-3 5-1 5-0"

$ diff --suppress-common-lines user.out test3.output | cat -e
Good !

== Test 4
$ ./user_exe "0-2 0-3 0-1 1-3 1-2 2-3 3-1 3-0"

$ diff --suppress-common-lines user.out test4.output | cat -e
Good !

== Test 5
$ ./user_exe "0-2 0-1 1-3 1-4 1-5 1-2 2-6 2-1 3-2 3-7 3-6 3-1 4-1 4-7 4-6 5-6 5-2 6-5 6-7 6-4 6-3 6-1 6-0 6-2 7-1 7-5 7-3"

$ diff --suppress-common-lines user.out test5.output | cat -e
Good !

== Test 6
$ ./user_exe "0-2 0-1 1-3 1-6 1-0 1-5 2-5 2-6 3-6 3-4 3-5 3-0 3-1 3-2 4-6 5-4 5-2 5-0 5-3 5-6 6-0"

$ diff --suppress-common-lines user.out test6.output | cat -e
Good !
