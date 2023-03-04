#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> lerMatriz(int l) {
    vector<vector<int>> matriz;

    for (int i = 0; i < l; i++) {
        vector<int> line;

        for (int j = 0; j < l; j++) {
            int num;
            cin >> num;
            line.push_back(num);
        }

        matriz.push_back(line);
    }

    return matriz;
};

void mostrarMatriz(vector<vector<int>> matriz) {
    int l = matriz.size();

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) cout << matriz[i][j] << "\t";
        cout << endl;
    }

    cout << endl << "-----" << endl;
};

void verifyRight(vector<vector<int>> matriz, int tam, int l, int c, int* auxl,
                 int* auxc, int* valor) {
    if (c + 1 != tam) {
        if (matriz[l][c + 1] != -1 && *valor <= matriz[l][c + 1]) {
            *valor = matriz[l][c + 1];
            *auxl = l;
            *auxc = c + 1;
        }
    }
}

void verifyRightDiagonal(vector<vector<int>> matriz, int tam, int l, int c,
                         int* auxl, int* auxc, int* valor) {
    if (l + 1 != tam && c + 1 != tam) {
        if (matriz[l + 1][c + 1] != -1 && *valor <= matriz[l + 1][c + 1]) {
            *valor = matriz[l + 1][c + 1];
            *auxl = l + 1;
            *auxc = c + 1;
        }
    }
}

void verifyBottom(vector<vector<int>> matriz, int tam, int l, int c, int* auxl,
                  int* auxc, int* valor) {
    if (l + 1 != (tam)) {
        if (matriz[l + 1][c] != -1 && *valor <= matriz[l + 1][c]) {
            *valor = matriz[l + 1][c];
            *auxl = l + 1;
            *auxc = c;
        }
    }
}

void verifyLeftDiagonal(vector<vector<int>> matriz, int tam, int l, int c,
                        int* auxl, int* auxc, int* valor) {
    if (l + 1 != tam && c - 1 >= 0) {
        if (matriz[l + 1][c - 1] != -1 && *valor <= matriz[l + 1][c - 1]) {
            *valor = matriz[l + 1][c - 1];
            *auxl = l + 1;
            *auxc = c - 1;
        }
    }
}

void verifyLeft(vector<vector<int>> matriz, int tam, int l, int c, int* auxl,
                int* auxc, int* valor) {
    if (c - 1 >= 0 && l != tam - 1) {
        if (matriz[l][c - 1] != -1 && *valor <= matriz[l][c - 1]) {
            *valor = matriz[l][c - 1];
            *auxl = l;
            *auxc = c - 1;
        }
    }
}

int main() {
    int n;  // Número de matrizes
    cin >> n;

    int tam;  // Tamanho da matriz, l por l
    cin >> tam;

    while (n--) {
        vector<vector<int>> matriz = lerMatriz(tam);

        int l = 0;  // linha inicial
        int c = 0;  // coluna inicial

        int auxl = 0;
        int auxc = 0;

        while (l != (tam - 1) || c != (tam - 1)) {
            int valor = 0;

            cout << matriz[l][c] << " ";

            verifyLeft(matriz, tam, l, c, &auxl, &auxc, &valor);
            verifyLeftDiagonal(matriz, tam, l, c, &auxl, &auxc, &valor);
            verifyBottom(matriz, tam, l, c, &auxl, &auxc, &valor);
            verifyRight(matriz, tam, l, c, &auxl, &auxc, &valor);
            verifyRightDiagonal(matriz, tam, l, c, &auxl, &auxc, &valor);

            matriz[l][c] = -1;

            l = auxl;
            c = auxc;
        }

        // Mostrando ultima posicao
        cout << matriz[l][c] << endl;

        mostrarMatriz(matriz);
    }

    return 0;
}