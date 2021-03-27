#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFILE "sorgente.txt"
#define OUTFILE "compresso.txt"

bool open_files(FILE ** ,FILE **);


int main() {
    char carattere,old_carattere;
    int cont;
    FILE *fp_in,*fp_out;

    if(!open_files(&fp_in, &fp_out)){
        fprintf(stderr,"Errore nell'apertura dei file.\n");
        exit(-1);
    }

    old_carattere = fgetc(fp_in);
    
    while ((carattere = fgetc(fp_in)) != EOF) {
		
		if(old_carattere == carattere) {
		    for(cont = 0; carattere == old_carattere && carattere != EOF && cont < 9; cont++)
		        carattere = fgetc(fp_in);

		    fprintf(fp_out,"%c$%d",old_carattere,cont);
		} else
		    fprintf(fp_out,"%c",old_carattere);

		old_carattere = carattere;
    }
    fprintf(fp_out,"%c",old_carattere);
    
    fclose(fp_in);
    fclose(fp_out);
}



bool open_files(FILE **in ,FILE **out){
    *in = fopen(INFILE,"r");
    *out = fopen(OUTFILE,"w");

    return(*in != NULL && *out != NULL);
}

