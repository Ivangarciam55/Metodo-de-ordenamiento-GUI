#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void iSort();
clock_t t0, t1;


int main() {
    t0 = clock();
    iSort();
    t1 = clock();
    double time = (static_cast<double>(t1 - t0) / CLOCKS_PER_SEC);
    cout << endl << "Tiempo de ejecucion: " << time << endl;
    return 0;
}

void iSort() {
    int tam;
    int contador = 1;
    cout << "Ingrese el tamano del arreglo" << endl;
    cin >> tam;
    //int num[tam];

    vector<int> num(tam);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 50);

    cout << "Desordenado" << endl;

    for (int i = 0; i < tam; ++i) {
        num[i] = dis(gen);
    }
    for (int i = 0; i < tam; ++i) {
        cout << num[i] << " ";
    }

    for (int j = 1; j < tam; j++) {
        int key = num[j];
        int i = j - 1;
        while (i >= 0 && num[i] > key) {
            num[i + 1] = num[i];
            i = i - 1;
            num[i + 1] = key;
        }
    }


    cout << endl << "Ordenado" << endl;
    for (int i = 0; i < tam; i++) {
        cout << num[i] << " ";
    }
}