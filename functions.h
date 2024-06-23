#ifndef functions_h
#define functions_h
void valid_moves(int board[4][4], int *st, int *dr, int *sus, int *jos);
void auto_play(WINDOW* game, int board[4][4], int *valid_mv, int *punctaj);
void add_token(WINDOW *game, int board[4][4]);
void merge(WINDOW *game, int board[4][4], int select, int *valid_mv, int *punctaj);
void menu(WINDOW *game, int board[4][4], int *punctaj);
void play(WINDOW *game, int board[4][4], int *punctaj);
void new_game();
void rand_strt(int *p1x, int *p1y, int *p2x, int *p2y);
void print_color(WINDOW *game, int board[4][4]);
int game_over(int board[4][4]);
int game_won(int board[4][4]);
#endif