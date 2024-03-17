import numpy as np


def read_matrix_from_file(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
        rows, cols = map(int, lines[0].split())
        matrix = np.array([list(map(int, line.split())) for line in lines[1:]])

    return matrix


# Чтение матриц из файлов
matrix1 = read_matrix_from_file(r'E:\\Projectы\\Lab_1_Par_prog\\matrix1.txt')
matrix2 = read_matrix_from_file(r'E:\\Projectы\\Lab_1_Par_prog\\matrix2.txt')

print("Матрица 1:\n", matrix1)
print("Матрица 2:\n", matrix2)


def write_matrix_to_file(file_path, matrix):
    with open(file_path, 'w') as file:
        file.write(f"{len(matrix)} {len(matrix[0])}\n")
        for row in matrix:
            file.write(' '.join(map(str, row)) + '\n')


# Умножение матриц
result_matrix = np.matmul(matrix1, matrix2)

# Запись результата в файл
write_matrix_to_file(r'E:\\Projectы\\Lab_1_Par_prog\\result_matrix_python.txt', result_matrix)

print("Матрицы перемножены успешно, и результат записан в файл 'result_matrix.txt'.")
print("Result:\n", result_matrix)
