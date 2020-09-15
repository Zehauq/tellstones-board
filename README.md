# tellstones-board#include <stdlib.h>
#include <unistd.h>

#define MAXJETONS 20

int rdm(int borne){
        static int seme = 0;
        if (!seme){
                srandom(getpid());
                seme = 1;
        }
        return (int) random() % borne;
}

void initialis(char pioche[], char table[], char visu[]){
        int i = rdm(MAXJETONS);
        int val1,val2;
        char temp;
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

void ajouter(char pioche[], char table[], char visu[]){
	char temp;
	int indice = 0;
        while (pioche[indice]='-')
                indice++;
        table[indice] = pioche[indice];
        visu[indice] = pioche[indice];
}

void echanger(char table[], char visu[], int n, int n2){
        char tempt, tempv;
        tempt = table[n];
        tempv = visu[n];
        table[n] = table[n2];
        visu[n] = visu[n2];
        table[n2] = tempt;
        visu[n2] = tempv;
}

void retourner(char table[], char visu[], int n){
        if (visu[n] = table[n])
                visu[n] = '?';
        else
                visu[n] = table[n];
}

void main(void);
        int quitter = 0;
        char pioche[MAXJETONS] = "ABCDEFGHIJKLMNOPQRST", table[MAXJETONS], visu[MAXJETONS];
        initialis(pioche, table, visu);
        while (quitter != 0){
                scanf("%c",&commande);
                switch (commande){
                        case i:
                                pioche[] = "ABCDEFGHIJKLMNOPQRST";
                                initialis(pioche, table, visu);
                                break;
                        case r:
                                scanf("%d", x);
                                retourner(table, visu, x);
                                break;
                        case a:
                                ajouter(pioche, table, visu);
                                break;
                        case e:
                                scanf("%d", x);
                                scanf("%d", y);
                                echanger(table, visu, x, y);
                                break;
                        case q:
                                quitter = 1;
                                break;
                        default:
                                break;
                }
                for (int i = 0; i<MAXJETONS; i++)
                        printf("%d", *visu[i]);
}
