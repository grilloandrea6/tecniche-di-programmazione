/*
 * Laboratorio 3 Esercizio 3
 * Autore: Andrea Grillo
 * Data: Marzo 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILENAME "input.txt"

bool scarta(int, int, int);

int main() {
    FILE *fp = fopen(FILENAME,"r");

    if(fp == NULL) {
        fprintf(stderr,"Errore nell'apertura del file!\n");
        exit(-1);
    }

    int numero, old_1, old_2,
        max, min,
        cont_scartati = 0;

    // assumo siano presenti almeno due numeri nel file
    fscanf(fp," %d",&old_2);
    fscanf(fp," %d",&old_1);

    // inizializzo le variabili max e min a partire dai primi due numeri
    if(old_2 > old_1) {
        max = old_2;
        min = old_1;
    } else {
        max = old_1;
        min = old_2;
    }

    while(!feof(fp)) {
        fscanf(fp," %d",&numero);

        if(!scarta(old_2,old_1,numero)) { // se il numero non viene scartato

            // aggiornamento del massimo e del minimo
            max = (max > numero) ? max : numero;
            min = (min < numero) ? min : numero;

            // aggiornamento variabilili old_1 e old_2
            old_2 = old_1;
            old_1 = numero;
        } else  cont_scartati++; // altrimenti incremento il contatore dei numeri scartati
    }

    printf("Numero massimo: %d\n",max);
    printf("Numero minimo: %d\n",min);
    printf("Numeri scartati: %d\n",cont_scartati);

    fclose(fp);

    return 0;
}


bool scarta(int a, int b, int c) {
    if (c == (a+b)) return false;
    if (c == (a-b)) return false;
    if (c == (a*b)) return false;
    if (b != 0 && c == (a/b)) return false;

    return true;
}
