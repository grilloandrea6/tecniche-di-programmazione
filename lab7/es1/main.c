#include <stdio.h>
#include <assert.h>

#define FILENAME "mat.txt"
#define MAX_DIM 50

typedef struct{
    int i,j,h,l;
} isola;

// controlla se il punto si trova in un'isola già trovata sulla verticale
int inIsola(int i, int j, isola isole[], int cont_isole);

void stampaIsola(isola*,int);

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

    // apertura file
    fp = fopen(FILENAME,"r");
    assert(fp != NULL);

    //lettura numero di righe e numero di colonne
    assert(fscanf(fp,"%d %d\n",&nr,&nc) == 2);

    //lettura matrice
    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            assert(fscanf(fp,"%d ",&mat[i][j]) == 1);
        }
    }

    // ricerca isole
    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {
            if (mat[i][j] == 1 && !inIsola(i,j,isole,cont_isole)) {
                isole[cont_isole].i = i;
                isole[cont_isole].j = j;

                for (isole[cont_isole].h = 0;
                     isole[cont_isole].h < nr - i && mat[isole[cont_isole].h + i][j] == 1;
                     isole[cont_isole].h++);

                for (isole[cont_isole].l = 0;
                     isole[cont_isole].l < nc - j && mat[i][isole[cont_isole].l + j] == 1;
                     isole[cont_isole].l++);

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


// controlla se il punto si trova in un'isola già trovata
int inIsola(int i, int j, isola *isole, int cont_isole) {
    for(int cont = 0; cont < cont_isole;cont++) {
        if(j >= isole[cont].j && j < isole[cont].j + isole[cont].l &&
            i >= isole[cont].i && i < isole[cont].i + isole[cont].h) {
            return 1;
        }
    }
    return 0;
}

void stampaIsola(isola isole[],int i) {
   printf("estremo:(%d,%d), altezza=%d, larghezza=%d, area=%d.\n",
          isole[i].i,isole[i].j,isole[i].h,isole[i].l,isole[i].l*isole[i].h);
}