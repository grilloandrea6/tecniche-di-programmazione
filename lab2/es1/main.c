/*
 * Laboratorio 2 Esercizio 1
 * Autore: Andrea Grillo
 * Data: Marzo 2021
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1,n2,resto,temp;

    printf("Questo programma calcola il M.C.D. utilizzando la formula di Eulero.\nInserisci il primo numero: ");
    scanf("%d",&n1);
    printf("Inserisci il secondo numero: ");
    scanf("%d",&n2);

    if( n1 < 0 || n2 < 0) {
        fprintf(stderr,"Errore! I numeri devono essere positivi!\n");
        exit(-1);
    }

    if( n1 < n2 )
    {
        temp = n2;
        n2 = n1;
        n1 = temp;
    }

    do {
        resto = n1 % n2;
        n1 = n2;
        n2 = resto;
    } while (resto != 0);


    printf("\nIl massimo comune divisore è %d",n1);


    return 0;
}
