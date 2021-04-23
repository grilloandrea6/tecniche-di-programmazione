#include <stdio.h>
#include <stdlib.h>

#define NR_MAX 20
#define NC_MAX 20
#define FILENAME_MAX 20


// ritorna l'indice del valore massimo del vettore V di dimensione dim
int massimo(int *V, int dim) {
    int max = V[0],
        index = 0;

    for(int i = 1; i < dim; i++) {
        if(V[i] > max) {
            index = i;
            max = V[i];
        }
    }
    return(index);
}



int main() {
    FILE * fp;
    int nr,nc,mat[NR_MAX][NC_MAX],dim,cont,max,i_max,j_max,
        somme[NR_MAX*NC_MAX];//massimo NR*NC sottomatrici se la dim è 1

    for(int i =0; i<NR_MAX*NC_MAX;i++) {
        somme[i] = 0;
    }
    char filename[FILENAME_MAX] = "input.txt"; //TODO lettura da stdin

    printf("inserisci il nome del file da cui leggere: ");

    //scanf("%s",filename);

    if((fp = fopen(filename,"r")) == NULL) {
        fprintf(stderr,"Errore nell'apertura del file");
        exit(-1);
    }

    fscanf(fp,"%d %d\n",&nr,&nc);

    printf("nr %d nc %d\n",nr,nc);

    for(int i = 0; i < nr; i++) {
        for(int j = 0; j < nc; j++) {

            if(fscanf(fp," %d",&mat[i][j]) != 1) {
                fprintf(stderr,"Errore di lettura da file.\n");
                exit(-1);
            }
            // DEBUG    printf("%d ",mat[i][j]);
        }
        // DEBUG printf("\n");
    }

    do {
        printf("Inserisci la dimensione delle sottomatrici da ricercare: ");
        if(scanf(" %d",&dim) != 1) {
            fprintf(stderr,"Valore non valido\n");
            exit(-1);
        }

        printf("Le sottomatrici quadrate di dimensione %d sono:\n",dim);
        cont = 0;
        for(int i = 0; i < nr - dim + 1; i++) {
            for(int j = 0; j < nc - dim + 1; j++) {
                // nuova sottomatrice
                for (int x = 0; x < dim; x++ ) {
                    for(int y = 0; y < dim; y++) {
                        printf("%d ",mat[i+x][j+y]);
                        somme[cont] += mat[i+x][j+y];
                    }
                    printf("\n");
                }

                cont++;
                printf("\n");
            }
        }

        printf("somme\n");
        for(int i =0; i<cont;i++) {
            printf("%d ",somme[i]);
        }

        max = massimo(somme,cont);

        printf("\n max = %d",max);
        i_max = max / nc;
        j_max = max % nc;
        printf("i_max %d, j_max %d\n",i_max,j_max);

        for (int x = 0; x < dim; x++ ) {
            for(int y = 0; y < dim; y++) {
                printf("%d ",mat[i_max+x][j_max+y]);
            }
            printf("\n");
        }


        for(int i =0; i<NR_MAX*NC_MAX;i++) {
            somme[i] = 0;
        }
    } while(dim >= 1 && dim <= ((nc>nr)?nr:nc));


    printf("Arrivederci.\n");

    return 0;
}
