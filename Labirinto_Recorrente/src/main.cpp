#include <chrono>
#include <iostream>
#include "Maze.h"

using namespace std;


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Maze maze;
    maze.readHeader();
    maze.separateMatrix();
    maze.allocate();
    maze.getInitialPosition();
    maze.loadMatrix();
    maze.joystick();
    maze.endGame();
    auto end = std::chrono::high_resolution_clock::now();
    auto exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Tempo de execução: " << exec_time.count() << " milisegundos." << std::endl;
    return 0;
}