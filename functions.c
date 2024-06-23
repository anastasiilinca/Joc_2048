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

void valid_moves(int board[4][4], int *st, int *dr, int *sus, int *jos) {
    int i, j, k;
    (*st) = 0;
    (*dr) = 0;
    (*sus) = 0;
    (*jos) = 0;
    // se verifica existenta unei mutari valide la stanga
    for (i = 0; i < 4; i++)
    {
        for (j = 1; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                k = j;
                while (k > 0 && board[i][k - 1] == 0 && (*st) == 0)
                {
                    (*st) = 1;
                }
            }
        }
    }
    // se verifica existenta unei mutari valide la dreapta
    for (i = 0; i < 4; i++)
    {
        for (j = 2; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                k = j;
                while (k < 3 && board[i][k + 1] == 0 && (*dr) == 0) {
                    (*dr) = 1;
                }       
            }
        }
    }
    // se verifica existenta unei mutari valide in sus
    for (j = 0; j < 4; j++)
    {
        for (i = 0; i < 4; i++)
        {
            if (board[i][j] != 0)
            {
                k = i;
                while (k != 0 && board[k - 1][j] == 0 && (*sus) == 0)
                {
                    (*sus) = 1;
                }
            }
        }
    }
    // se verifica existenta unei mutari valide in jos
    for (j = 0; j < 4; j++)
    {
        for (i = 3; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                k = i;
                while (k != 3 && board[k + 1][j] == 0 && (*jos) == 0)
                {
                    (*jos) = 1;
                }
            }
        }
    }
}

// functie care coloreaza celulele valide
void print_color(WINDOW *game, int board[4][4])
{
    int i, j;
    // parcurge matricea tablei si coloreaza, linie cu linie,
    // celulele in functie de cifra continuta
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                if (board[i][j] == 2)
                {
                    // printarea fundalului celulei 
                    wattron(game, COLOR_PAIR(2));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    // printarea numarului celulei
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(2));
                    wrefresh(game);
                }
                else if (board[i][j] == 4)
                {
                    wattron(game, COLOR_PAIR(4));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(4));
                    wrefresh(game);
                }
                else if (board[i][j] == 8)
                {
                    wattron(game, COLOR_PAIR(8));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(8));
                    wrefresh(game);
                }
                else if (board[i][j] == 16)
                {
                    wattron(game, COLOR_PAIR(16));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(16));
                    wrefresh(game);
                }
                else if (board[i][j] == 32)
                {
                    wattron(game, COLOR_PAIR(32));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(32));
                    wrefresh(game);
                }
                else if (board[i][j] == 64)
                {
                    wattron(game, COLOR_PAIR(64));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(64));
                    wrefresh(game);
                }
                else if (board[i][j] == 128)
                {
                    wattron(game, COLOR_PAIR(128));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(128));
                    wrefresh(game);
                    // intrucat sunt doar 7 culori disponibile, numerele
                    // ramase sunt colorate cu 2 culori
                }
                else if (board[i][j] == 256)
                {
                    wattron(game, COLOR_PAIR(2));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    wattroff(game, COLOR_PAIR(2));
                    wattron(game, COLOR_PAIR(4));
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(4));
                    wrefresh(game);
                }
                else if (board[i][j] == 512)
                {
                    wattron(game, COLOR_PAIR(8));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    wattroff(game, COLOR_PAIR(8));
                    wattron(game, COLOR_PAIR(16));
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(16));
                    wrefresh(game);
                }
                else if (board[i][j] == 1024)
                {
                    wattron(game, COLOR_PAIR(2));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    wattroff(game, COLOR_PAIR(2));
                    wattron(game, COLOR_PAIR(128));
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(128));
                    wrefresh(game);
                }
                else
                {
                    wattron(game, COLOR_PAIR(8));
                    mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                    wattroff(game, COLOR_PAIR(8));
                    wattron(game, COLOR_PAIR(4));
                    mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                    mvwprintw(game, 2 + i * 4, 5 + j * 10, "%d", board[i][j]);
                    wattroff(game, COLOR_PAIR(4));
                    wrefresh(game);
                }
            }
            // golirea celulelor libere
            else
            {
                mvwprintw(game, 1 + i * 4, 1 + j * 10, "        ");
                mvwprintw(game, 2 + i * 4, 1 + j * 10, "        ");
                mvwprintw(game, 3 + i * 4, 1 + j * 10, "        ");
                wrefresh(game);
            }
        }
    }
}

// functie care returneaza 1 daca jocul a ajuns la un final castigator
int game_won(int board[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (board[i][j] == 2048)
            {
                return 1;
            }
        }
    }
    return 0;
}

// functie care returneaza 1 daca jucatorul a pierdut runda
// pentru ca nu mai exista mutari valide
int game_over(int board[4][4])
{
    // "full" = verifica daca tabla este complet plina de celule
    int i, j, full = 0, same_on_line = 0, same_on_col = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                full = 1;
            }
            // se verifica daca exista celule identice alaturate care pot
            // rezulta o mutare valida prin unire pe linii/coloane
            if (j < 3 && board[i][j] == board[i][j + 1])
            {
                same_on_line = 1;
            }
            if (i < 3 && board[i][j] == board[i + 1][j])
            {
                same_on_col = 1;
            }
        }
    }
    // daca ambele conditii sunt indeplinite, jocul e pierdut
    if (full == 0 && same_on_col == 0 && same_on_line == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

// functie care efectueaza mutarea care elibereaza cele mai multe
// celule automat
// x = 1 -> auto_play
// x = 0 -> verifica daca mutarea e valida pe o directie
void auto_play (WINDOW *game, int board[4][4], int *valid_mv, int *punctaj) {
    int i, j, k, cp_st[4][4], cp_sus[4][4], cp_dr[4][4], cp_jos[4][4], pnctj_vert = 0, pnctj_lat = 0;
    // variabilele ok_x verifica daca miscarile stanga, dreapta, sus, jos
    // produc macar o mutare banala (cu sau fara un merge) 
    // al casutelor valide
    int ok_sus = 0, ok_st = 0, ok_dr = 0, ok_jos = 0; 
    // cream 4 copii ale tablei
    for (i = 0; i < 4; i++) {
        for (j = 0;j < 4; j++) {
            cp_st[i][j] = board[i][j];
            cp_dr[i][j] = board[i][j];
            cp_sus[i][j] = board[i][j];
            cp_jos[i][j] = board[i][j];
        }
    }
    // efectuam mutarea + merge-ul care ar rezulta in urma apasarii
    // tastei KEY_LEFT si calculam punctajul pentru acest caz
    for(i = 0; i < 4; i++) {
        for(j = 1; j < 4; j++) {
            if(cp_st[i][j] != 0) {
                k = j;
                while(k > 0 && cp_st[i][k-1] == 0) {
                    ok_st = 1;
                    cp_st[i][k-1] = cp_st[i][k];
                    cp_st[i][k] = 0;
                    --k;
                }
            }
        }
    }
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 3; j++) {
            if( cp_st[i][j] == cp_st[i][j+1] && cp_st[i][j] != 0) {
                ok_st = 1;
                cp_st[i][j] = cp_st[i][j] * 2;
                pnctj_lat = pnctj_lat + cp_st[i][j];
                for( k = j + 2; k < 4; k++) {
                    cp_st[i][k-1] = cp_st[i][k]; 
                }
                cp_st[i][3] = 0;
            }
        }
    }
    // efectuam mutarea care ar rezulta in urma apasarii
    // tastei KEY_UP si calculam punctajul pentru acest caz
    for(j = 0; j < 4; j++) {
        for(i = 0; i < 4; i++) {
            if(cp_sus[i][j] != 0) {
                k = i;
                while(k != 0 && cp_sus[k-1][j] == 0) {
                    ok_sus = 1;
                    cp_sus[k-1][j] = cp_sus[k][j];
                    cp_sus[k][j] = 0;
                    --k;
                }
            }
        }
    }
    for( j = 0; j < 4; j++) {
        for( i = 0; i < 3; i++) {
            if(cp_sus[i][j] == cp_sus[i+1][j] && cp_sus[i][j] != 0) {
                ok_sus = 1;
                cp_sus[i][j] = cp_sus[i][j] * 2;
                pnctj_vert = pnctj_vert + cp_sus[i][j];
                for(k = i + 2; k < 4; k++) {
                    cp_sus[k-1][j] = cp_sus[k][j];
                } 
                cp_sus[3][j] = 0;
            }
        }
    }
    // efectuam mutarea care ar rezulta in urma apasarii
    // tastei KEY_RIGHT si calculam punctajul pentru acest caz
    for(i = 0; i < 4; i++) {
        for(j = 2; j >= 0; j--) {
            if(cp_dr[i][j] != 0) {
                k = j;
                while(k < 3 && cp_dr[i][k+1] == 0) {
                    ok_dr = 1;
                    cp_dr[i][k+1] = cp_dr[i][k];
                    cp_dr[i][k] = 0;
                    ++k;
                }
            }
        }
    }
    for( i = 0; i < 4; i++) {
        for(j = 3; j > 0; j--) {
            if(cp_dr[i][j] == cp_dr[i][j-1] && cp_dr[i][j] != 0) {
                ok_dr = 1;
                cp_dr[i][j] = cp_dr[i][j] * 2;
                for(k = j - 2; k >= 0; k--) {
                    cp_dr[i][k+1] = cp_dr[i][k]; 
                }
                cp_dr[i][0] = 0;
            }
        } 
    }
    // efectuam mutarea care ar rezulta in urma apasarii
    // tastei KEY_DOWN si calculam punctajul pentru acest caz
    for(j = 0; j < 4; j++) {
        for(i = 3; i >= 0; i--) {
            if(cp_jos[i][j] != 0) {
                k = i;
                while(k != 3 && cp_jos[k+1][j] == 0) {
                    ok_jos = 1;
                    cp_jos[k+1][j] = cp_jos[k][j];
                    cp_jos[k][j] = 0;
                    ++k;
                }
            }
        }
    }
    for( j = 0; j < 4; j++) {
        for( i = 3; i > 0; i--) {
            if(cp_jos[i][j] == cp_jos[i-1][j] && cp_jos[i][j] != 0) {
                ok_jos = 1;
                cp_jos[i][j] = cp_jos[i][j] * 2;
                for(k = i - 2; k >=0; k--) {
                    cp_jos[k+1][j] = cp_jos[k][j];
                } 
                cp_jos[0][j] = 0;
            }
        }
    }
    // in functie de punctaj, vedem care miscare este cea mai favorabila

    // daca punctajul pe axa orizontala este mai mare, efectuam miscarea la 
    // stanga (tinem cont ca miscarea la dreapta si cea la stanga rezulta
    // acelasi numar de puncte)
    if(ok_st == 1 || ok_sus == 1) {
        if (pnctj_lat > pnctj_vert) {
            for (i = 0; i < 4; i++) {
                for (j = 0;j < 4; j++) {
                    board[i][j] = cp_st[i][j];
                }
            }
            (*punctaj) = (*punctaj) + pnctj_lat;
        // daca punctajul pe axa verticala este mai mare, efectuam miscarea in 
        // sus (tinem cont ca miscarea in sus si cea in jos rezulta
        // acelasi numar de puncte)
        } else if (pnctj_lat <= pnctj_vert) {
            for (i = 0; i < 4; i++) {
                for (j = 0;j < 4; j++) {
                    board[i][j] = cp_sus[i][j];
                }
            }
            (*punctaj) = (*punctaj) + pnctj_vert;
        }
        (*valid_mv) = 1;
    // daca punctajul vertical si cel orizontal sunt ambele nule, vedem 
    // care din miscari poate produce o mutare banala a casutelor valide  
    } else {
        if(ok_dr == 1) {
            for (i = 0; i < 4; i++) {
                for (j = 0;j < 4; j++) {
                    board[i][j] = cp_dr[i][j];
                }
            }
            (*valid_mv) = 1;
        } else if (ok_jos == 1){
            for (i = 0; i < 4; i++) {
                for (j = 0;j < 4; j++) {
                    board[i][j] = cp_jos[i][j];
                }
            }
            (*valid_mv) = 1;
        }
    }
}

// functie care adauga o noua celula random cu valoarea 2 sau 4
void add_token(WINDOW *game, int board[4][4])
{
    int x = 0, y = 0, val = 0, ok = 0;
    srand(time(NULL));
    while (ok == 0)
    {
        x = rand() % 4;
        y = rand() % 4;
        if (board[x][y] == 0)
        {
            ok = 1;
            val = rand() % 2;
            if (val == 0)
            {
                val = 2;
            }
            else
            {
                val = 4;
            }
            board[x][y] = val;
        }
    }
}

// functie care uneste celulele identice alaturate in cadrul unei mutrai
void merge(WINDOW *game, int board[4][4], int select, int *valid_mv, int *punctaj)
{
    curs_set(0);
    int i, j, k;
    keypad(game, TRUE);
    switch (select)
    {
    case KEY_LEFT:
        // daca s-a apasat tasta KEY_LEFT, se unesc toate celulele identice
        // alaturate in celula din stanga
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
                {
                    (*valid_mv) = 1;
                    board[i][j] = board[i][j] * 2;
                    // se mareste punctajul cu valoarea noii celule
                    (*punctaj) = (*punctaj) + board[i][j];
                    for (k = j + 2; k < 4; k++)
                    {
                        board[i][k - 1] = board[i][k];
                    }
                    board[i][3] = 0;
                }
            }
        }
        break;
    case KEY_RIGHT:
        // daca s-a apasat tasta KEY_RIGHT, se unesc toate celulele identice
        // alaturate in celula din dreapta
        for (i = 0; i < 4; i++)
        {
            for (j = 3; j > 0; j--)
            {
                if (board[i][j] == board[i][j - 1] && board[i][j] != 0)
                {
                    (*valid_mv) = 1;
                    board[i][j] = board[i][j] * 2;
                    (*punctaj) = (*punctaj) + board[i][j];
                    for (k = j - 2; k >= 0; k--)
                    {
                        board[i][k + 1] = board[i][k];
                    }
                    board[i][0] = 0;
                }
            }
        }
        break;
    case KEY_UP:
        // daca s-a apasat tasta KEY_UP, se unesc toate celulele identice
        // alaturate in celula de deasupra
        for (j = 0; j < 4; j++)
        {
            for (i = 0; i < 3; i++)
            {
                if (board[i][j] == board[i + 1][j] && board[i][j] != 0)
                {
                    (*valid_mv) = 1;
                    board[i][j] = board[i][j] * 2;
                    (*punctaj) = (*punctaj) + board[i][j];
                    for (k = i + 2; k < 4; k++)
                    {
                        board[k - 1][j] = board[k][j];
                    }
                    board[3][j] = 0;
                }
            }
        }
        break;
    case KEY_DOWN:
        // daca s-a apasat tasta KEY_DOWN, se unesc toate celulele identice
        // alaturate in celula de jos
        for (j = 0; j < 4; j++)
        {
            for (i = 3; i > 0; i--)
            {
                if (board[i][j] == board[i - 1][j] && board[i][j] != 0)
                {
                    (*valid_mv) = 1;
                    board[i][j] = board[i][j] * 2;
                    (*punctaj) = (*punctaj) + board[i][j];
                    for (k = i - 2; k >= 0; k--)
                    {
                        board[k + 1][j] = board[k][j];
                    }
                    board[0][j] = 0;
                }
            }
        }
        break;
    default:
        break;
    }
}

// functia care efectueaza jocul in sine
void play(WINDOW *game, int board[4][4], int *punctaj)
{
    curs_set(0);
    halfdelay(100);
    int select, i, j, k, *valid_mv, pnctj_mutare, nr_helps = 0;
    int *dr, *st, *sus, *jos;
    char last_cmd[10], k_u[10] = "KEY_UP", k_d[10] = "KEY_DOWN", k_l[10] = "KEY_LEFT", k_r[10] = "KEY_RIGHT";
    time_t *t;
    struct tm *date;
    t = (time_t *)malloc(sizeof(time_t));
    date = (struct tm *)malloc(sizeof(struct tm));
    valid_mv = (int *)malloc(sizeof(int));
    dr = (int *)malloc(sizeof(int));
    st = (int *)malloc(sizeof(int));
    sus = (int *)malloc(sizeof(int));
    jos = (int *)malloc(sizeof(int));
    // mutarea celulelor (fara merge)
    while (1)
    {
        (*valid_mv) = 0;
        keypad(game, TRUE);
        select = wgetch(game);
        pnctj_mutare = (*punctaj);
        // se asteapta apasarea unei taste directionale
        // in functie de tatsa apasata, se muta toate celulele in acea directe
        // cat mai aproape de margine posibil
        switch (select)
        {
        case KEY_LEFT:
            // se retine tasta ultimei mutari (in toate cazurile)
            strcpy(last_cmd, k_l);
            for (i = 0; i < 4; i++)
            {
                for (j = 1; j < 4; j++)
                {
                    if (board[i][j] != 0)
                    {
                        k = j;
                        while (k > 0 && board[i][k - 1] == 0)
                        {
                            // se retine in 'valid_mv' daca mutarea
                            // a fost valida
                            (*valid_mv) = 1;
                            board[i][k - 1] = board[i][k];
                            board[i][k] = 0;
                            --k;
                        }
                    }
                }
            }
            break;
        case KEY_RIGHT:
            strcpy(last_cmd, k_r);
            for (i = 0; i < 4; i++)
            {
                for (j = 2; j >= 0; j--)
                {
                    if (board[i][j] != 0)
                    {
                        k = j;
                        while (k < 3 && board[i][k + 1] == 0)
                        {
                            (*valid_mv) = 1;
                            board[i][k + 1] = board[i][k];
                            board[i][k] = 0;
                            ++k;
                        }
                    }
                }
            }
            break;
        case KEY_UP:
            strcpy(last_cmd, k_u);
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    if (board[i][j] != 0)
                    {
                        k = i;
                        while (k != 0 && board[k - 1][j] == 0)
                        {
                            (*valid_mv) = 1;
                            board[k - 1][j] = board[k][j];
                            board[k][j] = 0;
                            --k;
                        }
                    }
                }
            }
            break;
        case KEY_DOWN:
            strcpy(last_cmd, k_d);
            for (j = 0; j < 4; j++)
            {
                for (i = 3; i >= 0; i--)
                {
                    if (board[i][j] != 0)
                    {
                        k = i;
                        while (k != 3 && board[k + 1][j] == 0)
                        {
                            (*valid_mv) = 1;
                            board[k + 1][j] = board[k][j];
                            board[k][j] = 0;
                            ++k;
                        }
                    }
                }
            }
            break;
        // apasarea tastei 'q' redeschide meniul
        case 'q':
            wclear(game);
            wrefresh(game);
            menu(game, board, punctaj);
            break;
        // apasarea tastei 'h' conduce la efectuarea unei mutari
        // automate favorabile, ca indiciu la cererea jucatorului
        case 'h':
            if (nr_helps < 3)
            {
                auto_play(game, board, valid_mv, punctaj);
                ++nr_helps;
            }
            else
            {
                wattron(game, COLOR_PAIR(32));
                mvwprintw(game, 17, 45, "No more hints available!");
                wattroff(game, COLOR_PAIR(32));
                wrefresh(game);
            }
            break;
        // daca trec mai mult de 10 secunde, functia halfdelay() returneaza
        // ERR, asa ca se efectueaza mutarea automata
        case ERR:
            auto_play(game, board, valid_mv, punctaj);
            break;
        default:
            break;
        }
        // se unesc celulele
        merge(game, board, select, valid_mv, punctaj);
        // daca mutarea = valida, se adauga o noua celula
        if ((*valid_mv) == 1)
        {
            add_token(game, board);
        }
        wrefresh(game);
        // se coloreaza celulele
        sleep(1);
        print_color(game, board);
        *t = time(NULL);
        date = localtime(t);
        // se verifica daca jucatorul a pierdut
        if (game_over(board) == 1)
        {
            WINDOW *over = newwin(100, 100, 20, 20);
            wattron(game, COLOR_PAIR(32));
            mvwprintw(over, 25, 25, "GAME OVER");
            wattroff(game, COLOR_PAIR(32));
            wclear(game);
            wrefresh(over);
            // se verifica daca jucatroul a castigat
        }
        else if (game_won(board) == 1)
        {
            wclear(game);
            wattron(game, COLOR_PAIR(8));
            mvwprintw(game, 5, 5, "YOU WON !! CONGRATULATIONS !!");
            mvwprintw(game, 7, 7, "You reached %d points!", *punctaj);
            wattroff(game, COLOR_PAIR(8));
            wrefresh(game);
            // altfel, se continua jocul
        }
        else
        {
            // se afiseaza panoul de control
            mvwprintw(game, 1, 45, "Data: %02d.%02d.%d", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
            mvwprintw(game, 2, 45, "Ora: %02d:%02d:%02d", date->tm_hour, date->tm_min, date->tm_sec);
            mvwprintw(game, 3, 45, "Punctaj: %dp", *punctaj);
            wrefresh(game);
            mvwprintw(game, 4, 45, "Legenda mutari valide:");
            valid_moves(board, st, dr, sus, jos);
            if((*dr) == 1) {
                wattron(game, COLOR_PAIR(2));
                mvwprintw(game, 8, 48, "KEY RIGHT pentru a muta la dreapta");
                wattroff(game, COLOR_PAIR(2));
            } else {
                mvwprintw(game, 8, 48, "KEY RIGHT pentru a muta la dreapta");
            }
            if((*st) == 1) {
                wattron(game, COLOR_PAIR(2));
                mvwprintw(game, 7, 48, "KEY LEFT pentru a muta la stanga");
                wattroff(game, COLOR_PAIR(2));
            } else {
                mvwprintw(game, 7, 48, "KEY LEFT pentru a muta la stanga");
            }
            if((*sus) == 1) {
                wattron(game, COLOR_PAIR(2));
                mvwprintw(game, 5, 48, "KEY UP pentru a muta in sus");
                wattroff(game, COLOR_PAIR(2));
            } else {
                mvwprintw(game, 5, 48, "KEY UP pentru a muta in sus");
            }
            if((*jos) == 1) {
                wattron(game, COLOR_PAIR(2));
                mvwprintw(game, 6, 48, "KEY DOWN pentru a muta in jos");
                wattroff(game, COLOR_PAIR(2));
            } else {
                mvwprintw(game, 6, 48, "KEY DOWN pentru a muta in jos");
            }
            mvwprintw(game, 9, 48, "To use a hint, press key 'h'!");
            mvwprintw(game, 10, 48, "ATTENTION! You only have 3 hints available per game!");
            wattron(game, COLOR_PAIR(32));
            mvwprintw(game, 11, 48, "Hints used: %d", nr_helps);
            wattroff(game, COLOR_PAIR(32));
            mvwprintw(game, 12, 45, "                                     ");
            mvwprintw(game, 12, 45, "Last command executed: %s", last_cmd);
            wattron(game, COLOR_PAIR(8));
            mvwprintw(game, 15, 45, "+%d POINTS", (*punctaj) - pnctj_mutare);
            wattroff(game, COLOR_PAIR(8));
            wrefresh(game);
        }
    }
    wgetch(game);
    endwin();
}

// functie care genereaza pozitii diferite random pentru cele 2 celule de start
void rand_strt(int *p1x, int *p1y, int *p2x, int *p2y)
{
    srand(time(NULL));
    *p1y = rand() % 4;
    *p1x = rand() % 4;
    do
    {
        *p2x = rand() % 4;
        *p2y = rand() % 4;
    } while (*p1x == *p2x && *p1y == *p2y); 
    // transformarea in coordonate dempe tabla de joc
    *p1x = 5 + (*p1x) * 10;
    *p1y = 2 + (*p1y) * 4;
    *p2x = 5 + (*p2x) * 10;
    *p2y = 2 + (*p2y) * 4;
}

// functie care genereaza tabla de joc
void new_game()
{
    refresh();
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    srand(time(NULL));
    int ymax, xmax, i, j, *p1x, *p1y, *p2x, *p2y, val1, val2, board[4][4], x1, x2, y1, y2;
    int *punctaj;
    punctaj = (int *)malloc(sizeof(int));
    p1x = (int *)malloc(sizeof(int));
    p1y = (int *)malloc(sizeof(int));
    p2x = (int *)malloc(sizeof(int));
    p2y = (int *)malloc(sizeof(int));
    (*punctaj) = 0;
    getmaxyx(stdscr, ymax, xmax);
    WINDOW *game = initscr();
    game = newwin(100, 100, ymax / 4, xmax / 4);
    // se priteaza marginile liniilor
    for (i = 0; i < 18; i = i + 4)
    {
        for (j = 0; j < 40; j++)
        {
            mvwprintw(game, i, j, "-");
        }
    }
    // se priteaza marginile coloanelor
    for (j = 0; j < 41; j = j + 10)
    {
        for (i = 0; i < 17; i++)
        {
            mvwprintw(game, i, j, "|");
        }
    }
    // se genereaza 4 coordonate random pentru 2 celule
    rand_strt(p1x, p1y, p2x, p2y);
    // se genereaza valoarea random 2 sau 4 a celulelor
    val1 = rand() % 2;
    val2 = rand() % 2;
    if (val1 == 0)
    {
        val1 = 2;
    }
    else
    {
        val1 = 4;
    }
    if (val2 == 0)
    {
        val2 = 2;
    }
    else
    {
        val2 = 4;
    }
    wgetch(game);
    // se transforma coordonatele celulelor de start de pe tabla
    // in coordonatele lor corepsunzatoare din matricea asociata
    x1 = ((*p1x) - 5) / 10;
    x2 = ((*p2x) - 5) / 10;
    y1 = ((*p1y) - 2) / 4;
    y2 = ((*p2y) - 2) / 4;
    // se initializeaza matricea asociata
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
    board[y1][x1] = val1;
    board[y2][x2] = val2;
    print_color(game, board);
    // se incepe jocul
    play(game, board, punctaj);
}

// menu function
// parametrii sunt adaugati pentru ca, daca meniul este accesat in mijlocul
// unei runde si se apasa tasta resume, sa se poata reveni la joc
// apeland functia play careia i se dau ca parametrii tabla si matricea anterioara
// accesarii meniului
void menu(WINDOW *game, int board[4][4], int *punctaj)
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    int ymax, xmax, select, ycurs, c = 1;
    getmaxyx(stdscr, ymax, xmax);
    WINDOW *menu = initscr();
    menu = newwin(ymax / 2, xmax / 2, ymax / 4, xmax / 4);
    box(menu, 0, 0);
    int i, j;
    // printarea fundalului
    wattron(menu, COLOR_PAIR(16));
    for (i = 0; i < ymax / 2; i++)
    {
        for (j = 0; j < xmax / 2; j++)
        {
            mvwprintw(menu, i, j, " ");
        }
    }
    // printarea optiunilor
    mvwprintw(menu, 1, 1, "MENU: ");
    mvwprintw(menu, 1, 25, "New Game");
    mvwprintw(menu, 3, 25, "Resume");
    mvwprintw(menu, 5, 25, "Quit");
    wattroff(menu, COLOR_PAIR(16));
    wrefresh(menu);
    wmove(menu, 1, 25);
    ycurs = getcury(menu);
    while (c)
    {
        keypad(menu, TRUE);
        select = wgetch(menu);
        // in functie de tasta apasata, cursorul se pozitioneaza
        // pe optiunea cu o poztie mai sus/jos
        switch (select)
        {
        case KEY_UP:
            if (ycurs == 5)
            {
                wattron(menu, A_STANDOUT);
                mvwprintw(menu, 3, 25, "Resume");
                wattroff(menu, A_STANDOUT);
                wattron(menu, COLOR_PAIR(16));
                mvwprintw(menu, 1, 25, "New Game");
                mvwprintw(menu, 5, 25, "Quit");
                wattroff(menu, COLOR_PAIR(16));
                wmove(menu, 3, 25);
                ycurs = 2;
            }
            else
            {
                wattron(menu, A_STANDOUT);
                mvwprintw(menu, 1, 25, "New Game");
                wattroff(menu, A_STANDOUT);
                wattron(menu, COLOR_PAIR(16));
                mvwprintw(menu, 3, 25, "Resume");
                mvwprintw(menu, 5, 25, "Quit");
                wattroff(menu, COLOR_PAIR(16));
                wmove(menu, 1, 25);
                ycurs = 1;
            }
            wrefresh(menu);
            break;
        case KEY_DOWN:
            if (ycurs == 1)
            {
                wattron(menu, A_STANDOUT);
                mvwprintw(menu, 3, 25, "Resume");
                wattroff(menu, A_STANDOUT);
                wattron(menu, COLOR_PAIR(16));
                mvwprintw(menu, 1, 25, "New Game");
                mvwprintw(menu, 5, 25, "Quit");
                wattroff(menu, COLOR_PAIR(16));
                wmove(menu, 3, 25);
                ycurs = 2;
            }
            else
            {
                wattron(menu, A_STANDOUT);
                mvwprintw(menu, 5, 25, "Quit");
                wattroff(menu, A_STANDOUT);
                wattron(menu, COLOR_PAIR(16));
                mvwprintw(menu, 1, 25, "New Game");
                mvwprintw(menu, 3, 25, "Resume");
                wattroff(menu, COLOR_PAIR(16));
                wmove(menu, 5, 25);
                ycurs = 3;
            }
            break;
        // daca se apasa Enter, se executa optiunea pe care
        // se afla cursorul la acel moment
        case 10:
            clear();
            switch (ycurs)
            {
            // cursorul este pe linia 1 => optiunea New Game
            case 1:
                new_game();
                break;
            // cursorul este pe linia 2 => optiunea Resume
            case 2:
                wclear(menu);
                int i, j;
                // redesenam tabla
                for (i = 0; i < 18; i = i + 4)
                {
                    for (j = 0; j < 40; j++)
                    {
                        mvwprintw(game, i, j, "-");
                    }
                }
                for (j = 0; j < 41; j = j + 10)
                {
                    for (i = 0; i < 17; i++)
                    {
                        mvwprintw(game, i, j, "|");
                    }
                }
                wclear(menu);
                wrefresh(menu);
                wrefresh(game);
                // reincepem jocul cu aceeasi tabla si matrice asociata,
                // intrucat le-am transmis ca parametrii in antetul functiei
                play(game, board, punctaj);
                break;
            // cursorul este pe linia 3 => optiunea QUIT
            case 3:
                curs_set(0);
                wclear(menu);
                wattron(menu, COLOR_PAIR(2));
                mvwprintw(menu, 5, 25, "YOU QUIT - GAME OVER");
                wattroff(menu, COLOR_PAIR(2));
                wrefresh(menu);
                // se intrerupe while-ul infinit
                c = 0;
                break;
            default:
                break;
            }
            break;
        }
        wrefresh(menu);
    }
    wgetch(menu);
    endwin();
}