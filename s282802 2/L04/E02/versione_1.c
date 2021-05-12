/*
 * Laboratorio 4 Esercizio 2
 * Autore: Andrea Grillo
 * Data: Aprile 2021
 *
 * versione 1:
 *  - iterazioni sull'array non ottimizzate
 *  - non ha bisogno di altri vettori in più di appoggio
 */

#include <stdio.h>
#include <stdlib.h>

#define maxN 30

void ruota(int v[maxN], int N, int P, int dir);
void ruotaSingolo(int v[maxN], int N, int dir);

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
    for(int i = 0; i < P; i++)
        ruotaSingolo(v,N,dir);
}

// effettuo un singolo spostamento
void ruotaSingolo(int v[maxN], int N, int dir) {
    int temp;

    // sposto avanti
    if(dir == 1) {
        temp = v[N-1];

        for(int i = N; i > 0; i--) {
            v[i] = v[i-1];
        }

        v[0] = temp;

    } else { // sposto indietro

        temp = v[0];

        for(int i = 0; i < N-1; i++) {
            v[i] = v[i+1];
        }

        v[N-1] = temp;
    }
}