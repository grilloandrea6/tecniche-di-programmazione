#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define FILENAME "sort.txt"
#define MAX_N       100

int leggiRiga(int V[], FILE **fp);
void selectionSort(int vect[],int N);
int insertionSort(int V[], int N);
void shellSort(int vect[],int N);

int main() {
    FILE *fp;
    int V[MAX_N],N,V_appoggio[MAX_N];

    if((fp = fopen(FILENAME,"r")) == NULL) {
        fprintf(stderr,"Errore apertura file.\n");
        exit(EXIT_FAILURE);
    }

    int n_seq;
    fscanf(fp,"%d\n",&n_seq);

    for(int i = 0; i < n_seq; i++) {
        N = leggiRiga(V,&fp);
        printf("Ordino la seguente sequenza di lunghezza %d: ",N);
        for(int i = 0; i < N; i++)
            printf("%d ",V[i]);
        printf("\n");

        printf("SelectionSort\n");
        memcpy(V_appoggio,V,N*sizeof(int));
        selectionSort(V_appoggio,N);
        printf("Vettore Ordinato: ");
        for(int i = 0; i < N; i++)
            printf("%d ",V_appoggio[i]);
        printf("\n\n\n");

        printf("InsertionSort\n");
        memcpy(V_appoggio,V,N*sizeof(int));
        insertionSort(V_appoggio,N);
        printf("Vettore Ordinato: ");
        for(int i = 0; i < N; i++)
            printf("%d ",V_appoggio[i]);
        printf("\n\n\n");

        printf("ShellSort\n");
        memcpy(V_appoggio,V,N*sizeof(int));
        shellSort(V_appoggio,N);
        printf("Vettore Ordinato: ");
        for(int i = 0; i < N; i++)
            printf("%d ",V_appoggio[i]);
        printf("\n\n\n\n\n");
    }


    return 0;
}


int leggiRiga(int V[], FILE **fp){
    int N;
    fscanf(*fp,"%d ",&N);

    for(int i = 0; i < N; i++)
        fscanf(*fp,"%d ",&V[i]);

    return N;
}

void selectionSort(int vect[],int N) {
    int min,temp;

    int ext_count = 0, int_count = 0, scambio_count = 0;
    for(int i = 0; i < N; i++) {
        printf("Iterazione del ciclo esterno %d.\n", ext_count + 1);
        ext_count++;

        min = i;
        for(int j = i; j < N; j++) {
            int_count++;
            if (vect[j] < vect[min])
                min = j;
        }

        if(min != i) {
            scambio_count++;
            temp = vect[i];
            vect[i] = vect[min];
            vect[min] = temp;
        }

        printf("Numero iterazioni interne: %d\n", int_count);
        int_count = 0;
    }
    printf("Fine algoritmo.\nNumero di scambi: %d\nNumero di iterazioni del ciclo esterno: %d\n",scambio_count,ext_count);
}

int insertionSort(int V[], int N) {
    int x,i,j;
    int ext_count = 0, int_count = 0, scambio_count = 0;

    for (i = 1; i < N; i++) {
        printf("Iterazione del ciclo esterno %d.\n", ext_count + 1);
        ext_count++;

        x = V[i];
        for(j = i - 1; j >= 0 && x < V[j]; j--) {
            V[j+1] = V[j];
            scambio_count++;
            int_count++;
        }
        V[j+1] = x;
        scambio_count++;

        printf("Numero iterazioni interne: %d\n", int_count);
        int_count = 0;
    }
    printf("Fine algoritmo.\nNumero di scambi: %d\nNumero di iterazioni del ciclo esterno: %d\n",scambio_count,ext_count);
}

void shellSort(int vect[],int N) {
    int h,x,j;
    int ext_count = 0, int_count = 0, scambio_count = 0, h_count = 0;

    for(h = 3;h > 0; h-=2) {
        printf("Iterazione dell'algoritmo con h = %d\n",h);
        h_count++;
        for (int i = 1;i < N; i++) {
            printf("Iterazione del ciclo esterno %d.\n", ext_count + 1);
            ext_count++;
            x = vect[i];
            for(j = i - 1;j >= 0 &&x<vect[j];j--) {
                int_count++;
                vect[j+1] = vect[j];
                scambio_count++;
            }
            printf("Numero iterazioni interne: %d\n", int_count);
            int_count = 0;
            vect[j+1] =x;
            scambio_count++;
        }

    }
    printf("Fine algoritmo.\nNumero di scambi: %d\nNumero di iterazioni del ciclo esterno: %d\nNumero di h utilizzati: %d \n",scambio_count,ext_count, h_count);
}
