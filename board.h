#ifdef _BOARD_H_
#error board.h is already included
#else
#define _BOARD_H_


#define COLOR_NUMBER   (6)
#define MAX_BOARD_SIZE (64)
#define MAX_GRID_LEN   (MAX_BOARD_SIZE * MAX_BOARD_SIZE)
#define XY(x, y)       (((y) * (b->size)) + (x))

enum { R, G, Y, B, M, C };

typedef struct {
	int size;    /* largeur de la grille */
	uchar *grid; /* static way ? uchar grid[MAX_GRID_LEN] */
} Board;

/* fonctions de base du plateau */
void board_init(Board *b, const int size);
void board_print(const Board *b);
void board_free(const Board *b);


#endif /* _BOARD_H_ */
