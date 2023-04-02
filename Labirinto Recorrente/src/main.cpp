#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <random>
#include <set>
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

void saveAllMatrixOnSeparateFiles(
    ifstream* file, vector<vector<pair<int, int>>>* validPositions,
    int numberOfMatrixs, int lines, int columns) {
    for (int i = 0; i < numberOfMatrixs; i++) {
        fstream matrixFile;

        string filename = getMatrixFilename(i + 1);
        matrixFile.open(filename, ios::out);

        for (int j = 0; j < lines; j++) {
            for (int k = 0; k < columns; k++) {
                string s;
                *file >> s;
                matrixFile << s << " ";

                if (s != "#") {
                    (*validPositions)[i].push_back({j, k});
                }
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

void changeMatrix(vector<vector<string>>* matrix, int* matrixIndex,
                  int newMatrixIndex, int lines, int columns) {
    saveMatrixOnFile(*matrix, newMatrixIndex, lines, columns);

    *matrixIndex = newMatrixIndex;

    *matrix = loadMatrixFromFile(*matrixIndex, lines, columns);
}

pair<int, int> teleportBack(int* matrixIndex, vector<vector<string>>* matrix,
                            int lines, int columns,
                            vector<vector<pair<int, int>>>* validPositions,
                            int numberOfMatrixs) {
    // Check
    // if
    // is
    // possible
    // back

    if (*matrixIndex - 1 > 0) {
        changeMatrix(matrix, matrixIndex, *matrixIndex - 1, lines, columns);

        int index =
            randomInteger(0, (*validPositions)[*matrixIndex - 1].size() - 1);

        return (*validPositions)[*matrixIndex - 1][index];
    } else {
        // Case is not possible back, try go to last matrix

        changeMatrix(matrix, matrixIndex, numberOfMatrixs, lines, columns);

        int index =
            randomInteger(0, (*validPositions)[*matrixIndex - 1].size() - 1);

        return (*validPositions)[*matrixIndex - 1][index];
    }
}

pair<int, int> teleportNext(int* matrixIndex, vector<vector<string>>* matrix,
                            int lines, int columns,
                            vector<vector<pair<int, int>>>* validPositions,
                            int numberOfMatrixs) {
    // Check if is possible go to next matrix
    if (*matrixIndex + 1 <= numberOfMatrixs) {
        changeMatrix(matrix, matrixIndex, *matrixIndex + 1, lines, columns);

        int index =
            randomInteger(0, (*validPositions)[*matrixIndex - 1].size() - 1);

        return (*validPositions)[*matrixIndex - 1][index];
    } else {
        // Case is not possible back, try go to first matrix

        changeMatrix(matrix, matrixIndex, 1, lines, columns);

        int index = randomInteger(0, (*validPositions)[0].size() - 1);

        return (*validPositions)[0][index];
    }
}

pair<int, int> randomMove(vector<vector<string>>* matrix, int line, int column,
                          int lines, int columns, int* matrixIndex,
                          int numberOfMatrixs,
                          vector<vector<pair<int, int>>>* validPositions) {
    // TODO

    // 1 -
    // Diagonal
    // superior
    // esquerda
    // Matriz
    // anterior

    // 2 -
    // Cima
    // Matriz
    // anterior

    // 3 -
    // Diagonal
    // superior
    // direita
    // Matriz
    // anterior

    // 4 -
    // Esquerda
    // Matriz
    // anterior

    // 5 -
    // Direita
    // Proxima
    // matriz

    // 6 -
    // Diagonal
    // inferior
    // esquerda
    // Proxima
    // matriz

    // 7 -
    // Baixo
    // Proxima
    // matriz

    // 8 -
    // Diagonal
    // inferior
    // direita
    // Proxima
    // matriz

    pair<int, int> newPosition = {line, column};
    int auxIndex = *matrixIndex;

    bool isSamePosition = (newPosition.first == line) &&
                          (newPosition.second == column) &&
                          (auxIndex == *matrixIndex);

    bool isPositionBlock =
        (*matrix)[newPosition.first][newPosition.second] == "#";

    do {
        int move = randomInteger(1, 8);

        switch (move) {
            case 1:

                if (line - 1 < 0 || column - 1 < 0) {
                    newPosition =
                        teleportBack(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line - 1, column - 1};
                }

                break;
            case 2:

                if (line - 1 < 0) {
                    newPosition =
                        teleportBack(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line - 1, column};
                }

                break;
            case 3:

                if (line - 1 < 0 || column + 1 > (columns - 1)) {
                    newPosition =
                        teleportBack(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line - 1, column + 1};
                }

                break;
            case 4:

                if (column - 1 < 0) {
                    newPosition =
                        teleportBack(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line, column - 1};
                }

                break;
            case 5:

                if (column + 1 > (columns - 1)) {
                    newPosition =
                        teleportNext(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line, column + 1};
                }

                break;
            case 6:

                if (line + 1 > (lines - 1) || column - 1 < 0) {
                    newPosition =
                        teleportNext(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line + 1, column - 1};
                }

                break;
            case 7:
                if (line + 1 > (lines - 1)) {
                    newPosition =
                        teleportNext(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line + 1, column};
                }

                break;
            case 8:
                if (line + 1 > (lines - 1) || column + 1 > (columns - 1)) {
                    newPosition =
                        teleportNext(matrixIndex, matrix, lines, columns,
                                     validPositions, numberOfMatrixs);
                } else {
                    newPosition = {line + 1, column + 1};
                }

                break;
        }

        isSamePosition = (newPosition.first == line) &&
                         (newPosition.second == column) &&
                         (auxIndex == *matrixIndex);

        isPositionBlock =
            (*matrix)[newPosition.first][newPosition.second] == "#";

    } while (isSamePosition || isPositionBlock);

    return newPosition;
}

bool verifyStartPosition(pair<int, int> startPosition,
                         vector<vector<string>>* matrix, int lines,
                         int columns) {
    int line = startPosition.first;
    int column = startPosition.second;

    if ((*matrix)[line][column] == "#") {
        return false;
    }

    bool canMoveUpperLeftDiag, canMoveUpper, canMoveUpperRightDiag;
    bool canMoveleft, canMoveRight;
    bool canMoveBottomLeftDiag, canMoveBottom, canMoveBottomRightDiag;

    bool isBorder = false;

    if (line - 1 >= 0 && column - 1 >= 0) {
        canMoveUpperLeftDiag = (*matrix)[line - 1][column - 1] != "#";
    } else {
        isBorder = true;
    }

    if (line - 1 >= 0) {
        canMoveUpper = (*matrix)[line - 1][column] != "#";
    } else {
        isBorder = true;
    }

    if (line - 1 >= 0 && column + 1 <= (columns - 1)) {
        canMoveUpperRightDiag = (*matrix)[line - 1][column + 1] != "#";
    } else {
        isBorder = true;
    }

    if (column - 1 >= 0) {
        canMoveleft = (*matrix)[line][column - 1] != "#";
    } else {
        isBorder = true;
    }

    if (column + 1 <= (columns - 1)) {
        canMoveRight = (*matrix)[line][column + 1] != "#";
    } else {
        isBorder = true;
    }

    if (line + 1 <= (lines - 1) && column - 1 >= 0) {
        canMoveBottomLeftDiag = (*matrix)[line + 1][column - 1] != "#";
    } else {
        isBorder = true;
    }

    if (line + 1 <= (lines - 1)) {
        canMoveBottom = (*matrix)[line + 1][column] != "#";
    } else {
        isBorder = true;
    }

    if (line + 1 <= (lines - 1) && column + 1 <= (columns - 1)) {
        canMoveBottomRightDiag = (*matrix)[line + 1][column + 1] != "#";
    } else {
        isBorder = true;
    }

    // If you try teleport and have just 1 matrix,
    // you will win one valid random position on the same matrix
    // bool canTeleport = (numberOfMatrixs > 1) && isBorder;

    bool canTeleport = isBorder;

    if (canTeleport || canMoveUpperLeftDiag || canMoveUpper ||
        canMoveUpperRightDiag || canMoveleft || canMoveRight ||
        canMoveBottomLeftDiag || canMoveBottom || canMoveBottomRightDiag) {
        return true;
    }

    return false;
}

int main() {
    ifstream file;
    file.open("matrizes.txt", ios::in);

    int lines, columns;
    readLinesAndColumnFromFile(&file, &lines, &columns);

    int numberOfMatrixs;
    readNumberOfMatrixsFromFile(&file, &numberOfMatrixs);

    vector<vector<pair<int, int>>> validPositions(numberOfMatrixs);
    vector<set<pair<int, int>>> exploitedPositions(numberOfMatrixs);

    saveAllMatrixOnSeparateFiles(&file, &validPositions, numberOfMatrixs, lines,
                                 columns);

    file.close();

    // Play

    pair<int, int> startPosition = {1, 1};
    int matrixIndex = 1;

    vector<vector<string>> matrix =
        loadMatrixFromFile(matrixIndex, lines, columns);

    if (!verifyStartPosition(startPosition, &matrix, lines, columns)) {
        cout << "Posição inicial inválida!" << endl;
        return 1;
    }

    int life = 10;
    int bag = 0;

    int itemsCounter = 0;
    int numberOfExploitedPositions = 0;
    int dangersCounter = 0;
    int allCollectedItems = 0;

    int line = startPosition.first;
    int column = startPosition.second;

    exploitedPositions[matrixIndex - 1].insert({line, column});

    while (life > 0) {
        pair<int, int> nextMove =
            randomMove(&matrix, line, column, lines, columns, &matrixIndex,
                       numberOfMatrixs, &validPositions);

        line = nextMove.first;
        column = nextMove.second;

        numberOfExploitedPositions++;

        exploitedPositions[matrixIndex - 1].insert({line, column});

        if (line == startPosition.first && column == startPosition.second) {
            if (itemsCounter == 0)
                break;
            else
                itemsCounter = 0;
        }

        string position = matrix[line][column];

        if (position == "*") {
            // Perigo
            life--;
            dangersCounter++;
        } else {
            // Como a função randomMove não retorna uma posição que seja
            // parede
            // (#) caso a posição não seja um perigo (*) ela vai ser um item
            // (1-10).

            int item = stoi(position);

            if (item != 0) {
                matrix[line][column] = to_string(item - 1);
                bag++;
                itemsCounter++;
                allCollectedItems++;
                if (bag == 4) {
                    bag = 0;
                    life++;
                }
            }
        }
    }

    cout << endl;

    cout << "Casas percorridas ao todo: " << numberOfExploitedPositions << endl
         << endl;
    cout << "Item consumidos pelo caminho: " << allCollectedItems << endl
         << endl;

    for (int i = 0; i < numberOfMatrixs; i++) {
        cout << "Matriz " << i + 1 << endl;

        cout << "Total de casas: " << lines * columns << endl;
        cout << "Posições válidas: " << validPositions[i].size() << endl;
        cout << "Paredes: " << (lines * columns) - validPositions[i].size()
             << endl;

        cout << "Casas exploradas: " << exploitedPositions[i].size() << endl;

        cout << "Casas não exploradas: "
             << validPositions[i].size() - exploitedPositions[i].size() << endl
             << endl;
    }

    cout << endl;

    cout << "Perigos enfrentados: " << dangersCounter << endl;

    cout << "Vida ao final: " << life << endl;

    return 0;
}