#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SORGENTE "sorgente.txt"
#define COMPRESSO "compresso.txt"
#define DECOMPRESSO "decompresso.txt"

bool open_files(FILE **in, const char * inname, FILE **out, const char * outname);
int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);

int main() {
    char scelta = 0;
    int ret;

    FILE *fp_in,*fp_out;


    while (scelta != 'e') {
        printf("\n\nCiao. Questo è un semplice programma di compressione/decompressione. Posso fare le seguenti cose:\n");
        printf(" - [a] comprimo il contenuto del file 'sorgente.txt' e lo salvo in 'compresso.txt';\n");
        printf(" - [b] decomprimo il contenuto del file 'compresso.txt' e lo salvo in 'decompresso.txt';\n");
        printf(" - [e] esci.\n");
        printf("\nEffettua la tua scelta [a/b/e]: ");


        scanf(" %c",&scelta);
        switch (scelta) {
            case 'a':
                printf("\nCompressione in corso.\n");

                if(!open_files(&fp_in,SORGENTE, &fp_out, COMPRESSO)){
                    fprintf(stderr,"Errore nell'apertura dei file.\n");
                    exit(-1);
                }
                ret = comprimi(fp_in,fp_out);
                if(ret == 0)
                    fprintf(stderr,"Errore nella compressione.\n");
                else
                    printf("Compressione effettuata. Scritti %d caratteri.\n", ret);
                break;
            case 'b':
                printf("\nDecompressione in corso.\n");

                if(!open_files(&fp_in,COMPRESSO, &fp_out, DECOMPRESSO)){
                    fprintf(stderr,"Errore nell'apertura dei file.\n");
                    exit(-1);
                }
                ret = decomprimi(fp_in,fp_out);
                if(ret == 0)
                    fprintf(stderr,"Errore nella decompressione.\n");
                else
                    printf("Decompressione effettuata. Scritti %d caratteri.\n", ret);
                break;
            case 'e':
                printf("\nArrivederci!\n");
                break;
            default:
                fprintf(stderr,"Errore! Comando non riconosciuto!\n");
        }
    }
    return(0);
}


// TODO ritornare 0 se c'è errore. quale può essere l'errore? trovo un dollaro - i file sono null
int comprimi(FILE *fin, FILE *fout){
    char carattere,old_carattere;
    int cont;
    int ret=1; //parto da uno per conteggiare l'ultima scrittura senza doverlo incrementare nuovamente

    old_carattere = fgetc(fin);

    while ((carattere = fgetc(fin)) != EOF) {

        if(old_carattere == carattere) {
            for(cont = 0; carattere == old_carattere && carattere != EOF && cont < 9; cont++)
                carattere = fgetc(fin);

            fprintf(fout,"%c$%d",old_carattere,cont);
            ret = ret + 3;
        } else{
            fprintf(fout,"%c",old_carattere);
            ret++;
        }

        old_carattere = carattere;
    }
    fprintf(fout,"%c",old_carattere);

    fclose(fin);
    fclose(fout);

    return(ret);
}

// TODO ritornare 0 se c'è errore. quale può essere l'errore? un dollaro senza numero dopo - i file sono null
int decomprimi(FILE *fin, FILE *fout){
    char carattere,old_carattere;
    int cont, ret=1; //parto da uno per conteggiare l'ultima scrittura senza doverlo incrementare nuovamente

    old_carattere = fgetc(fin);

    while ((carattere = fgetc(fin)) != EOF) {
        if(carattere == '$') {
            carattere = fgetc(fin);
            if(carattere < '0' || carattere > '9') {
                fprintf(stderr, "Errore. Formato del file compresso non valido.\n");
                return(0);
            }
            carattere = carattere - '0';

            for(cont = 0; cont < carattere+1; cont++) {
                fprintf(fout, "%c", old_carattere);
                ret++;
            }

            ret--;

        } else {
            fprintf(fout, "%c", old_carattere);
            ret++;
        }
        old_carattere = carattere;
    }
    fprintf(fout,"%c",old_carattere);

    fclose(fin);
    fclose(fout);

    return(ret);
}



bool open_files(FILE **in, const char * inname, FILE **out, const char * outname){
    *in = fopen(inname,"r");
    *out = fopen(outname,"w");

    return(*in != NULL && *out != NULL);
}
