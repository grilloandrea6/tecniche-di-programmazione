/*
 * Laboratorio 8 esercizio 1
 * Autore: Andrea Grillo
 * Data: Maggio 2021
 *
 * Versione 2 senza salvataggio delle regioni in vettore di struct.
 * Per una versione con il salvataggio vedasi file main.c.
 */

#include <stdio.h>
#include <assert.h>

#define FILENAME "mat.txt"
#define MAX_DIM 50

typedef struct{
    int i,j,h,l;
} isola;

void leggiMatrice(int[][MAX_DIM], int, int*, int*);
void stampaIsola(isola*, int);
void salvaIsola(isola*,int, int, int, int, int);
int riconosciRegione(int[][MAX_DIM], int, int, int, int, int*, int*);

int main() {
    int nr,nc,mat[MAX_DIM][MAX_DIM],
            i,j,l,h,prima_iterazione = 1;

    isola isole[3];
    // isole[0] = isola di h max
    // isole[1] = isola di l max
    // isole[2] = isola di area max

    leggiMatrice(mat,MAX_DIM,&nr,&nc);

    // DEBUG - stampo matrice
    /*for(i=0;i < nr;i++) {
        for (j = 0; j < nc; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }*/

    // ricerca isole
    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            if (riconosciRegione(mat,nr,nc,i,j,&l,&h)) {

                // se è la prima iterazione la salvo in tutti e tre gli elementi del vettore
                if(prima_iterazione) {
                    for (int k = 0; k < 3; k++) {
                        salvaIsola(isole,k,i,j,h,l);
                    }
                    prima_iterazione = 0;
                }

                if(h > isole[0].h) {
                    salvaIsola(isole,0,i,j,h,l);
                }

                if(l > isole[1].l) {
                    salvaIsola(isole,1,i,j,h,l);
                }

                if((h*l) > (isole[2].h*isole[2].l)) {
                    salvaIsola(isole,2,i,j,h,l);
                }

                // non controllo le colonne che so già essere occupate dall'isola che ho già trovato
                j += l-1;
            }
        }
    }

    printf("Altezza massima: ");
    stampaIsola(isole,0);

    printf("Larghezza massima: ");
    stampaIsola(isole,1);

    printf("Area massima: ");
    stampaIsola(isole,2);

    return 0;
}

void leggiMatrice(int mat[][MAX_DIM], int maxR, int *nr, int *nc) {
    // apertura file
    FILE *fp = fopen(FILENAME,"r");
    assert(fp != NULL);

    //lettura numero di righe e numero di colonne
    assert(fscanf(fp, "%d %d\n", nr, nc) == 2);
    assert(*nr < maxR && *nc < MAX_DIM);

    //lettura matrice
    for (int i = 0; i < *nr; i++) {
        for (int j = 0; j < *nc; j++) {
            assert(fscanf(fp, "%d ", &mat[i][j]) == 1);
        }
    }

    //chiusura file
    fclose(fp);
}


void stampaIsola(isola isole[],int i) {
    printf("estremo=(%d,%d), altezza=%d, larghezza=%d, area=%d.\n",
           isole[i].i,isole[i].j,isole[i].h,isole[i].l,isole[i].l*isole[i].h);
}

void salvaIsola(isola* isole,int k,int i,int j,int h,int l) {
    isole[k].i = i;
    isole[k].j = j;
    isole[k].h = h;
    isole[k].l = l;
}

int riconosciRegione(int mat[][MAX_DIM],int nr,int nc,int i,int j, int *l,int *h) {
    if(mat[i][j] == 1 &&
       (i == 0 || mat[i-1][j] == 0) &&
       (j == 0 || mat[i][j - 1] == 0)) {

        // ho trovato l'estremo

        // calcolo l'estensione della regione
        for (*h = 0;
             *h < nr - i && mat[*h + i][j] == 1;
             (*h)++);

        for (*l = 0;
             *l < nc - j && mat[i][*l + j] == 1;
             (*l)++);

        return 1;
    }
    return 0;
}
