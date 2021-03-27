/*
 * Laboratorio 1 Esercizio 6
 * Autore: Andrea Grillo
 * Data: Marzo 2021
 */

#include <stdio.h>
#include <stdlib.h>

#define INFILE  "operazioni.txt"
#define OUTFILE "risultati.txt"

float calcola(char operazione, float op1, float op2);
int open_files(FILE **,FILE **);

int main() {
    float op1 = 0,
            op2 = 0,
            res = 0;
    char operazione;
    FILE *fp_in,*fp_out;

    if(!open_files(&fp_in, &fp_out)){
        fprintf(stderr,"Errore nell'apertura dei file.\n");
        exit(-1);
    }

    while(!feof(fp_in)){
        fscanf(fp_in,"%f %c %f",&op1,&operazione,&op2);

        res = calcola(operazione,op1,op2);

        //DEBUG printf("operazione: %f %c %f = %f\n",op1,operazione,op2, res);

        fprintf(fp_out,"%f\n",res);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}

float calcola(char operazione, float op1, float op2)
{
    float res;
    switch (operazione) {
        case '+':
            res = op1 + op2;
            break;
        case '-':
            res = op1 - op2;
            break;
        case '*':
            res = op1 * op2;
            break;
        case '/':
            if (op2 != 0) {
                res = op1 / op2;
            } else {
                fprintf(stderr, "Impossibile eseguire una divisione per zero!\n");
                exit (-1);
            }
            break;
    }
    return(res);
}

int open_files(FILE ** in,FILE ** out) {
    *in = fopen(INFILE,"r");
    *out = fopen(OUTFILE,"w");

    return(*in != NULL && *out != NULL);
}
