#include <iostream>
#include<math.h>
#include <time.h>
using namespace std;

#define MAX 4
#define MAX_THREAD 4

int matA[MAX][MAX];
int matB[MAX][MAX];
int matC[MAX][MAX];
int step_i = 0;

void* multi(void* arg) {
    int i = step_i++;
    for (int j = 0; j < MAX; j++) {
        for (int k = 0; k < MAX; k++) {
            matC[j][k] = matA[j][k] * matB[j][k];
        }
    }
}

void* resta(void* arg) {
    int i = step_i++;
    for (int j = 0; j < MAX; j++) {
        for (int k = 0; k < MAX; k++) {
            matC[j][k] = matA[j][k] + matB[j][k];
        }
    }
}

void* suma(void* arg) {
    int i = step_i++;
    for (int j = 0; j < MAX; j++) {
        for (int k = 0; k < MAX; k++) {
            matC[j][k] = matA[j][k] - matB[j][k];
        }
    }
}

int main()
{
    bool repetir = true;
    int opcion;
    unsigned t0, t1;
    do {

        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Datos  " << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion " << endl;
        cout << "4. Suma" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    matA[i][j] = rand() % 5;
                    matB[i][j] = rand() % 5;
                }
            }

            cout << endl << "Matrix A" << endl;
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    cout << matA[i][j] << " ";
                }
                cout << endl;
            }

            cout << endl << "Matrix B" << endl;
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++)
                    cout << matB[i][j] << " ";
                cout << endl;
            }

            pthread_t threads[MAX_THREAD];
            break;
        case 2:
            {t0 = clock();
            for (int i = 0; i < MAX_THREAD; i++) {
                int* p;
                pthread_create(&threads[i], NULL, resta, (void*)(p));
            }
            t1 = clock();
            double time = (double(t1 - t0) / CLOCKS_PER_SEC);
            for (int i = 0; i < MAX_THREAD; i++)
                pthread_join(threads[i], NULL);

            cout << endl
                << "Resta de A y B" << endl;
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++)
                    cout << matC[i][j] << " ";
                cout << endl;
            }
            cout << "Execution Time: " << time << endl;}
            break;
        case 3:
            {t0 = clock();
            for (int i = 0; i < MAX_THREAD; i++) {
                int* p;
                pthread_create(&threads[i], NULL, multi, (void*)(p));
            }
            t1 = clock();
            double time = (double(t1 - t0) / CLOCKS_PER_SEC);
            for (int i = 0; i < MAX_THREAD; i++)
                pthread_join(threads[i], NULL);

            cout << endl
                << "Multiplicacion de A y B" << endl;
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++)
                    cout << matC[i][j] << " ";
                cout << endl;
            }
            cout << "Execution Time: " << time << endl;}
            break;
        case 4:
            {t0 = clock();
            for (int i = 0; i < MAX_THREAD; i++) {
                int* p;
                pthread_create(&threads[i], NULL, suma, (void*)(p));
            }
            t1 = clock();
            double time = (double(t1 - t0) / CLOCKS_PER_SEC);
            for (int i = 0; i < MAX_THREAD; i++)
                pthread_join(threads[i], NULL);

            cout << endl
                << "suma de A y B" << endl;
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++)
                    cout << matC[i][j] << " ";
                cout << endl;
            }
            cout << "Execution Time: " << time << endl;}
            break;
        }
    } while (repetir);
}
