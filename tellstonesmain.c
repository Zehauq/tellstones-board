#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include "tellstonesgraphic.h"

#define MAXJETONS 7

int rdm(int borne){
        static int seme = 0;
        if (!seme){
                srandom(getpid());
                seme = 1;
        }
        return (int) random() % borne;
}

void initialis(char pioche[], char table[], char visu[], char pioche2[]){
        inittable();
        int i = rdm(MAXJETONS);
        int val1,val2;
        char temp;
        for (int n=0; n<MAXJETONS; n++)
                pioche[n] = pioche2[n];
        for (int j=0; j<i; j++){
                val1 = rdm(MAXJETONS);
		val2 = rdm(MAXJETONS);
		temp = pioche[val1];
		pioche[val1] = pioche[val2];
                pioche[val2] = temp;
        }
        for (int n=0; n<MAXJETONS; n++){
                table[n] = '-';
                visu[n] = '-';
        }
}
int max(int x, int y){
        if (x<y)
                return y;
        else
                return x;
}

void ajouter(char pioche[], char table[], char visu[]){
        int indice = 0, x = 1;
        for (int i = 0; i < MAXJETONS ; i++)
                x = x + (pioche[i] == '-');
        x = max(x - 7, 0);
        if (!x){
                while (pioche[indice]=='-')
                        indice++;
                table[indice] = pioche[indice];
                visu[indice] = pioche[indice];
                pioche[indice] = '-';
        }
}

void echanger(char table[], char visu[], int n, int n2){
        n--;
        n2--;
        char tempt, tempv;
        tempt = table[n];
        tempv = visu[n];
        table[n] = table[n2];
        visu[n] = visu[n2];
        table[n2] = tempt;
        visu[n2] = tempv;
}

void retourner(char table[], char visu[], int n){
        n--;
        if (visu[n] == table[n])
                visu[n] = '?';
        else
                visu[n] = table[n];
}

void plateau(char visu[]){
        for (int i = 0; i<MAXJETONS; i++){
                        if(visu[i] == '-')
                                effacejeton(i);
                        else(dessinejeton(i, visu[i]));
        }
        refresh();
}

int main(void) {
	int row, col;
	initscr();
	noecho();
        getmaxyx(stdscr, row, col);
        int quitter = 0;
        int compt = 0;
        int compt2 = 0;
        int x,y;
        char pioche2[MAXJETONS] = "CMEBJDH", table[MAXJETONS], visu[MAXJETONS], pioche[MAXJETONS];
        initialis(pioche, table, visu, pioche2);
        char commande;
        while (quitter == 0){
                commande = getch();
                switch (commande){
                        case 'i':
                                while (pioche[compt2] != '-')
                                        compt2++;
                                while (table[compt] != '-')
                                        pioche[compt2] = table[compt++];
                                initialis(pioche, table, visu, pioche2);
                                plateau(visu);
                                break;
                        case 'r':
                                x= getch() - '1' + 1;
                                retourner(table, visu, x);
                                plateau(visu);
                                plateau(visu);
                                break;
                        case 'a':
                                ajouter(pioche, table, visu);
                                plateau(visu);
                                break;
                        case 'e':
                                x= getch() - '1' + 1;
                                y= getch() - '1' + 1;
                                echanger(table, visu, x, y);
                                plateau(visu);
                                break;
                        case 'q':
                                quitter = 1;
                                break;
                        default:
                                break;
                }
        }
        endwin();
}