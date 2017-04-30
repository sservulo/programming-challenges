#include<iostream>

#define n 5

void print(int (&matrix)[n][n]);
void fill(int (&matrix)[n][n]);
void zero(int (&matrix)[n][n]);

int main(){
	int matrix[n][n] = {};

	fill(matrix);

	matrix[3][2] = 0;
	print(matrix);

	zero(matrix);
	print(matrix);
	return 0;
}

void print(int (&matrix)[n][n]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void fill(int (&matrix)[n][n]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = 1;
		}
	}
}

void zero(int (&matrix)[n][n]){
	bool rowsToZero[n] = {};
	bool columnsToZero[n] = {};

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(matrix[i][j] == 0){
				rowsToZero[i] = true;
				columnsToZero[j] = true;
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(rowsToZero[i] || columnsToZero[j]){matrix[i][j] = 0;}
		}
	}
}

