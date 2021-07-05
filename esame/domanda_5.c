/*
 * Esame Tecniche di Programmazione
 * Appello 03/07/2001
 *
 * Andrea Grillo - S282802
 *
 * Domanda 5
 * Versione originale con correzioni.
 * Presente anche versione ottimizzata con approccio on-line.
 */

#include <stdio.h>

#define DIM 6

// Prototipi delle funzioni
float max(float *somme, int dim);
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


// Funzione di appoggio che ricerca il massimo in un vettore di float di dimensione dim.
float max(float *somme, int dim){
	float max = somme[0];
	for (int i = 1; i < dim; i++)
		if(somme[i] > max) max = somme[i];

	return max;
}


float matrMaxDiag(float M[DIM][DIM], int n) {
	float somme[(2*DIM)-1]; // ci sono sempre 2DIM-1 diagonali
	for(int i = 0; i < (2*DIM)-1; i++) somme[i] = 0; // inizializzazione del vettore

	// variabili di appoggio
	int i,j,k = 0, count = 0;

	// diagonali inferiori e diagonale principale
	int start_i = n - 1;	// corretto DIM con n
	int start_j = 0;
	while(start_i >= 0) {
		i = start_i;
		j = start_j;

		// somma degli elementi sulla diagonale
		// corretto "i++ && j++" con "i++, j++" - corretto DIM con n
		for(; i < n && j < n; i++, j++) {
			somme[k] += M[i][j];
			count++;
		}

		// calcolo e salvataggio della media
		somme[k] /= count;

		count = 0;
		start_i--;
		k++;
	}

	//diagonali superiori
	start_i = 0;
	start_j = 1;
	while(start_j < n) {	// corretto DIM con n
		i = start_i;
		j = start_j;

		// somma degli elementi sulla diagonale
		// corretto "i++ && j++" con "i++, j++" - corretto DIM con n
		for(; i < n && j < n; i++, j++) {			
			somme[k] += M[i][j];
			count++;
		}

		// calcolo e salvataggio della media
		somme[k] /= count;

		count = 0;
		start_j++;
		k++;
	}

	// ritorno il massimo delle medie salvate nel vettore, utilizzando la funzione max
	return max(somme,(2*n)-1);
}
