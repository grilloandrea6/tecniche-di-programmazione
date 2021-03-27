#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define INFILE "sorgente.txt"
#define OUTFILE "compresso.txt"


bool open_files(FILE ** ,FILE **);


    
int main(){
FILE * fp_in,*fp_out;
    if(!open_files(&fp_in, &fp_out)){
        fprintf(stderr,"Errore nell'apertura dei file.\n ");
        exit(-1);
    }
}


bool open_files(FILE **in ,FILE **out){
    *in = fopen(INFILE,"r");

    //*out = fopen(OUTFILE,"w");
	if (*in == NULL)printf("oila");
	
    return((*in != NULL));
}
