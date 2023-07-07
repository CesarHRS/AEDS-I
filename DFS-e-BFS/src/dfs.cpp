#include "dfs.hpp"

void print(char** matriz, int tam) {
    cout << endl;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << (matriz)[i][j] << " ";
        }

        cout << endl;
    }
}

dfs::dfs() { this->steps = 0; }

bool dfs::move(int line, int column, char** matrix) {
    if (line >= tam || line < 0 || column >= tam || column < 0) return false;
    if (matrix[line][column] == '#') return false;

    stack.push({line, column});
    moves.push_back({line, column});

    steps++;

    return true;
}

void dfs::danger(char** matrix) {
    matrix[l][c] = '1';  // Eliminating danger

    // Cleaning path
    while (!moves.empty()) {
        matrix[moves.back().first][moves.back().second] = '1';
        moves.pop_back();
    }

    // Returning to start position
    stack.push({0, 0});
}

void dfs::run(char** matrix, int tam) {
    this->tam = tam;

    stack.push({0, 0});  // Setting starting position
    moves.push_back({0, 0});

    l = stack.top().position.first;   // line
    c = stack.top().position.second;  // column

    while (!stack.empty()) {
        char position =
            matrix[stack.top().position.first][stack.top().position.second];

        if (position == '?') break;

        l = stack.top().position.first;
        c = stack.top().position.second;

        if ((matrix)[l][c] == '*') {
            danger(matrix);
            continue;
        }

        matrix[l][c] = '#';  // Marking visited position

        // Mostar execucação passo a passo
        // print(matrix, tam);
        // usleep(10000);  // sleeps for 3 second
        // system("clear");

        if (move(l + 1, c, matrix)) continue;
        if (move(l, c + 1, matrix)) continue;
        if (move(l, c - 1, matrix)) continue;
        if (move(l - 1, c, matrix)) continue;

        stack.pop();
    }

    cout << "Passos Profundidade: " << steps << endl;
}
