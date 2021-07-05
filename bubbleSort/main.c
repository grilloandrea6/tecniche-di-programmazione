#include <stdio.h>

int main() {
    int vect[13] = {3,6,5,1,7,21,8,4,12,0,9,8,4};
    int x,i,j;
    for (i = 0; i < 13; i++) {
        for(j = 0; j < 13 - i; j++) {
            if(vect[j] > vect[j+1]) {
                x = vect[j + 1];
                vect[j+1] = vect[j];
                vect[j] = x;
            }
        }
    }

    for(i = 0; i < 13; i++) {
        printf("%d ",vect[i]);
    }
    return 0;
}
