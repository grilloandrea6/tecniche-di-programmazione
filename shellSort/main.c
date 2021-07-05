#include <stdio.h>

int main() {
    int vect[13] = {3,6,5,1,7,21,8,4,12,0,9,8,4};
    int i;
    int start = 0;
    int h = 4;
    for(;h > 0; h--) {
        for (i = 1; i < ; i++) {
            x = vect[i];
            for(j = i - 1; j >= 0 && x < vect[j]; j--) {
                vect[j+1] = vect[j];
            }
            vect[j+1] = x;
        }
    }
    printf("Hello, World!\n");
    return 0;
}
