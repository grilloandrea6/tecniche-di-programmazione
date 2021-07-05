#include <stdio.h>

/*void Merge(int A[],int B[],int l, int q, int r) {
    int i = l,j = i + q;
    int k = l;

    while(i<=l+q && j <= r) {
        if(A[i] >= A[j]) {
            B[k] = A[i];
            k++;
            i++;
        } else {
            B[k] = A[j];
            k++;
            j++;
        }
    }
    if(i == q) {
        for(i = j; i <= r; i++ && k++)  B[k] = A[i];
    } else if (j == r)  for(; i <= q; i++ && k++)  B[k] = A[i];


}*/
/*void Merge(int A[],int B[],int l, int q, int r) {
    int i,j,k;
    i = l;
    j = q+1;
    for(k=l;k<=r;k++) {
        if(i>q) {
            B[k] = A[j++];
        } else if(j > r) {
            B[k] = A[i++];
        } else if(A[i] <= A[j]) {
            B[k] = A[i++];
        } else {
            B[k] = A[j++];
        }
    }
    for(k=l; k <= r; k++){
        A[k] = B[k];
    }
}

void BottomUpMergeSort(int A[],int B[], int N) {
    int q;
    for(int m = 1; m < N; m = m+m) {
        for(int i = 0; i < N-m; i+= m+m) {
            q = i+m-1;
            Merge(A,B,i,q,N-1);
        }
    }
}
*/
void Merge(int A[], int B[], int l, int q, int r) {
printf("l %d q%d r%d\n\n",l,q,r);
    int i, j, k;
    i = l;
    j = q;
    printf("Valore di j: %d\n", j);
    for (k = l; k <= r; k++){
         if (i > q){// esaurito sottovettore sinistro
             B[k] = A[j++];
             printf("sx\n\n");
         }
         else if (j > r){// esaurito sottovettore destro
             B[k] = A[i++];
                          printf("dx\n\n");
         }
         else if (A[i] <= A[j]){
             B[k] = A[i++];
         }
         else{
             B[k] = A[j++];
         }

	}

    printf("Vettore B:\n");
    for (k = l; k <= r; k++){
        A[k] = B[k];
        printf("%d ", B[k]);

    }
    printf("%c ", '\n');

    return;
}


void BottomUpMergeSort(int A[], int B[], int N) {
    int i, q, m; // estremi

    for (m = 1; m < N; m = 2*m) {
        printf("VALORE DI M: %d\n", m);

        for (i = 0; i < N - m; i += m + m) {
            q = i + m; // punto in cui si taglia
            
            printf("CHIAMATA AL MERGE\n");
            Merge(A, B, i, q, i+m+m-1);
            printf("Valore di i: %d\n", i);
            printf(" Valore di q: %d\n", q);
            printf(" Valore di r: %d\n", i+m+m-1);
            printf("%c", '\n');
        }
        printf("%c%c", '\n', '\n');
    }
    printf("Valore finale di m: %d\n", m);
}


int main() {
    int N = 16;

    int A[] = {5,3,2,5,76,7,5,4,3,3,12,345,6,4,23,74},B[N];
    for(int i = 0; i < N; i++) printf("%d ",A[i]);
    printf("\n");
    BottomUpMergeSort(A,B,N);
    for(int i = 0; i < N; i++) printf("%d ",A[i]);
    printf("\n");

    return 0;
}
