/*
 * Laboratorio 3 Esercizio 1
 * Autore: Andrea Grillo
 * Data: Marzo 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define IN "input.txt"
#define OUT "testo.txt"

int main() {
    FILE *fp_in, *fp_out;
    char carattere;
    int cont = 0;
    bool lastWasPunct = false,
            nextMaiuscolo = false;

    fp_in = fopen(IN,"r");
    fp_out = fopen(OUT, "w");

    if(fp_out == NULL || fp_in == NULL) {
        fprintf(stderr, "Errore nell'apertura dei file!\n");
        exit(-1);
    }

    // input da file
    while( (carattere = fgetc(fp_in)) != EOF) {

        // se il carattere precedente era punteggiatura
        if(lastWasPunct) {

            // se il carattere non è uno spazio ne un 'a capo' aggiunto uno spazio
            if(carattere != ' ' && carattere != '\n') {
                fprintf(fp_out, " ");
                cont++;
            }

            lastWasPunct = false;
        }

        // se il carattere precedente era [./!/?] e il carattere attuale è una lettera lo rendo maiuscolo
        if(nextMaiuscolo && isalpha(carattere)) {
            carattere = toupper(carattere);
            nextMaiuscolo = false;
        }

        // se è una cifra lo codifico con *
        if(isdigit(carattere) != 0){
           carattere = '*';
        }
        // altrimenti se è un segno di punteggiatura lo salvo nel flag
        else if(ispunct(carattere) != 0) {
            lastWasPunct = true;

            // segno se è un segno di punteggiatura che deve essere seguito da un carattere maiuscolo
            if(carattere == '.' ||
                carattere == '!' ||
                carattere == '?')
                nextMaiuscolo = true;
        }

        if(carattere == '\n'){
            if(cont < 25)
                for(int i = cont; i < 25; i++) fprintf(fp_out," ");
            fprintf(fp_out,"| c:%d\n",cont+1);
            cont = 0;

            //non eseguo la stampa del carattere
            continue;
        }

        //incremento il contatore e verifico che non sia maggiore di 25
        if(cont >=  24) {
            fprintf(fp_out,"%c| c:%d\n",carattere,cont+1);
            cont = 0;

            // non eseguo la stampa del carattere
            continue;
        }

        fprintf(fp_out,"%c",carattere);
        cont++;
    }
}
