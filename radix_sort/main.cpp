#include <stdio.h>
#include <cmath>


void countSort(int A[], int N,int n_cifra) {
    int D[N],peso=1;
    int occorrenze[N],appoggio[N];

    for(int i = 0; i < n_cifra; i++) peso*=10;

    for(int i = 0; i < N;i++) occorrenze[i] = 0;

    for(int i = 0; i < N; i++) D[i] = (A[i]/peso)%10;

    for(int i = 0; i < N; i++) printf(" %d", D[i]);
    printf("lala\n");



    for(int i = 0; i < N; i++) {
        occorrenze[D[i]]++;
    }

    for(int i = 1; i < N; i++) {
        occorrenze[i] += occorrenze[i - 1];
    }

    for(int i = N-1; i>=0;i--){
        appoggio[occorrenze[D[i]] - 1] = A[i];
        occorrenze[D[i]]--;
    }
    for(int i = 0; i < N;i++) A[i] = appoggio[i];


}


void CountingSort(int A[],int N, int step) {
    int B[N],C[10],D[N];

    int i, l = 0, r = N-1, weight = 1;

    for(i=0; i < step; i++) weight *= 10;

    for(i=0; i < 10; i ++) C[i] =0;

    for(i = l; i<=r; i++) D[i] = (A[i]/weight)%10;

    for(i=l; i <= r; i++) C[D[i]]++;

    for(i = 1; i < 10; i++)
        C[i] += C[i-1];

    for(i = r; i>= l ; i--) {
        B[C[D[i]] - 1] = A[i];
        C[D[i]]--;
    }

    for(i = l; i <= r; i++) A[i] = B[i];
}
int getMax(int A[],int N) {
    int res = A[0];
    for(int i = 1; i < N; i++)
        if (A[i] > res)
            res = A[i];

    return res;
}
void radixSort(int A[],int N){
    int max = getMax(A,N),d=1;
    while(max/10 > 0){
        d++;
        max/=10;
    }
    for(int i = 0; i < d; i++)
        countSort(A,N,i);
}



void radixSortB(int A[],int N){
    int max = getMax(A,N),d=1;
    while(max/10 > 0){
        d++;
        max/=10;
    }
    for(int i = 0; i < d; i++)
        CountingSort(A,N,i);
}
int main() {
    int A[] = {170,45,2375,90,802,24,2,66,12,42};
    radixSort(A,10);
    for(int i = 0; i < 10; i++) printf(" %d", A[i]);
    printf("\n");
    int B[] = {170,45,2375,90,802,24,2,66,12,42};

    radixSortB(B,10);
    for(int i = 0; i < 10; i++) printf(" %d", B[i]);
    printf("\n");

    return 0;
}

