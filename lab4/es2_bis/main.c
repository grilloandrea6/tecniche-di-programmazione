/*
 * Laboratorio 4 Esercizio 2
 * Autore: Andrea Grillo
 * Data: Aprile 2021
 *
 * versione 2:
 *  -ia
 *  - utilizza un vettore in più di appoggio
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define maxN 30

void ruota(int v[maxN], int N, int P, int dir);

int main() {

    int V[30],N,P,dir;

    printf("Rotazione di un vettore.\nInserisci dimensione del vettore: ");

    // se il valore inserito non è un intero oppure non rientra nel range (0,maxN]
    // stampo un messaggio di errore ed esco
    if (scanf(" %d",&N) != 1 || N <=0 || N > maxN)
    {
        fprintf(stderr,"Valore non valido!\n");
        exit(EXIT_FAILURE);
    }

    // lettura valori del vettore da tastiera
    for(int i = 0; i < N; i++) {
        printf("Inserisci valore all'indice %d: ",i);

        // se il numero di valori letti è diverso da uno
        // stampo un messaggio di errore ed esco
        if(scanf(" %d", &V[i]) != 1) {
            fprintf(stderr,"Valore non valido!\n");
            exit(-1);
        }

    }

    do {
        printf("Inserisci il numero di posizioni di cui spostare l'array (0 per uscire): ");

        // se il valore inserito non è un intero oppure non rientra nel range [0,N]
        // stampo un messaggio di errore ed esco
        if(scanf(" %d",&P) != 1 || P < 0 || P > N) {
            fprintf(stderr,"Valore non valido!");
            exit(EXIT_FAILURE);
        }

        // se l'utente chiede di uscire
        // non gli chiedo la direzione di spostamento
        if(P == 0) break;


        printf("Inserisci la direzione di spostamento [-1/1]: ");

        // se il valore inserito non è un intero oppure non è uguale a +1/-1
        // stampo un messaggio di errore ed esco
        if(scanf(" %d",&dir) != 1 || abs(dir) != 1) {
            fprintf(stderr,"Valore non valido!");
            exit(EXIT_FAILURE);
        }

        ruota(V, N, P, dir);

        // stampo il vettore
        for(int i = 0; i<N;i++) {
            printf("%d ",V[i]);
        }
        printf("\n");

    } while (P != 0);   // condizione inutile in quanto c'è già il break
    // ma per sicurezza evito di usare while(true)

    return 0;
}


void ruota(int v[maxN], int N, int P, int dir) {
    int new_vect[maxN];
    int j;

    for(int i = 0; i < N; i ++)
    {
        j = (i+ (P * dir) + N) % N;

        // aggiungendo N prima di fare il modulo non è più necessario
        //j = (j>=0)?j:j+N;

        // DEBUG printf("copying i %d in j %d \n",i,j);
        new_vect[j] = v[i];
    }

    memcpy(v,new_vect,N*sizeof(int));
    /* copia del vettore senza usare memcpy
     * for(int i = 0; i < N; i++)
     *   v[i]=new_vect[i];*/
}