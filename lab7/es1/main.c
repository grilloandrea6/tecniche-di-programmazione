#include <stdio.h>
#include <assert.h>

#define FILENAME "mat.txt"
#define MAX_DIM 50

typedef struct{
    int i,j,h,l;
} isola;

int inIsola(int, int, isola*, int);
void stampaIsola(isola*, int);

int main() {
    int nr,nc,mat[MAX_DIM][MAX_DIM],
        i, j, cont_isole = 0;

    // per i valori massimi posso partire da zero
    // non esistendo una regione con dimensioni negative
    // verranno sicuramente sovrascritti alla prima iterazione
    int i_h_max, h_max = 0,
        i_l_max, l_max = 0,
        i_a_max, a_max = 0;

    // in una matrice quadrata con dimensione n pari
    // ci sono al massimo (n/2)^2 isole di dimensione 1x1
    // se MAX_DIM fosse dispari la formula sarebbe
    // (n/2+1)^2 + (n/2)^2 dove '/' indica la divisione intera
    isola isole[MAX_DIM*MAX_DIM/4];

    // apertura file
    FILE *fp = fopen(FILENAME,"r");
    assert(fp != NULL);

    //lettura numero di righe e numero di colonne
    assert(fscanf(fp, "%d %d\n", &nr, &nc) == 2);
    assert(nr < MAX_DIM && nc < MAX_DIM);

    //lettura matrice
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            assert(fscanf(fp, "%d ", &mat[i][j]) == 1);
        }
    }

    // chiusura file
    fclose(fp);


    // DEBUG - stampo la matrice
    /*for(i=0;i < nr;i++) {
        for (j = 0; j < nc; j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }*/


    // ricerca isole
    for(i = 0; i < nr; i++) {
        for(j = 0; j < nc; j++) {

            // se trovo un 1 che non è già stato inserito in un'altra regione allora ne ho trovata una
            if (mat[i][j] == 1 && !inIsola(i,j,isole,cont_isole)) {
                isole[cont_isole].i = i;
                isole[cont_isole].j = j;

                // misuro l'altezza della regione
                for (isole[cont_isole].h = 0;
                     isole[cont_isole].h < nr - i && mat[isole[cont_isole].h + i][j] == 1;
                     isole[cont_isole].h++);

                // misuro la larghezza
                for (isole[cont_isole].l = 0;
                     isole[cont_isole].l < nc - j && mat[i][isole[cont_isole].l + j] == 1;
                     isole[cont_isole].l++);

                // verifico se supera i valori massimi
                //altezza
                if(isole[cont_isole].h > h_max) {
                    h_max = isole[cont_isole].h;
                    i_h_max = i;
                }
                //larghezza
                if(isole[cont_isole].l > l_max) {
                    l_max = isole[cont_isole].l;
                    i_l_max = i;
                }
                //area
                if(isole[cont_isole].h*isole[cont_isole].l > a_max) {
                    a_max = isole[cont_isole].h*isole[cont_isole].l;
                    i_a_max = i;
                }

                // non controllo le colonne che so già essere occupate dall'isola che ho già trovato
                j += isole[cont_isole].l-1;

                cont_isole++;
            }
        }
    }

    // stampo valori massimi
    printf("Altezza massima: ");
    stampaIsola(isole,i_h_max);
    printf("Larghezza massima: ");
    stampaIsola(isole,i_l_max);
    printf("Area massima: ");
    stampaIsola(isole,i_a_max);

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
   printf("estremo=(%d,%d), altezza=%d, larghezza=%d, area=%d.\n",
          isole[i].i,isole[i].j,isole[i].h,isole[i].l,isole[i].l*isole[i].h);
}