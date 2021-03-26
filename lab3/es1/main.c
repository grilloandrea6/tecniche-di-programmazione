#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define IN "input.txt"
#define OUT "testo.txt"

int main() {
    FILE *fp_in,*fp_out;
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

    while((carattere = fgetc(fp_in))!= EOF) {
        if(lastWasPunct) {
            if(carattere != ' ' && carattere != '\n')
                printf(" ");
            lastWasPunct = false;
        }

        if(nextMaiuscolo && isalpha(carattere)) {
            carattere = toupper(carattere);
            nextMaiuscolo = false;
        }

        if(isdigit(carattere) != 0){
            printf("*");
            continue;
        }

        else if(ispunct(carattere) != 0) {
            lastWasPunct = true;
            if(carattere == '.' ||
                carattere == '!' ||
                carattere == '?')
                nextMaiuscolo = true;
        }

        /*if(carattere == '\n'){
            if(cont < 25)
                for(int i = cont; i < 25; i++) printf(" ");
            printf("| c:%d\n",cont);
            continue;
            cont = 0;
        }

        if(cont++ >= 25) {
            cont = 0;
            printf("| c:%d\n",cont);
            continue;
        }*/

        printf("%c",carattere);
    }
}
