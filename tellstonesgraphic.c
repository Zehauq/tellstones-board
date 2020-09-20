#include <ncurses.h>
#include "tellstonesgraphic.h"

void inittable(){
        for (int i = 1; i<121; i++)
                mvprintw(10, i, "%c", '=');
        for (int i = 1; i<121; i++)
                mvprintw(20, i, "%c", '=');
        for (int i = 1; i<8; i++)
                mvprintw(18, 36+(i*6),"%d", i);
}

void dessinejeton(int n, char c){
        n = n-3;
        int col = 60 + 6*n;
        mvprintw(13, col, "%c", '_');
        mvprintw(14, col-1, "%s", "/ \\");
        mvprintw(15, col-2, "%s%c%s", "| ",c," |");
        mvprintw(16, col-1, "%s", "\\_/");
}

void effacejeton(int n){
        n = n-3;
        int col = 60 + 6*n;
        mvprintw(13, col, "%c", ' ');
        mvprintw(14, col-1, "%s", "   ");
        mvprintw(15, col-2, "%s", "     ");
        mvprintw(16, col-1, "%s", "   ");
}