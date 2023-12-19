//
// Created by czarhrs on 11/19/23.
//


#include "dfs.h"

int dfs(vector<vector<char>> matrix, vector<vector<int>> distance, pair<int, int> I, pair<int, int> F) {
    bool found = false;
    stack<pair<int, int>> s;
    int verification_counter = 0;
    s.push(I);
    distance[I.first][I.second] = 0;

    while (!s.empty()) {
        if(found){
            break;
        }
        auto [i, j] = s.top();
        matrix[i][j] = '#';
        verification_counter++;

        s.pop();

        for (auto [vi, vj]: initializer_list<pair<int, int>>{
                {i + 1, j},
                {i - 1, j},
                {i,     j + 1},
                {i,     j - 1}}) {

            if (vi < 0 || vj < 0 || (unsigned long int)vi >= matrix.size() || (unsigned long int)vj >= matrix[0].size() || matrix[vi][vj] == '1') {
                continue;
            }
            if (distance[vi][vj] <= distance[i][j] + 1) {
                continue;
            }

            distance[vi][vj] = distance[i][j] + 1;

            if (make_pair(vi, vj) == F) {
                matrix[vi][vj] = '*';
                verification_counter++;
                found = true;
                break;
            } else {
                s.push(make_pair(vi, vj));
            }
        }
    }
    printMatrix(matrix);
    return verification_counter;
}

void printMatrix(vector<vector<char>> &matrix) {
    cout << endl;
    for (const auto &row: matrix) {
        for (char ch: row) {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }
    cout << endl;
}
