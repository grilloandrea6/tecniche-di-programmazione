#include <stdio.h>

int main() {
    int vect[13] = {3,6,5,1,7,21,8,4,12,0,9,8,4};
    int x,i,j;
    
    for (i = 1; i < 13; i++) {
        x = vect[i];
        for(j = i - 1; j >= 0 && x < vect[j]; j--) {
            vect[j+1] = vect[j];
        }
        vect[j+1] = x;
        for(int k = 0; k < 13; k++) {
        	printf("%d ",vect[k]);
    	}
    	printf("\n");
    	
    }
        for(i = 0; i < 13; i++) {
        printf("%d ",vect[i]);
    }
    
    return 0;
}

/*
3,6,5,1,7,21,8,4,12,0,9,8,4
3 6 5 1 7 21 8 4 12 0 9 8 4
3 5 6 1 7 21 8 4 12 0 9 8 4
1 3 5 6 7 21 8 4 12 0 9 8 4
1 3 5 6 7 21 8 4 12 0 9 8 4
1 3 5 6 7 21 8 4 12 0 9 8 4
1 3 5 6 7 21 8 4 12 0 9 8 4
1 3 5 6 7 8 21 4 12 0 9 8 4
1 3 5 4 6 7 8 21 12 0 9 8 4
1 3 5 4 6 7 8 12 21 0 9 8 4
0 1 3 5 4 6 7 8 12 21 9 8 4
0 1 3 5 4 6 7 8 9 12 21 8 4
0 1 3 5 4 6 7 8 8 9 12 21 4
0 1 3 5 4 4 6 7 8 8 9 12 21
*/
