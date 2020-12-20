#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define rows 5
#define cols 5

void fillMatrix(int matrix[rows][cols]){

	int randNum;
	int r;
	int c;

	srand(time(NULL));

	for (r=0; r < rows; r++){

		for (c=0; c < cols; c++){

			randNum = (rand() %99+1);

			matrix[r][c] = randNum;
			//printf("%d\t", board[rows][columns]);

		}
		
	}
	//printf("\n");

}


void printMatrix(int matrix[rows][cols]){

	int r;
	int c;

	//fillMatrix(matrix);

	for (r=0; r < rows; r++){

		for (c=0; c < cols; c++){

			printf("%d\t", *(*(matrix + r) + c));
		}

		printf("\n");

	}

	printf("\n");

}


void transposeMatrix(int matrix[rows][cols]){

	int r;
	int c;

	//fillMatrix(matrix);

	for (r=0; r < rows; r++){

		for(c=r; c < cols; c++){

			int tmp = *(*(matrix + r) + c);
			int *x = (*(matrix + r) + c);
			int *y = (*(matrix + c) + r);

			*x = *(*(matrix + c) + r);
			*y = tmp;

		}

	}

}


void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]) {

	int r, c, i, j;
	int sum;

	for (r=0; r < rows; r++){
	
		sum = 0;

		for (c=0; c < cols; c++){

			sum += (*(*m1 + c) * (*(*(m2 + c) + r)));

			}

		*(*resultMatrix + r) = sum;

		}

	for (r=0; r < rows; r++){

		sum = 0;

		for (c=0; c < cols; c++){

			sum += (*(*(m1 + 1) + c) * (*(*(m2 + c) + r)));

		}

		*(*(resultMatrix + 1) + r) = sum;

	}

	for (i=2; i < 5; i++){

		for (j=0; j < 5; j++){

			*(*(resultMatrix + i) + j) = 0;

		}

	}

}


int main(){

	int matrix[rows][cols];

	fillMatrix(matrix); //Q1
	printMatrix(matrix); //Q2

	transposeMatrix(matrix); //Q3
	printMatrix(matrix);

	int matrix2[2][cols] = {{0,1,2,3,4}, {5,6,7,8,9}};
	int matrixResult[rows][cols];
	multiplyMatrix(matrix2, matrix, matrixResult); //Q4
	printMatrix(matrixResult);

	return 0;

}
