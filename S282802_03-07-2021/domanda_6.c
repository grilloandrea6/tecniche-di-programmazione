/*
 * Politecnico di Torino
 * Esame Tecniche di Programmazione
 * Appello 03/07/2001
 *
 * Andrea Grillo - S282802
 *
 * Domanda 6
 */

#include <stdio.h>

#define DIM 101

// prototipo della funzione
int areaIntersection(FILE * fp);

void main() {
	FILE *fp = fopen("domanda_6.txt", "r");
	printf("%d\n", areaIntersection(fp));
	fclose(fp);
}

int areaIntersection(FILE * fp) {
	// matrice del piano cartesiano
	int mat[DIM][DIM];

	// variabili di appoggio
	int start_i, start_j, end_i, end_j, i, j, area = 0;

	// inizializzazione della matrice
	for(i = 0; i < DIM; i++)
		for(j = 0; j < DIM; j++)
			mat[i][j] = 0;

	// lettura dei dati da file
	while(!feof(fp)) {
		fscanf(fp,"%d %d %d %d\n",&start_i,&start_j,&end_i,&end_j);

		// incremento dei valori della matrice
		// corretto da ciclo unico che incrementava solo la "diagonale"
		for(i = start_i; i < end_i; i++)
			for(j = start_j; j < end_j; j++)
				mat[i][j]++;
	}

	// conteggio del numero di elementi con valore strettamente maggiore di uno
	for(i = 0; i < DIM; i++)
		for(j = 0; j < DIM; j++)
			if(mat[i][j] > 1) area++;

	return area;
}
