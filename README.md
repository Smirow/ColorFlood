# ColorFlood

## Coding Style

Pour comprendre le code, commencer par lire `board.h`.
Le `main` se trouve dans `colorflood.c`.

Le style doit rester constant, aligné et harmonieux :
- Indentation avec des tabulations uniquement, alignement avec des espaces.
- Anglais pour les symboles, français pour les commentaires.
- Pour plus de détails : http://suckless.org/coding_style

## Design du plateau de jeu

Une structure `Board` qui contient un champ `size` avec la largeur
du plateau et un tableau 1D de non-signés sur 1 octet,
unsigned char, donc jusqu'à 255 couleurs.

On accède aux cases de la même manière qu'avec un tableau 2D en
utilisant la macro XY.
