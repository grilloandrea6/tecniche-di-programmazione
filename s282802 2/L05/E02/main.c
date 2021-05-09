/*
 * Laboratorio 5 Esercizio 2
 * Autore: Andrea Grillo
 * Data: Aprile 2021
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SORGENTE        "sorgente.txt"
#define DIZIONARIO      "dizionario.txt"
#define RICODIFICATO    "ricodificato.txt"

#define LINE_LEN        200

//#define DEBUGGING
#ifdef DEBUGGING
#define DEBUG(arg ...) fprintf(stderr,arg);
#else
#define DEBUG(arg ...) {}
#endif

typedef struct voce_diz {
    char codice[LINE_LEN];
    char parola[LINE_LEN];
} voce_diz;

int openFiles(FILE **sorg,FILE **diz, FILE **ricod);
void translateString(char * str, voce_diz *diz, int n_voci, FILE **fout);

int main() {
    FILE *sorg,*diz,*ricod;
    int n_voci;
    voce_diz dizionario[30];
    char line[LINE_LEN];

    if(!openFiles(&sorg,&diz,&ricod)) {
        fprintf(stderr,"Errore nell'apertura dei file.\n");
        exit(-1);
    }
    DEBUG("file aperti\n");

    // lettura del numero di voci presenti nel dizionario
    fscanf(diz," %d\n",&n_voci);
    DEBUG("%d\n",n_voci);

    // caricamento dati nel vettore di struct
    for(int i = 0; i < n_voci; i++) {
        fscanf(diz,"%s %s\n",&dizionario[i].codice,&dizionario[i].parola);
        DEBUG("%s _ %s\n",dizionario[i].codice,dizionario[i].parola);
    }

    // lettura da file
    while(fgets(line,LINE_LEN,sorg) != NULL) {
        DEBUG("-%s-",line);

        translateString(line,dizionario,n_voci,&ricod);
    }

    //chiusura file
    fclose(sorg);
    fclose(diz);
    fclose(ricod);

    return 0;
}

/*
 * Funzione che traduce ricorsivamente la stringa
 */
void translateString(char *str, voce_diz *diz, int n_voci, FILE **fout) {
    DEBUG("\ntranslating %s - lenght %d\n",str,strlen(str));

    // se la mia stringa ha dimensione 1 è sicuramente '\n',
    // inutile ricercare parole da codificare
    // - controllo superfluo ma diminuisce il tempo di esecuzione
    if(strlen(str) == 1) {
        DEBUG("stampo a capo e ritorno\n");
        fprintf(*fout,"\n");
        return;
    }

    char *pos,*minimo = NULL;
    int indice_diz = 0;

    // ricerco la prima occorrenza di una parola nel dizionario nella stringa
    for(int i = 0; i < n_voci; i++) {
        pos = strstr(str,diz[i].parola);
        if (pos !=NULL && (minimo == NULL || pos < minimo)) {
            minimo = pos;
            indice_diz = i;
        }
    }

    if(minimo == NULL) {
        fprintf(*fout, "%s", str);
        return;
    } else {
        DEBUG("\n -found %s\n\n",diz[indice_diz].parola);

        // stampo la parte di stringa prima della parola da codificare
        int j = 0;
        while (minimo != &str[j]) {
            fprintf(*fout, "%c", str[j]);
            DEBUG("%c", str[j]);
            j++;
        }

        //stampo ricodifica
        fprintf(*fout, "%s", diz[indice_diz].codice);
        DEBUG("%s", diz[indice_diz].codice);

        //richiamo ricorsivamente la funzione, partendo dalla fine della parola appena ricodificata
        minimo += strlen(diz[indice_diz].parola);
        translateString(minimo, diz, n_voci, fout);
    }
}

int openFiles(FILE **sorg,FILE **diz, FILE **ricod) {
    *sorg = fopen(SORGENTE,"r");
    *diz = fopen(DIZIONARIO,"r");
    *ricod = fopen(RICODIFICATO,"w");
    return(*sorg != NULL && *diz != NULL && *ricod != NULL);
}
