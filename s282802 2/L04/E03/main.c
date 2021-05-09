/*
 * Laboratorio 4 Esercizio 3
 * Autore: Andrea Grillo
 * Data: Aprile 2021
 */

#include <stdio.h>
#include <stdlib.h>

#define NR_MAX 20
#define NC_MAX 20

// presente nella libreria stdio
// scommentare se crea problemi
//#define FILENAME_MAX 20

int massimo(int *V, int dim);

int main() {
    FILE * fp;
    int nr,nc,mat[NR_MAX][NC_MAX],dim,cont,max,i_max,j_max,
        somme[NR_MAX*NC_MAX];//massimo NR*NC sottomatrici se la dim è 1

    char filename[FILENAME_MAX];// = "input.txt";

    // lettura nome del file
    printf("inserisci il nome del file da cui leggere: ");
    if(scanf("%s",filename) != 1) {
        fprintf(stderr,"Errore nell'inserimento del nome del file.\n");
        exit(EXIT_FAILURE);
    }

    // apertura del file
    if((fp = fopen(filename,"r")) == NULL) {
        fprintf(stderr,"Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }

    // lettura numero di righe e di colonne
    fscanf(fp,"%d %d\n",&nr,&nc);
    // DEBUG printf("nr %d nc %d\n",nr,nc);

    // lettura matrice
    for(int i = 0; i < nr; i++) {
        for(int j = 0; j < nc; j++) {

            if(fscanf(fp," %d",&mat[i][j]) != 1) {
                fprintf(stderr,"Errore di lettura da file.\n");
                exit(EXIT_FAILURE);
            }
            // DEBUG    printf("%d ",mat[i][j]);
        }
        // DEBUG printf("\n");
    }

    // chiusura file
    fclose(fp);

    do {
        printf("Inserisci la dimensione delle sottomatrici da ricercare: ");
        if(scanf(" %d",&dim) != 1 || dim > ((nc>nr)?nr:nc) ) {
            fprintf(stderr,"Valore non valido\n");
            exit(EXIT_FAILURE);
        }

        printf("Le sottomatrici quadrate di dimensione %d sono:\n",dim);
        cont = 0;
        for(int i = 0; i < nr - dim + 1; i++) {
            for(int j = 0; j < nc - dim + 1; j++) {

                // nuova sottomatrice
                somme[cont] = 0;
                for (int x = 0; x < dim; x++ ) {
                    for(int y = 0; y < dim; y++) {
                        printf("%d ",mat[i+x][j+y]);
                        somme[cont] += mat[i+x][j+y];
                    }
                    printf("\n");
                }

                cont++;
                printf("\n");
            }
        }

        //DEBUG
        /*printf("somme\n");
        for(int i =0; i<cont;i++) {
            printf("%d ",somme[i]);
        }*/

        max = massimo(somme,cont);
        //DEBUG printf("\n max = %d",max);

        // dall'indice del massimo nel vettore delle somme
        // ricavo le coordinate del primo elemento della sottomatrice
        i_max = max / (nc - dim + 1);
        j_max = max % (nc - dim + 1);
        //DEBUG printf("i_max %d, j_max %d\n",i_max,j_max);

        // stampo sottomatrice con somma massima
        printf("Sottomatrice con somma degli elementi massima:\n");
        for (int x = 0; x < dim; x++ ) {
            for(int y = 0; y < dim; y++) {
                printf("%d ",mat[i_max+x][j_max+y]);
            }
            printf("\n");
        }

    } while(dim >= 1 && dim <= ((nc>nr)?nr:nc));

    printf("Arrivederci.\n");

    return 0;
}

// ritorna l'indice del valore massimo del vettore V di dimensione dim
int massimo(int *V, int dim) {
    int max = V[0],
            index = 0;

    for(int i = 1; i < dim; i++) {
        if(V[i] > max) {
            index = i;
            max = V[i];
        }
    }
    return(index);
}
