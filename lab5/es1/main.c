#include <stdio.h>
#include <stdlib.h>

#define FILENAME "input.txt"
#define MAX_DIM 20

#define DEBUGGING
#ifdef DEBUGGING
#define DEBUG(arg ...) fprintf(stderr,arg);
#else
#define DEBUG(arg ...) {}
#endif

int massimo(int *vec, int dim);

int main() {
    int n_squadre;
    int m_giornate;

    int matrice[MAX_DIM][MAX_DIM];
    int punteggi[MAX_DIM];

    FILE *fp;

    // inizializzazione del vettore punteggi
    for(int i = 0; i < MAX_DIM; i++) {
        punteggi[i] = 0;
    }

    // apertura del file
    if((fp = fopen(FILENAME,"r")) == NULL){
        fprintf(stderr,"Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }

    // lettura del numero di righe e di colonne del file
    if(fscanf(fp,"%d %d\n",&n_squadre,&m_giornate) != 2) {
        fprintf(stderr,"Errore di formato nel file.\n");
        exit(EXIT_FAILURE);
    }
    DEBUG("-%d-%d-\n ",n_squadre,m_giornate);

    // lettura matrice da file
    for(int i = 0; i < n_squadre; i++) {
        for(int j = 0; j < m_giornate; j++) {
            if(fscanf(fp," %d",&matrice[i][j]) != 1 ||
                        (matrice[i][j] != 1 &&
                        matrice[i][j] != 3 &&
                        matrice[i][j] != 0)) {
                fprintf(stderr,"Errore di formato nel file.\n");
                exit(EXIT_FAILURE);
            }
            DEBUG("%d ",matrice[i][j]);
    }
        fgetc(fp);
        DEBUG("\n");
    }

    // somma dei conteggi e stampa del massimo
    for(int j = 0; j < m_giornate; j++) {
        for(int i = 0 ; i<  n_squadre; i++) {
            punteggi[i] += matrice[i][j];
        }
        printf("Indice della squadra al primo posto in classifica: %d.\n",massimo(punteggi,n_squadre));
    }

    fclose(fp);
    return 0;
}

// ritorna l'indice del valore massimo nel vettore vec di dimensione dim
int massimo(int *vec, int dim) {
    int massimo = 0,index;
    for(int i = 0; i < dim; i++) {
        if(vec[i] > massimo) {
            massimo = vec[i];
            index = i;
        }
    }
    return(index);
}