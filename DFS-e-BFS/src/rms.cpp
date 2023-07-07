#include "rms.hpp"

// TODO remove this
void printA(char** matriz, int tam) {
    cout << endl;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << (matriz)[i][j] << " ";
        }

        cout << endl;
    }
}

rms::rms() { this->steps = 0; }

void rms::danger(char** matrix) {
    matrix[l][c] = '1';  // Eliminating danger

    // Cleaning path
    while (!moves.empty()) {
        matrix[moves.back().first][moves.back().second] = '1';
        moves.pop_back();
    }

    // Returning to start position
    stack.push({0, 0});
}

int rms::randomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

vector<pair<int, int>> rms::getAllPossibilites(char** matrix) {
    vector<pair<int, int>> possibilities;

    if (l + 1 < tam)
        if (matrix[l + 1][c] != '#') possibilities.push_back({l + 1, c});

    if (c + 1 < tam)
        if (matrix[l][c + 1] != '#') possibilities.push_back({l, c + 1});

    if (c - 1 >= 0)
        if (matrix[l][c - 1] != '#') possibilities.push_back({l, c - 1});

    if (l - 1 >= 0)
        if (matrix[l - 1][c] != '#') possibilities.push_back({l - 1, c});

    return possibilities;
}

void rms::run(char** matrix, int tam) {
    this->tam = tam;     // Setting size
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

        // cout << "Randômico" << endl;
        // printA(matrix, tam);
        // usleep(800000);  // sleeps for 3 second
        // system("clear");

        auto possibilities = getAllPossibilites(matrix);

        if (!possibilities.empty()) {
            int randomMove = randomInt(0, possibilities.size() - 1);

            stack.push(possibilities[randomMove]);
            moves.push_back(possibilities[randomMove]);
            steps++;

            continue;
        }

        stack.pop();
    }

    cout << "Passos Randômico: " << steps << endl;
}