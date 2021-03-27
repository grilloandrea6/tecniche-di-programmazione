/*
 * Laboratorio 1 Esercizio 5
 * Autore: Andrea Grillo
 * Data: Marzo 2021
 */

#include <stdio.h>
#include <stdlib.h>

int get_input_data(char *operazione, float *op1, float *op2);
float calcola(char operazione, float op1, float op2);

int main() {
    float op1 = 0,
            op2 = 0,
            res = 0;
    char operazione;

    if(get_input_data(&operazione,&op1,&op2) != 1) {
        fprintf(stderr,"Errore nell'input dei dati.\n");
        exit(-1);
    }

    res = calcola(operazione,op1,op2);

    printf("Il risultato è %f",res);
    return 0;
}

int get_input_data(char *operazione, float *op1, float *op2) {

    //input operazione
    printf("Calcolatrice: inserisci l'operazione da eseguire [+,-,*,/]: ");
    *operazione = getchar();

    //controllo operazione
    if (*operazione != '+' && *operazione != '-' && *operazione != '*' && *operazione != '/')
    {
        fprintf(stderr, "Operazione non riconosciuta!\n");
        return(-1);
    }

    //input operando 1
    printf("Inserisci il primo operando: ");
    if(scanf("%f",op1) != 1)
    {
        fprintf(stderr,"Non è un numero!\n");
        return(-1);
    }

    //input operando 2
    printf("Inserisci il secondo operando: ");
    if(scanf("%f",op2) != 1)
    {
        fprintf(stderr,"Non è un numero!\n");
        return(-1);
    }

    return(1);
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
