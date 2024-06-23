#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <termios.h>
#include "functions.h"

#define COLOR_GREY 11
int main(void)
{
    // se initializeaza ecranul
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    WINDOW *w = newwin(10, 10, 10, 10);
    int aux[4][4], *p;
    p = (int *)malloc(sizeof(int));
    // se verifica functionarea culorilor in terminal
    if (has_colors() == false)
    {
        endwin();
        printf("No color support!\n");
        return -1;
    }
    // se initializeaza perechile de culori
    start_color();
    init_color(COLOR_GREY, 200, 500, 600);
    init_pair(2, COLOR_WHITE, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(8, COLOR_WHITE, COLOR_GREEN);
    init_pair(16, COLOR_WHITE, COLOR_CYAN);
    init_pair(32, COLOR_WHITE, COLOR_RED);
    init_pair(64, COLOR_BLACK, COLOR_WHITE);
    init_pair(128, COLOR_WHITE, COLOR_GREY);
    getch();
    endwin();
    // se afiseaza meniul
    menu(w, aux, p);
    endwin();
    return 0;
}