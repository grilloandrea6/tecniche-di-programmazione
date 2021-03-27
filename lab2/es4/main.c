#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define INFILE "in.txt"
#define OUTFILE "out.txt"


int main() {
    FILE *fin,*fout;
    char carattere,old_carattere;
    int k=0,h,ret=1;
    bool lastWasNotAlpha = true;

    fin = fopen(INFILE,"r");
    fout = fopen(OUTFILE,"w");

    while ((carattere = fgetc(fin)) != EOF) {

        if (isalnum(carattere) != 0) {
            if (isdigit(carattere) != 0) {
                printf("debug: valore numerico\n");

                carattere = (carattere -'0' + (k % 10)) % 10+'0';
                k = (k + 1) % 10;
                fprintf(fout, "%c", carattere);
                ret++;
                lastWasNotAlpha = true;

            } else {
                printf("debug: valore alfabetico\n");

                // l'ultimo carattere non era alfanumerico, non codifico
                if (lastWasNotAlpha) {
                    lastWasNotAlpha = false;
                    printf("lastwasnotalpha\n");
                    fprintf(fout, "%c", carattere);
                } else //codifico
                {
                    //carattere = (carattere -'0' + (k % 10)) % 10+'0';

                    if(isupper(old_carattere) == 0) {
                        h = (old_carattere - 'a');
                        if (h > 'a' + 26) h = h - 26;
                    } else {
                        h = (old_carattere - 'A') ;
                        if (h > 'A' + 26) h = h - 26;
                    }
                    char codificato=carattere + h;
                            printf("old_char %c %d char %c %d h %d\n",old_carattere,old_carattere,carattere,carattere-'a',h);
                    fprintf(fout, "%c",codificato);// (toupper(carattere) + (toupper(old_carattere) - 'A') % 26 - 'A')%26 + 'A');
                }
                ret++;
                old_carattere = carattere;
            }
        } else{
            lastWasNotAlpha=true;
            printf("debug: valore non alfanumerico\n");
            fprintf(fout,"%c",carattere);
        }
    }

    fclose(fin);
    fclose(fout);

    return(ret);


}
