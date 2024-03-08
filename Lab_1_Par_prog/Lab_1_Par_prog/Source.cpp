#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

void matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& result) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Чтение значений матриц из файлов
    std::ifstream file1("E:\\Projectы\\Lab_1_Par_prog\\matrix1.txt");
    std::ifstream file2("E:\\Projectы\\Lab_1_Par_prog\\matrix2.txt");

    int m, n, p;
    file1 >> m >> n;
    file2 >> n >> p;

    std::vector<std::vector<int>> A(m, std::vector<int>(n));
    std::vector<std::vector<int>> B(n, std::vector<int>(p));
    std::vector<std::vector<int>> result(m, std::vector<int>(p));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            file1 >> A[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            file2 >> B[i][j];
        }
    }

    // Перемножение матриц
    auto start = std::chrono::steady_clock::now();
    matrixMultiply(A, B, result);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    // Запись результата в файл
    std::ofstream file_result("E:\\Projectы\\Lab_1_Par_prog\\result_matrix.txt");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            file_result << result[i][j] << " ";
        }
        file_result << "\n";
    }

    // Вывод времени выполнения и объема задачи
    std::cout << "Time taken: " << elapsed_seconds.count() << "s\n";
    std::cout << "Task size: " << m << "x" << n << " and " << n << "x" << p << std::endl;
    file_result << "Time taken: " << elapsed_seconds.count() << "s\n";;
    file_result << "Task size: " << m << "x" << n << " and " << n << "x" << p << std::endl;
    // Завершение программы
    file1.close();
    file2.close();
    file_result.close();
    return 0;
}