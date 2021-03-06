# ColorFlood

Pour comprendre le code, commencez par lire `board.h`.

Le `main` se trouve dans `colorflood.c`.

Les choses à faire sont dans `game.c` et `game.h`.

## Installation

```sh
git clone https://github.com/theobk/ColorFlood.git
cd ColorFlood
make
```

## Utilisation

```sh
usage: ./colorflood [OPTION] < FILE
  -f <file>
  -s <size>
```

## Coding Style

Le style doit rester constant, aligné et harmonieux :
- Indentation avec des tabulations, alignement avec des espaces.
- Anglais pour les symboles, français pour les commentaires.
- Pour plus de détails : http://suckless.org/coding_style

## Design du plateau de jeu

Une structure `Board` qui contient 2 champs :
- `size` : `int`, largeur du plateau.
- `grid` : `uchar *`, grille contenant les cases du plateau.

On accède aux cases de la même manière qu'avec un tableau 2D en
utilisant la macro `XY`.
