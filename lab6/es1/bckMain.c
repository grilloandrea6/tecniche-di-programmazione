#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXL_COMANDO    15
#define MAXL            100
#define FILENAME        "log.txt"
#define MAX_RECORD      1000

typedef enum {
    c_date, c_partenza, c_capolinea, c_ritardo, c_ritardo_tot, c_fine, c_errore
} comandi;

typedef struct{
    char codice_tratta[MAXL + 1];
    char partenza[MAXL +1];
    char destinazione[MAXL + 1];
    int data_anno;
    int data_mese;
    int data_giorno;
    int partenza_ora;
    int partenza_minuto;
    int partenza_secondo;
    int arrivo_ora;
    int arrivo_minuto;
    int arrivo_secondo;
    int ritardo;
} record;

comandi leggiComando();
void strToLower(char *);
int openFile(FILE **);
int getData(FILE **, record *);
int menuParola(record *, int);

int f_date(record *dati, int num_record);
int f_partenza(record *dati, int num_record);
int f_capolinea(record *dati, int num_record);
int f_ritardo(record *dati, int num_record);
int f_ritardo_tot(record *dati, int num_record);

int main() {

    FILE * fp;
    record dati[MAX_RECORD];
    int numero_record;


    if(!openFile(&fp)) {
        fprintf(stderr,"Errore nell'apertura del file!\n");
        exit(EXIT_FAILURE);
    }

    numero_record = getData(&fp, dati);
    if(numero_record == -1) {
        fprintf(stderr,"Errore nella lettura del file!\n");
        exit(EXIT_FAILURE);
    }



    printf("Ciao! Con questo programma puoi filtrare i dati del log.\n");
    printf("Caricati in memoria %d record.\n",numero_record);
    while(menuParola(dati,numero_record));

    return 0;
}

comandi leggiComando () {
    comandi c;
    char cmd[MAXL_COMANDO];
    char tabella[c_errore][MAXL_COMANDO] = {"date","partenza","capolinea","ritardo","ritardo_tot","fine"};

    printf("Menù comandi:\n\t- date: elencare tutte le corse partite in un certo intervallo di date\n\t- partenza: elencare tutti le corse partite da una certa fermata\n\t- capolinea: elencare tutti le corse aventi una specifica destinazione \n\t- ritardo: elencare tutte le corse che hanno raggiunto la destinazione in ritardo, in un certo intervallo di date\n\t- ritardo_tot: elencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta\n\t- fine: terminare il programma\nInserisci il comando: ");

    scanf("%s",cmd);

    strToLower(cmd);

    c=c_date;

    while(c<c_errore && strcmp(cmd,tabella[c])!=0)
        c++;

    return(c);
}

void strToLower(char *str) {
    for(int i = 0; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

int openFile(FILE **fp){
    *fp = fopen(FILENAME,"r");
    return(*fp != NULL);
}

int menuParola(record *dati, int num) {
    comandi cmd = leggiComando();
    int ret;

    switch (cmd) {
        case c_date:
            ret = f_date(dati,num);
            break;
        case c_partenza:
            ret = f_partenza(dati,num);
            break;
        case c_capolinea:
            ret = f_capolinea(dati,num);
            break;
        case c_ritardo:
            ret = f_ritardo(dati,num);
            break;
        case c_ritardo_tot:
            ret = f_ritardo_tot(dati,num);
            break;

        case c_fine:
            printf("Arrivederci!\n");
            return(0);
            break;

        case c_errore:
        default:
            printf("Errore nella lettura del comando.\n");

            return(-1);
            break;
    }
    return(ret);
}

int getData(FILE **fp, record *dati) {
    int numero_record;

    if(fscanf(*fp,"%d\n",&numero_record) != 1 || numero_record > MAX_RECORD)
     return(-1);


    for(int i = 0; i < numero_record; i++) {
        if(fscanf(*fp,"%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d",
                                dati[i].codice_tratta,
                                dati[i].partenza,
                                dati[i].destinazione,
                                &dati[i].data_anno,
                                &dati[i].data_mese,
                                &dati[i].data_giorno,
                                &dati[i].partenza_ora,
                                &dati[i].partenza_minuto,
                                &dati[i].partenza_secondo,
                                &dati[i].arrivo_ora,
                                &dati[i].arrivo_minuto,
                                &dati[i].arrivo_secondo,
                                &dati[i].ritardo) != 13)    return(-1);

        /*printf("-%s-%s-%s-%d/%d/%d-%d:%d:%d-%d:%d:%d-%d-\n",
                dati[i].codice_tratta,
                dati[i].partenza,
                dati[i].destinazione,
                dati[i].data_anno,
                dati[i].data_mese,
                dati[i].data_giorno,
                dati[i].partenza_ora,
                dati[i].partenza_minuto,
                dati[i].partenza_secondo,
                dati[i].arrivo_ora,
                dati[i].arrivo_minuto,
                dati[i].arrivo_secondo,
                dati[i].ritardo);*/
    }

    return(numero_record);
}


int f_date(record *dati, int num_record){}
int f_partenza(record *dati, int num_record){}
int f_capolinea(record *dati, int num_record){}
int f_ritardo(record *dati, int num_record){}



int f_ritardo_tot(record *dati, int num_record) {
    char codice[MAXL];
    int ritardo = 0;
    printf("Inserisci il codice della tratta di cui vuoi verificare il ritardo: ");
    if(scanf(" %s",codice) != 1) return(-1);

    for(int i = 0; i < num_record; i++) {
        if(strcmp(dati[i].codice_tratta,codice) == 0) {
            ritardo += dati[i].ritardo;
        }
    }

    printf("Il ritardo totale accumulato dalla tratta di codice %s è di %d minuti.\n",codice,ritardo);
}