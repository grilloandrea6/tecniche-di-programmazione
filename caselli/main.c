#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME    "pedaggi.txt"
#define MAX_TRATTE  25
#define MAXL        20

typedef struct {
    char partenza[MAXL + 1];
    char arrivo[MAXL + 1];
    float costo;
} tratta;

void trovaPercorso(tratta *, char *, char *,float*);

int main() {

    FILE *fp;
    tratta tratte[MAX_TRATTE];
    int n_tratte,esci = 0;
    char entrata[MAXL + 1],uscita[MAXL + 1];

    // apertura file
    if((fp = fopen(FILENAME, "r")) == NULL) {
        fprintf(stderr, "Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }

    // lettura dati da file
    for(n_tratte = 0; fscanf(fp,"%s %s %f",tratte[n_tratte].partenza, tratte[n_tratte].arrivo, &tratte[n_tratte].costo) == 3; n_tratte++);


    for(int i = 0; i < n_tratte; i++) {
        printf("%s %s %f\n", tratte[i].partenza, tratte[i].arrivo, tratte[i].costo);
    }

    do {
        printf("Casello di entrata ('esci' per uscire): ");
        if(scanf("%s", entrata) != 1) {
            printf("Valore non valido!\n");
            continue;
        }

        if(strcmp(entrata,"esci") == 0) esci = 1;

        printf("Casello di uscita: ");
        if(scanf("%s", uscita) != 1) {
            printf("Valore non valido!\n");
            continue;
        }

        float valori[2] = {0,0};
        trovaPercorso(tratte,entrata,uscita,valori);

        if(valori[0] == -1) {
            printf("Impossibile raggiungere la destinazione percorrendo un massimo di tre tratte.\n");
        }
        else {
            printf("Destinazione raggiunta in %.0f tratte. Spesa complessiva: %.2f€.\n",valori[0],valori[1]);
        }
    } while(!esci);
    return 0;
}


void trovaPercorso(tratta *tratte, char *ingresso, char *uscita, float ret[2]){
    //float ret[2] = {0,0}; // ret[0] = numerotratte; ret[1] = costo

    int i;
    char *new_ingresso;

    // ricerca prima tratta
    for(i = 0; strcmp(tratte[i].partenza, ingresso) != 0;i++);
    ret[1] += tratte[i].costo;
    ret[0]++;
    new_ingresso = tratte[i].arrivo;

    // se sono già arrivato
    if(strcmp(new_ingresso,uscita) == 0){
        return;
    }


    //ricerca seconda tratta
    for(i = 0; strcmp(tratte[i].partenza, new_ingresso) != 0; i++);
    ret[1] += tratte[i].costo;
    ret[0]++;
    new_ingresso = tratte[i].arrivo;

    // se sono già arrivato
    if(strcmp(new_ingresso,uscita) == 0)
        return;

    //ricerca terza tratta
    for(i = 0; strcmp(tratte[i].partenza, new_ingresso) != 0; i++);
    ret[1] += tratte[i].costo;
    ret[0]++;
    new_ingresso = tratte[i].arrivo;

    // se sono arrivato
    if(strcmp(new_ingresso,uscita) == 0)
        return;

    // non è possibile raggiungere la destinazione
    ret[0] = -1;
    return;
}