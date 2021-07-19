/*
 * Politecnico di Torino
 * Esame Tecniche di Programmazione
 * Appello 03/07/2001
 *
 * Andrea Grillo - S282802
 *
 * Domanda 5
 * Versione ottimizzata con approccio on-line.
 */

#include <stdio.h>

#define DIM 6

// Prototipo della funzione
float matrMaxDiag(float M[DIM][DIM], int n);

void main() {
	float mat[][DIM] = {{1.0,2.0,3.0,4.0,5.0,0.0},
			    {2.0,2.0,2.0,2.0,-2.0,0.0},
			    {1.1,2.2,3.3,-4.4,5.5,0.0},
			    {2.2,2.2,-3.2,4.2,4.2,0.0},
			    {1.8,-2.3,3.1,4.9,5.0,0.0},
			    {0.0,0.0,0.0,0.0,0.0,0.0}};

	printf("Max diag average: %.1f\n",matrMaxDiag(mat,5));
}


float matrMaxDiag(float M[DIM][DIM], int n) {

	// inizializzo con l'elemento della prima diagonale inferiore
	float max = M[n-1][0];

	float somma = 0;

	int i, j, count = 0;

	// diagonali inferiori e diagonale principale
	int start_i = n - 2;	// corretto DIM con n
	int start_j = 0;
	while(start_i >= 0) {
		i = start_i;
		j = start_j;

		// calcolo la somma degli elementi sulla diagonale
		// corretto "i++ && j++" con "i++, j++" - corretto DIM con n
		for(; i < n && j < n; i++, j++) {
			somma += M[i][j];
			count++;
		}

		// calcolo la media e confronto con il massimo trovato finora
		somma /= count;
		if (somma > max) max = somma;

		// azzero le variabili
		count = 0;
		somma = 0;

		// sposto il punto di inizio per la prossima diagonale
		start_i--;
	}

	//diagonali superiori
	start_i = 0;
	start_j = 1;
	while(start_j < n) {	// corretto DIM con n
		i = start_i;
		j = start_j;

		// calcolo la somma degli elementi sulla diagonale
		// corretto "i++ && j++" con "i++, j++" - corretto DIM con n
		for(; i < n && j < n; i++, j++) {
			somma += M[i][j];
			count++;
		}

		// calcolo la media e confronto con il massimo trovato finora
		somma /= count;
		if (somma > max) max = somma;

		// azzero le variabili
		count = 0;
		somma = 0;

		// sposto il punto di inizio per la prossima diagonale
		start_j++;
	}

	//ritorno il massimo trovato
	return max;
}
