#include <stdlib.h>
#include <unistd.h>

#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

#include "FileOperator.h"
#include "Matrix.h"
#include "bfs.hpp"
#include "dfs.hpp"
#include "rms.hpp"

using namespace std;

int main() {
    Matrix matrix;
    rms rand;
    bfs breadth;
    dfs deep;

    char** copy;

    FileOperator fileOperator;

    // section text:
    fileOperator.openFile();
    matrix.setMatrixDimensions(fileOperator.readFileHeader());
    matrix.allocateMatrix();

    for (unsigned i = 0; i < matrix.getMatrixDimensions().first; i++) {
        for (unsigned j = 0; j < matrix.getMatrixDimensions().second; j++) {
            matrix.loadContentInMatrix(i, j, fileOperator.ReadDataFromFile());
        }
    }

    // Setting the number of decimal places in the output
    cout << fixed << setprecision(9) << endl;

    // Random

    copy = matrix.getCopyOfMatrix();

    auto start = chrono::steady_clock::now();

    rand.run(copy, matrix.getMatrixDimensions().first);

    auto elapsedTime = chrono::steady_clock::now() - start;

    fileOperator.saveMatrixOnFile(copy, "./dataset/rand.data");

    double duration =
        chrono::duration_cast<chrono::duration<double>>(elapsedTime).count();

    cout << "Tempo de execução do método randômico: \t\t" << duration * 1000
         << " ms" << endl;

    // BFS

    copy = matrix.getCopyOfMatrix();

    start = chrono::steady_clock::now();

    breadth.run(copy, matrix.getMatrixDimensions().first);

    elapsedTime = ::std::chrono::steady_clock::now() - start;

    fileOperator.saveMatrixOnFile(copy, "./dataset/bfs.data");

    duration = ::std::chrono::duration_cast<::std::chrono::duration<double>>(
                   elapsedTime)
                   .count();

    cout << "Tempo de execução da busca em largura: \t\t" << duration * 1000
         << " ms" << endl;

    // DFS

    copy = matrix.getCopyOfMatrix();

    start = chrono::steady_clock::now();

    deep.run(copy, matrix.getMatrixDimensions().first);

    elapsedTime = ::std::chrono::steady_clock::now() - start;

    fileOperator.saveMatrixOnFile(copy, "./dataset/dfs.data");

    duration = ::std::chrono::duration_cast<::std::chrono::duration<double>>(
                   elapsedTime)
                   .count();

    cout << "Tempo de execução da busca em profundidade: \t" << duration * 1000
         << " ms" << endl;

    fileOperator.closeFile();

    return 0;
}
