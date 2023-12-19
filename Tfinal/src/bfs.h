//
// Created by czarhrs on 11/19/23.
//

#ifndef DIJKSTRA_BFS_H
#define DIJKSTRA_BFS_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>


using namespace std;

int bfs(vector<vector<char>> matrix, vector<vector<int>> distance, pair<int, int> I, pair<int, int> F);

void printMatrixAux(vector<vector<char>> &matrix);
#endif //DIJKSTRA_BFS_H
