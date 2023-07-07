#include "joystick.h"
#include "file.h"
#include <chrono>


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream file;
    unsigned counter = 0, matrix_counter = 0;
    unsigned short size, num, row, column;

    file.open("dataset/input.data");

    if (file.is_open()) {

        read_size(&file, &size);
        auto *matrix = (unsigned *) malloc(size * size * sizeof(unsigned));

        do {
            load_matrix(&file, &size, &num, matrix, &matrix_counter);
            read_row_and_column(&row, &column);
            set_inicial_position(&row, &column, &counter, matrix, &size);
            joystick(matrix, size, &row, &column, &counter);

            if (file.eof()) {
                std::cout << "Fim do arquivo!" << std::endl;
                print(matrix, size);
                std::cout << "Contador: " << counter << std::endl;
                file.close();
                auto end = std::chrono::high_resolution_clock::now();
                auto exec_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                std::cout << "Tempo de execução: " << exec_time.count() << " milisegundos." << std::endl;
                return 0;
            }
        } while (true);
    }
    return 0;
}