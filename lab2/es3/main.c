/*
 * Laboratorio 2 Esercizio 3
 * Autore: Andrea Grillo
 * Data: Marzo 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SORGENTE "sorgente.txt"
#define COMPRESSO "compresso.txt"
#define DECOMPRESSO "decompresso.txt"

bool open_files(FILE **in, const char *inname, FILE **out, const char *outname);
int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);

int main() {
    char scelta = 0;
    int ret;
    FILE *fp_in,*fp_out;

    while (scelta != 'e') {

        //print menu
        printf("\n\nCiao. Questo è un semplice programma di compressione/decompressione. Posso fare le seguenti cose:\n");
        printf(" - [a] comprimo il contenuto del file 'sorgente.txt' e lo salvo in 'compresso.txt';\n");
        printf(" - [b] decomprimo il contenuto del file 'compresso.txt' e lo salvo in 'decompresso.txt';\n");
        printf(" - [e] esci.\n");
        printf("\nEffettua la tua scelta [a/b/e]: ");

        //acquisisci scelta
        scanf(" %c",&scelta);

        switch (scelta) {
            // scelta == a -> compressione
            case 'a':
                printf("\nCompressione in corso.\n");

                // apertura file
                if(!open_files(&fp_in,SORGENTE, &fp_out, COMPRESSO)){
                    fprintf(stderr,"Errore nell'apertura dei file.\n");
                    exit(-1);
                }

                // compressione
                ret = comprimi(fp_in,fp_out);

                // chiusura files
                fclose(fp_in);
                fclose(fp_out);

                if(ret == 0)
                    fprintf(stderr,"Errore nella compressione.\n");
                else
                    printf("Compressione effettuata. Scritti %d caratteri.\n", ret);
                break;

            // scelta == b -> decompressione
            case 'b':
                printf("\nDecompressione in corso.\n");

                // apertura files
                if(!open_files(&fp_in,COMPRESSO, &fp_out, DECOMPRESSO)){
                    fprintf(stderr,"Errore nell'apertura dei file.\n");
                    exit(-1);
                }

                //decompressione
                ret = decomprimi(fp_in,fp_out);

                // chiusura files
                fclose(fp_in);
                fclose(fp_out);

                if(ret == 0)
                    fprintf(stderr,"Errore nella decompressione.\n");
                else
                    printf("Decompressione effettuata. Scritti %d caratteri.\n", ret);
                break;

            // scelta == e -> uscita
            case 'e':
                printf("\nArrivederci!\n");
                break;

            // scelta non valida, stampo errore riprendo il ciclo
            default:
                fprintf(stderr,"Errore! Comando non riconosciuto!\n");
                break;
        }
    }
    return(0);
}

/*
 * FUNZIONE COMPRIMI
 *
 * errori gestiti:
 *  - trovo un dollaro
 *  - [fin/fout] == NULL
 */
int comprimi(FILE *fin, FILE *fout){
    char carattere,old_carattere;
    int cont;
    int ret=1; //parto da uno per conteggiare l'ultima scrittura senza doverlo incrementare nuovamente

    if(fin == NULL || fout == NULL) {
        fprintf(stderr,"Errore. Puntatori a file passati alla funzione nulli.\n");
        return(0);
    }

    //leggo il primo carattere
    old_carattere = fgetc(fin);

    //lettura da file
    while ((carattere = fgetc(fin)) != EOF) {

        //controllo se ho un '$', non accettato per la compressione
        if(old_carattere == '$') {
            fprintf(stderr,"Errore! Trovato '$' nel file da comprimere, carattere non accettato.\n");
            return(0);
        }

        // se trovo duplicati
        if(old_carattere == carattere) {

            //conto quanti caratteri sono uguali
            for(cont = 0; carattere == old_carattere && carattere != EOF && cont < 9; cont++)
                carattere = fgetc(fin);

            //scrivo sul file di output
            fprintf(fout,"%c$%d",old_carattere,cont);

            //incremento il contatore dei caratteri scritti
            ret += 3;

        } else {// se il carattere non è duplicato lo scrivo nel file di output
            fprintf(fout,"%c",old_carattere);
            ret++;
        }

        old_carattere = carattere;
    }

    //scrivo l'ultimo carattere
    fprintf(fout,"%c",old_carattere);

    return(ret);
}


/*
 * FUNZIONE DECOMPRIMI
 *
 * errori gestiti
 *  - [fin/fout] == null
 *  - trova un dollaro non seguito da un numero
 */
int decomprimi(FILE *fin, FILE *fout){
    char carattere,old_carattere;
    int cont, ret=1; //parto da uno per conteggiare l'ultima scrittura senza doverlo incrementare nuovamente

    if(fin == NULL || fout == NULL) {
        fprintf(stderr,"Errore. Puntatori a file passati alla funzione nulli.\n");
        return(0);
    }

    old_carattere = fgetc(fin);

    // leggo dal file
    while ((carattere = fgetc(fin)) != EOF) {

        // se il carattere è '$' lo gestisco
        if(carattere == '$') {
            carattere = fgetc(fin);

            // errore: dollaro non seguito da numero
            if(carattere < '0' || carattere > '9') {
                fprintf(stderr, "Errore. Formato del file compresso non valido.\n");
                return(0);
            }

            // sottraendo il codice ascii di 0
            // utilizzo carattere come fosse un intero
            carattere = carattere - '0';

            for(cont = 0; cont < carattere+1; cont++) {
                fprintf(fout, "%c", old_carattere);
            }

            // aggiorno il numero di caratteri scritti utilizzando cont
            ret = ret + cont - 1;

        } else { // altrimenti stampo il carattere letto
            fprintf(fout, "%c", old_carattere);
            ret++;
        }
        old_carattere = carattere;
    }
    fprintf(fout,"%c",old_carattere);

    return(ret);
}


bool open_files(FILE **in, const char * inname, FILE **out, const char * outname){
    *in = fopen(inname,"r");
    *out = fopen(outname,"w");

    return(*in != NULL && *out != NULL);
}
