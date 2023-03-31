#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void readLinesAndColumnFromFile(ifstream* file, int* lines, int* columns) {
    *file >> *lines;
    *file >> *columns;
}

void readNumberOfMatrixsFromFile(ifstream* file, int* numberOfMatrixs) {
    *file >> *numberOfMatrixs;
}

string getMatrixFilename(int index) {
    string filename = "";
    filename += to_string(index);
    filename += ".txt";

    return filename;
}

void saveAllMatrixOnSeparateFiles(ifstream* file, int numberOfMatrixs,
                                  int lines, int columns) {
    for (int i = 0; i < numberOfMatrixs; i++) {
        fstream matrixFile;

        string filename = getMatrixFilename(i + 1);
        matrixFile.open(filename, ios::out);

        for (int j = 0; j < lines; j++) {
            for (int k = 0; k < columns; k++) {
                string s;
                *file >> s;
                matrixFile << s << " ";
            }

            matrixFile << endl;
        }

        matrixFile.close();
    }
}

int randomInteger(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

vector<vector<string>> loadMatrixFromFile(int matrixIndex, int lines,
                                          int columns) {
    ifstream file;

    string filename = getMatrixFilename(matrixIndex);
    file.open(filename);

    vector<vector<string>> matrix;

    for (int i = 0; i < lines; i++) {
        vector<string> line;

        for (int j = 0; j < columns; j++) {
            string s;
            file >> s;

            line.push_back(s);
        }

        matrix.push_back(line);
    }

    file.close();

    return matrix;
}

pair<int, int> randomMove(vector<vector<string>>* matrix, int line, int column,
                          int lines, int columns) {
    // TODO

    // 1 - Diagonal superior esquerda
    // 2 - Cima
    // 3 - Diagonal superior direita
    // 4 - Esquerda
    // 5 - Direita
    // 6 - Diagonal inferior esquerda
    // 7 - Baixo
    // 8 - Diagonal inferior direita

    int move = randomInteger(1, 8);

    pair<int, int> newPosition;

    do {
        switch (move) {
            case 1:

                if (line - 1 < 0 || column - 1 < 0) {
                    // limite da matriz
                    newPosition = {0, 0};
                } else {
                    newPosition = {line - 1, column - 1};
                }

                break;
            case 2:

                if (line - 1 < 0) {
                    // Limite da matriz
                    newPosition = {0, 0};
                } else {
                    newPosition = {line - 1, column};
                }

                break;
            case 3:

                if (line - 1 < 0 || column + 1 > (columns - 1)) {
                    // Limite da matriz
                    newPosition = {0, 0};
                } else {
                    newPosition = {line - 1, column + 1};
                }

                break;
            case 4:

                if (column - 1 < 0) {
                    // Limite da matriz
                    newPosition = {0, 0};
                } else {
                    newPosition = {line, column - 1};
                }

                break;
            case 5:

                if (column + 1 > (columns - 1)) {
                    // Limite da matriz
                    newPosition = {0, 0};
                } else {
                    newPosition = {line, column + 1};
                }

                break;
            case 6:

                if (line + 1 > (lines - 1) || column - 1 < 0) {
                    // Limite da matriz
                    newPosition = {0, 0};
                } else {
                    return {line + 1, column - 1};
                }

                break;
            case 7:
                if (line + 1 > (lines - 1)) {
                    // Limite da matriz
                    newPosition = {0, 0};
                } else {
                    return {line + 1, column};
                }

                break;
            case 8:
                if (line + 1 > (lines - 1) || column + 1 > (columns - 1)) {
                    // Limite da matriz
                    newPosition = {0, 0};
                } else {
                    return {line + 1, column + 1};
                }

                break;
        }

    } while ((*matrix)[newPosition.first][newPosition.second] != "#");

    return newPosition;
}

int main() {
    ifstream file;
    file.open("matrizes.txt", ios::in);

    int lines, columns;
    readLinesAndColumnFromFile(&file, &lines, &columns);

    int numberOfMatrixs;
    readNumberOfMatrixsFromFile(&file, &numberOfMatrixs);

    saveAllMatrixOnSeparateFiles(&file, numberOfMatrixs, lines, columns);

    file.close();

    // Play

    pair<int, int> startPosition = {0, 0};
    int initialMatrix = 1;

    int life = 10;
    int bag = 0;

    int line = startPosition.first;
    int column = startPosition.second;

    vector<vector<string>> matrix;
    matrix = loadMatrixFromFile(initialMatrix, lines, columns);

    while (life >= 10) {

        cout << line << column << " ";

        pair<int, int> nextMove =
            randomMove(&matrix, line, column, lines, columns);

        line = nextMove.first;
        columns = nextMove.second;

        string position = matrix[line][column];

        if (position == "*") {
            // Perigo

            life--;
        } else {
            // Como a função randomMove não retorna uma posição que seja parede
            // (#) caso a posição não seja um perigo (*) ela vai ser um item
            // (1-10).

            int item = stoi(position);

            if (item != 0) {
                matrix[line][column] = item - 1;
                bag++;

                if (bag == 4) {
                    bag = 0;
                    life++;
                }
            }
        }

        life --;
    }

    return 0;
}