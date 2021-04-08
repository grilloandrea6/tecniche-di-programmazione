/*
 * Laboratorio 4 Esercizio 2
 * Autore: Andrea Grillo
 * Data: Aprile 2021
 */
#include <stdio.h>
#include <stdlib.h>

#define maxN 30


int main() {

    int V[30],N;

    printf("Rotazione di un vettore.\nInserisci dimensione del vettore: ");

    // se il valore inserito non è un intero oppure non rientra nel range (0,maxN]
    // stampo un messaggio di errore ed esco
    if (scanf(" %d",&N) != 1 || N <=0 || N > maxN)
    {
        fprintf(stderr,"Valore non valido!\n");
        exit(-1);
    }

    for(int i = 0; i < N; i++) {
        printf("Inserisci valore all'indice %d: ",i);
        if(scanf(" %d", &V[i]) != 1) {
            fprintf(stderr,"Valore non valido!\n");
            i--;
        }

    }

    return 0;
}
