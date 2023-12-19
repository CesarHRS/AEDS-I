//
// Created by czarhrs on 11/19/23.
//

#ifndef DIJKSTRA_DFS_H
#define DIJKSTRA_DFS_H

#include <iostream>
#include <vector>
#include <stack>


using namespace std;


int dfs(vector<vector<char>> matrix, vector<vector<int>> distance, pair<int, int> I, pair<int, int> F);

void printMatrix(vector<vector<char>> &matrix);


#endif //DIJKSTRA_DFS_H
