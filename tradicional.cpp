#include <iostream>
#include<ctime>
#include <stdlib.h>

using namespace std;
int** matrizA, ** matrizB;
void datos(int**& matriz, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			*(*(matriz + i) + j) = rand() % 5;;
		}
	}
}
void mostrar(int**& matriz, int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(matriz + i) + j) << " ";
		}
		cout << endl;
	}
}

void deleteM(int**& matriz, int m) {
	for (int i = 0; i < m; i++) {
		delete[] matriz[i];
	}
	delete[] matriz;
}

void resta(int** matrizA, int** matrizB, int m) {
	int** matrizC;
	matrizC = new int* [m];
	for (int i = 0; i < m; i++) {
		matrizC[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			*(*(matrizC + i) + j) = *(*(matrizA + i) + j) - *(*(matrizB + i) + j);
		}
	}
	mostrar(matrizC, m);
	deleteM(matrizC, m);
}

void multiplicacion(int** matrizA, int** matrizB, int m) {
	int** matrizC;
	matrizC = new int* [m];
	for (int i = 0; i < m; i++) {
		matrizC[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			*(*(matrizC + i) + j) = *(*(matrizA + i) + j) * *(*(matrizB + i) + j);
		}
	}
	mostrar(matrizC, m);
	deleteM(matrizC, m);
}

void suma(int** matrizA, int** matrizB, int m) {
	int** matrizC;
	matrizC = new int* [m];
	for (int i = 0; i < m; i++) {
		matrizC[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			*(*(matrizC + i) + j) = *(*(matrizA + i) + j) + *(*(matrizB + i) + j);
		}
	}
	mostrar(matrizC, m);
	deleteM(matrizC, m);
}

void tradicional(int const m) {

	matrizA = new int* [m];
	for (int i = 0; i < m; i++) {
		matrizA[i] = new int[m];
	}
	datos(matrizA, m);
	mostrar(matrizA, m);

	cout << "**************************" << endl;
	matrizB = new int* [m];
	for (int i = 0; i < m; i++) {
		matrizB[i] = new int[m];
	}
	datos(matrizB, m);
	mostrar(matrizB, m);

}

int main() {
	int m,opcion;
	bool repetir = true;
	unsigned t0, t1;
	cout << "tamaño: ";
	cin >> m ;
	do {

		cout << "\n\nMenu de Opciones" << endl;
		cout << "1. Datos tradicional " << endl;
		cout << "2. Resta tradicional" << endl;
		cout << "3. Multiplicacion tradicional" << endl;
		cout << "4. Suma tradicional" << endl;

		cout << "\nIngrese una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			
			tradicional(m);
			break;
		case 2:
			{t0 = clock();
			resta(matrizA, matrizB, m);
			t1 = clock();
			double time = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << "Execution Time: " << time << endl; }
			break;
		case 3:
			{t0 = clock();
			multiplicacion(matrizA, matrizB, m);
			t1 = clock();
			double time = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << "Execution Time: " << time << endl; }
			break;
		case 4:
			{t0 = clock();
			suma(matrizA, matrizB, m);
			t1 = clock();
			double time = (double(t1 - t0) / CLOCKS_PER_SEC);
			cout << "Execution Time: " << time << endl; }
			break;
		}

	} while (repetir);

}
