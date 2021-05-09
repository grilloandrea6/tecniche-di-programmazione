/*
 * Laboratorio 4 Esercizio 1
 * Autore: Andrea Grillo
 * Data: Aprile 2021
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input.txt"
#define MAX 30

int massimo(int *, int);
void sottoSequenze(int *, int);

int main() {
    FILE *fp;
    int vec[MAX], i = 0,dim;

    // apertura file
    if((fp = fopen(FILENAME,"r")) == NULL) {
        fprintf(stderr,"Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }

    // lettura da file
    while(feof(fp) == 0) {
        fscanf(fp, "%d",&vec[i]);
        i++;

        if(i >= MAX) {
            fprintf(stderr,"Errore, troppi numeri!\n");
            exit(EXIT_FAILURE);
        }
    }

    // chiusura file
    fclose(fp);

    // nuova dimensione del vettore
    dim = i;

    /*// stampo vettore originale
    printf("Vettore originale:\n");
    for(i=0;i<dim;i++)
        printf("%d ",vec[i]);
    printf("\n\n");
    */

    sottoSequenze(vec,dim);

    return 0;
}

// ritorna il valore massimo del vettore V di dimensione dim
int massimo(int *V, int dim) {
    int max = V[0];
    for(int i = 1; i < dim; i++) {
        if(V[i] > max) max = V[i];
    }
    return(max);
}

void sottoSequenze(int *V, int N){

    int starts[N], dims[N], // suppongo al massimo N sottovettori - TODO ottimizzare, saranno di meno
        cont = 0,iterator=0,max,i;

    // ricerco sottovettori
    // scrivo nel vettore starts gli indici di inizio dei sottovettori
    // e nel vettore dims la dimensione di ogni sottovettore

    // il primo sottovettore inizia all'inizio del vettore
    starts[0] = 0;

    for(i = 0; i < N; i++) {

        // se incontro uno zero chiudo il sottovettore e salvo i dati
        if(V[i] == 0)
        {
            starts[iterator+1] = i+1;
            dims[iterator] = cont;
            iterator++;

            // parto da -1 perché viene incrementato anche in questa iterazione
            cont = -1;

        } else if(i == N - 1) { // se sono alla fine del vettore chiudo comunque il sottovettore
            dims[iterator] = cont+1;
            iterator++;
        }

        cont++;
    }

    //iterator indica adesso il numero di sottovettori trovati

    //DEBUG faccio una stampa dei vettori starts e dims
    /*for(i = 0; i < iterator; i++) {
        printf("start[%d] %d dim[%d] %d\n",i,starts[i],i,dims[i]);
    }*/

    // trovo la dimensione massima
    max = massimo(dims,iterator);
    // DEBUG printf("dimensione massima %d\n", max);

    // stampo i sottovettori che hanno dimensione == max
    for(i = 0; i < iterator; i++) {

        // DEBUG a quale indice dei vettori starts e dims si trova il sottovettore stampato
        // printf("i: %d\n",i);

        if(dims[i] == max) {
            for(int j = starts[i]; j < (max + starts[i]); j++) {
                printf("%d ",V[j]);
            }

            // vado a capo dopo ogni sottovettore stampato
            printf("\n");
        }
    }
}
