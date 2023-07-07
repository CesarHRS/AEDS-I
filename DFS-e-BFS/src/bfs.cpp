#include "bfs.hpp"

void printB(char** matriz, int tam) {
    cout << endl;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << (matriz)[i][j] << " ";
        }

        cout << endl;
    }
}

bfs::bfs() { this->steps = 0; }

bool bfs::isValid(int line, int column, char** matrix) {
    return (line < tam && line >= 0 && column < tam && column >= 0) &&
           matrix[line][column] != '#';
}

void bfs::move(int line, int column, char** matrix) {
    matrix[line][column] = '#';  // Marking visited position

    queue.push({line, column});
    moves.push_back({line, column});

    steps++;
}

bool bfs::danger(int line, int column, char** matrix) {
    if (matrix[line][column] != '*') return false;

    matrix[line][column] = '1';  // Eliminating danger

    // Cleaning path
    for (int i = 0; i < (int)moves.size(); i++) {
        matrix[moves[i].first][moves[i].second] = '1';
    }

    while (!queue.empty()) {
        queue.pop();
    }

    // Returning to start position
    queue.push({0, 0});

    return true;
}

void bfs::run(char** matrix, int tam) {
    this->tam = tam;
    queue.push({0, 0});  // Setting starting position
    moves.push_back({0, 0});
    matrix[0][0] = '#';

    int l = queue.front().position.first;   // line
    int c = queue.front().position.second;  // column

    while (!queue.empty()) {
        l = queue.front().position.first;
        c = queue.front().position.second;

        if (isValid(l - 1, c, matrix)) {
            if (danger(l - 1, c, matrix)) continue;
            if (matrix[l - 1][c] == '?') {
                steps++;
                break;
            }

            move(l - 1, c, matrix);
        }

        if (isValid(l, c - 1, matrix)) {
            if (danger(l, c - 1, matrix)) continue;
            if (matrix[l][c - 1] == '?') {
                steps++;
                break;
            }

            move(l, c - 1, matrix);
        }

        if (isValid(l, c + 1, matrix)) {
            if (danger(l, c + 1, matrix)) continue;
            if (matrix[l][c + 1] == '?') {
                steps++;
                break;
            }

            move(l, c + 1, matrix);
        }

        if (isValid(l + 1, c, matrix)) {
            if (danger(l + 1, c, matrix)) continue;
            if (matrix[l + 1][c] == '?') {
                steps++;
                break;
            }

            move(l + 1, c, matrix);
        }

        // printB(matrix, tam);
        // usleep(100000);  // sleeps for 3 second
        // system("clear");

        queue.pop();
    }

    cout << "Passos Largura: " << steps << endl;
}
