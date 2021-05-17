#include <stdio.h>


void countSort(int A[], int N) {
    int occorrenze[N],appoggio[N];

    for(int i = 0; i < N;i++) occorrenze[i] = 0;

    for(int i = 0; i < N; i++) {
        occorrenze[A[i]]++;
    }
    for(int i = 1; i < N; i++) {
        occorrenze[i] += occorrenze[i - 1];
    }


    for(int i = N-1; i>=0;i--){
        appoggio[occorrenze[A[i]] - 1] = A[i];
        occorrenze[A[i]]--;
    }
    for(int i = 0; i < N;i++) A[i] = appoggio[i];


}


int main() {
    int N = 10;
    int A[] = {0,9,8,6,5,6,7,5,3,1};
    for(int i = 0; i < N;i++) printf(" %d",A[i]);
    printf("\n");
    countSort(A,N);
    for(int i = 0; i < N;i++) printf(" %d",A[i]);
    printf("\n");

    return 0;
}
