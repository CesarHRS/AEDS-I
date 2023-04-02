#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#define dbg(x) cout << #x << " = " << x << endl

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

void saveMatrixOnFile(vector<vector<string>> matrix, int matrixIndex, int lines,
                      int columns) {
    string filename = getMatrixFilename(matrixIndex);

    fstream matrixFile;
    matrixFile.open(filename, ios::out);

    for (int j = 0; j < lines; j++) {
        for (int k = 0; k < columns; k++) {
            matrixFile << matrix[j][k] << " ";
        }

        matrixFile << endl;
    }

    matrixFile.close();
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
void show(vector<vector<string>> matrix, int lines, int columns) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }

    cout << endl << "-----" << endl;
};
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

void teleport(vector<vector<string>>* matrix, int* matrixIndex,
              int newMatrixIndex, int lines, int columns) {
    saveMatrixOnFile(*matrix, newMatrixIndex, lines, columns);

    *matrixIndex = newMatrixIndex;

    *matrix = loadMatrixFromFile(*matrixIndex, lines, columns);
}

pair<int, int> randomValidMove(vector<vector<string>>* matrix, int line,
                               int column, int lines, int columns,
                               int* matrixIndex, int numberOfMatrixs) {
    int move = randomInteger(1, 8);
}

pair<int, int> randomMove(vector<vector<string>>* matrix, int line, int column,
                          int lines, int columns, int* matrixIndex,
                          int numberOfMatrixs) {
    // TODO

    // 1 - Diagonal superior esquerda
    // Matriz anterior

    // 2 - Cima
    // Matriz anterior

    // 3 - Diagonal superior direita
    // Matriz anterior

    // 4 - Esquerda
    // Matriz anterior

    // 5 - Direita
    // Proxima matriz

    // 6 - Diagonal inferior esquerda
    // Proxima matriz

    // 7 - Baixo
    // Proxima matriz

    // 8 - Diagonal inferior direita
    // Proxima matriz

    pair<int, int> newPosition = {line, column};

    bool isSamePosition =
        (newPosition.first == line) && (newPosition.second == column);

    bool isPositionBlock =
        (*matrix)[newPosition.first][newPosition.second] == "#";

    do {
        int move = randomInteger(1, 8);

        switch (move) {
            case 1:

                if (line - 1 < 0 || column - 1 < 0) {
                    // Limite da matriz
                    if (*matrixIndex - 1 > 0) {
                        teleport(matrix, matrixIndex, *matrixIndex - 1, lines,
                                 columns);

                        int l = randomInteger(0, lines - 1);
                        int c = randomInteger(0, columns - 1);

                        while ((*matrix)[l][c] != "#") {
                            l = randomInteger(0, lines - 1);
                            c = randomInteger(0, columns - 1);
                        }

                        newPosition = {l, c};
                    }

                } else {
                    newPosition = {line - 1, column - 1};
                }

                break;
            case 2:

                if (line - 1 < 0) {
                    // Limite da matriz
                    if (*matrixIndex - 1 > 0) {
                        newPosition = {0, 0};
                        teleport(matrix, matrixIndex, *matrixIndex - 1, lines,
                                 columns);
                    }
                } else {
                    newPosition = {line - 1, column};
                }

                break;
            case 3:

                if (line - 1 < 0 || column + 1 > (columns - 1)) {
                    // Limite da matriz
                    if (*matrixIndex - 1 > 0) {
                        newPosition = {0, 0};
                        teleport(matrix, matrixIndex, *matrixIndex - 1, lines,
                                 columns);
                    }
                } else {
                    newPosition = {line - 1, column + 1};
                }

                break;
            case 4:

                if (column - 1 < 0) {
                    // Limite da matriz
                    if (*matrixIndex - 1 > 0) {
                        newPosition = {0, 0};
                        teleport(matrix, matrixIndex, *matrixIndex - 1, lines,
                                 columns);
                    }
                } else {
                    newPosition = {line, column - 1};
                }

                break;
            case 5:

                if (column + 1 > (columns - 1)) {
                    // Limite da matriz

                    if (*matrixIndex + 1 <= numberOfMatrixs) {
                        newPosition = {0, 0};
                        teleport(matrix, matrixIndex, *matrixIndex + 1, lines,
                                 columns);
                    }

                } else {
                    newPosition = {line, column + 1};
                }

                break;
            case 6:

                if (line + 1 > (lines - 1) || column - 1 < 0) {
                    // Limite da matriz

                    if (*matrixIndex + 1 <= numberOfMatrixs) {
                        newPosition = {0, 0};
                        teleport(matrix, matrixIndex, *matrixIndex + 1, lines,
                                 columns);
                    }

                } else {
                    newPosition = {line + 1, column - 1};
                }

                break;
            case 7:
                if (line + 1 > (lines - 1)) {
                    // Limite da matriz

                    if (*matrixIndex + 1 <= numberOfMatrixs) {
                        newPosition = {0, 0};
                        teleport(matrix, matrixIndex, *matrixIndex + 1, lines,
                                 columns);
                    }

                } else {
                    newPosition = {line + 1, column};
                }

                break;
            case 8:
                if (line + 1 > (lines - 1) || column + 1 > (columns - 1)) {
                    // Limite da matriz

                    if (*matrixIndex + 1 <= numberOfMatrixs) {
                        newPosition = {0, 0};
                        teleport(matrix, matrixIndex, *matrixIndex + 1, lines,
                                 columns);
                    }

                } else {
                    newPosition = {line + 1, column + 1};
                }

                break;
        }

        isSamePosition =
            (newPosition.first == line) && (newPosition.second == column);

        isPositionBlock =
            (*matrix)[newPosition.first][newPosition.second] == "#";

    } while (isSamePosition || isPositionBlock);

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
    int matrixIndex = 1;

    int life = 10;
    int bag = 0;

    int line = startPosition.first;
    int column = startPosition.second;

    vector<vector<string>> matrix;
    matrix = loadMatrixFromFile(matrixIndex, lines, columns);

    while (life > 0) {
        pair<int, int> nextMove =
            randomMove(&matrix, line, column, lines, columns, &matrixIndex,
                       numberOfMatrixs);

        line = nextMove.first;
        column = nextMove.second;

        cout << matrixIndex << " " << line << column << " " << endl;

        // if (line == startPosition.first && column == startPosition.second &&
        //            bag == 0) {
        //     dbg("EU QUERTO CAFE");
        //     break;
        // }

        string position = matrix[line][column];

        if (position == "*") {
            // Perigo
            life--;
        } else {
            // Como a função randomMove não retorna uma posição que seja
            // parede
            // (#) caso a posição não seja um perigo (*) ela vai ser um item
            // (1-10).

            int item = stoi(position);

            if (item != 0) {
                matrix[line][column] = to_string(item - 1);
                bag++;

                if (bag == 4) {
                    bag = 0;
                    life++;
                }
            }
        }
    }

    return 0;
}