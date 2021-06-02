#include <stdio.h>
#include <assert.h>

#define FILENAME "mat.txt"
#define MAX_DIM 50

typedef struct{
    int i,j,h,l;
} isola;

// controlla se il punto si trova in un'isola già trovata sulla verticale
void stampaIsola(isola*,int);

void leggiMatrice(int mat[][MAX_DIM], int maxR, int *nr, int *nc);
int riconosciRegione(int mat[][MAX_DIM],int nr,int nc,int i,int j, int *l,int *h);

int main() {
    FILE *fp;
    int nr,nc,mat[MAX_DIM][MAX_DIM],
            i,j,cont_isole = 0,
            i_max,val_max;

    // in una matrice quadrata con dimensione n pari
    // ci sono al massimo (n/2)^2 isole di dimensione 1x1
    // se MAX_DIM fosse dispari la formula sarebbe
    // (n/2+1)^2 + (n/2)^2 dove '/' indica la divisione intera
    isola isole[MAX_DIM*MAX_DIM/4];

    leggiMatrice(mat,MAX_DIM,&nr,&nc);

    // ricerca isole
    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            if (riconosciRegione(mat,nr,nc,i,j,&isole[cont_isole].l,&isole[cont_isole].h)) {
                isole[cont_isole].i = i;
                isole[cont_isole].j = j;

                // non controllo le colonne che so già essere occupate dall'isola che ho già trovato
                j += isole[cont_isole].l-1;

                cont_isole++;
            }
        }
    }

    // ricerco altezza massima
    val_max = isole[0].h;
    i_max = 0;
    for(i = 1; i < cont_isole; i++) {
        if(isole[i].h > val_max) {
            val_max = isole[i].h;
            i_max = i;
        }
    }
    printf("Altezza massima: ");
    stampaIsola(isole,i_max);

    //ricerco larghezza massima
    val_max = isole[0].l;
    i_max = 0;
    for(i = 1; i < cont_isole; i++) {
        if(isole[i].l > val_max) {
            val_max = isole[i].l;
            i_max = i;
        }
    }
    printf("Larghezza massima: ");
    stampaIsola(isole,i_max);

    //ricerco area massima
    val_max = isole[0].h*isole[0].l;
    i_max = 0;
    for(i = 1; i < cont_isole; i++) {
        if(isole[i].h*isole[i].l > val_max) {
            val_max = isole[i].h*isole[i].l;
            i_max = i;
        }
    }
    printf("Area massima: ");
    stampaIsola(isole,i_max);

    return 0;
}



void leggiMatrice(int mat[][MAX_DIM], int maxR, int *nr, int *nc) {
    // apertura file
    FILE *fp = fopen(FILENAME,"r");
    assert(fp != NULL);

    //lettura numero di righe e numero di colonne
    assert(fscanf(fp, "%d %d\n", nr, nc) == 2);

    //lettura matrice
    for (int i = 0; i < *nr; i++) {
        for (int j = 0; j < *nc; j++) {
            assert(fscanf(fp, "%d ", &mat[i][j]) == 1);
        }
    }

    //chiusura file
    fclose(fp);
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

void stampaIsola(isola isole[],int i) {
    printf("estremo:(%d,%d), altezza=%d, larghezza=%d, area=%d.\n",
           isole[i].i,isole[i].j,isole[i].h,isole[i].l,isole[i].l*isole[i].h);
}