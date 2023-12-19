//
// Created by czarhrs on 11/19/23.
//

#include "bfs.h"

int bfs(vector<vector<char>> matrix, vector<vector<int>> distance, pair<int, int> I, pair<int, int> F) {

    queue<pair<int, int>> q;
    q.push(I);
    distance[I.first][I.second] = 0;
    int verifications_counter = 0;

    while (!q.empty()) {
        auto [i, j] = q.front();
        matrix[i][j] = '#';
        verifications_counter++;
        q.pop();

        for (auto [vi, vj]: initializer_list<pair<int, int>>{
                {i + 1, j},
                {i - 1, j},
                {i,     j + 1},
                {i,     j - 1}}){

            if (vi < 0 || vj < 0 || (unsigned long int)vi >= matrix.size() || (unsigned long int)vj >= matrix[0].size() || matrix[vi][vj] == '1') {
                continue;
            }
            if (distance[vi][vj] <= distance[i][j] + 1) {
                continue;
            }

            distance[vi][vj] = distance[i][j] + 1;

            if (make_pair(vi, vj) == F) {
                matrix[vi][vj] = '*';
                verifications_counter++;
                printMatrixAux(matrix);
                return verifications_counter;
            } else {
                q.push(make_pair(vi, vj));
            }
        }
    }
    return 0;
}

void printMatrixAux(vector<vector<char>> &matrix) {
    cout << endl;
    for (const auto &row: matrix) {
        for (char ch: row) {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }
    cout << endl;
}
