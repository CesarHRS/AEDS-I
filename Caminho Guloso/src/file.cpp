#include "file.hpp"

void File::readInitialPosition(string configFileName, int* initialLine,
                               int* initialColumn) {
    FILE* file = fopen(configFileName.c_str(), "r");

    if (file == nullptr) {
        cout << "Error: could not open config file: \"config.va\".\n";
        exit(-1);
    }

    fscanf(file, "%d", initialLine);
    fscanf(file, "%d", initialColumn);

    fclose(file);
}

void File::readLinesAndColumns(FILE* file, int* lines, int* columns) {
    fscanf(file, "%d", lines);
    fscanf(file, "%d", columns);
}

FILE* File::openFileToRead(string filename) {
    FILE* file = fopen(filename.c_str(), "r");

    if (file == nullptr) {
        cout << "Error: could not open matrix file.\n";
        exit(-1);
    }

    return file;
}

void File::readMatrix(FILE* file, vector<vector<int>>* matrix, int* lines, int* columns) {
    for (int i = 0; i < *lines; i++) {
        vector<int> line;

        for (int j = 0; j < *columns; j++) {
            int num;
            fscanf(file, "%d", &num);
            line.push_back(num);
        }

        matrix->push_back(line);
    }
}