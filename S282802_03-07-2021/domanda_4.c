/*
 * Politecnico di Torino
 * Esame Tecniche di Programmazione
 * Appello 03/07/2001
 *
 * Andrea Grillo - S282802
 *
 * Domanda 4
 */

#include <stdio.h>
#include <string.h>

// prototipo della funzione
int strFindSimilar(char str1[], char str2[]);


int main() {
	char *str1 = "FifthOfNovember";
	char *str2 = "September";
	printf("%d\n",strFindSimilar(str1,str2));
}

int strFindSimilar(char str1[], char str2[]) {
	int count = 0,
		minDim = strlen(str2)/2;	//numero minimo di caratteri uguali

	// itero su str1
	for(int i = 0; i + strlen(str2) <= strlen(str1); i++) { // eliminata condizione superflua

		// itero su str2
		for( int j = i; j < i + strlen(str2); j++) { // corretta condizione di uscita dal ciclo
			// conto il numero di caratteri uguali
			if(str1[j] == str2[j-i]) count++;
		}

		// se il numero di caratteri uguali è maggiore
		// del minimo ritorno il valore di i, che è
		// l'indice di inizio della sottostrigna simile
		if(count > minDim) return i;

		count = 0;
	}
	return -1;
}
