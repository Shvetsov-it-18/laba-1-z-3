#include "knumber_solver.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

bool KNumberSolver::setParameters(int n, int k) {
    n_digits = n;
    k_base = k;
    return validateParameters();
}

bool KNumberSolver::validateParameters() const {
    if (n_digits <= 1 || n_digits >= 20) {
        return false;
    }

    if (k_base < 2 || k_base > 10 || n_digits + k_base >= 26) {
        return false;
    }

    return true;
}

double KNumberSolver::calculateCount() const {
    // Состояния динамического программирования:
    // ending_with_nonzero - количество чисел, оканчивающихся на ненулевую цифру
    // ending_with_one_zero - количество чисел, оканчивающихся ровно на один ноль
    // ending_with_two_zeros - количество чисел, оканчивающихся ровно на два нуля

    long long ending_with_nonzero = k_base - 1;  // Первая цифра не может быть нулем
    long long ending_with_one_zero = 0;
    long long ending_with_two_zeros = 0;

    // Построение чисел длины от 2 до n_digits
    for (int i = 2; i <= n_digits; ++i) {
        // Новые значения для следующей длины числа
        long long new_ending_with_nonzero = (k_base - 1) * (ending_with_nonzero +
            ending_with_one_zero + ending_with_two_zeros);
        long long new_ending_with_one_zero = ending_with_nonzero;
        long long new_ending_with_two_zeros = ending_with_one_zero;

        ending_with_nonzero = new_ending_with_nonzero;
        ending_with_one_zero = new_ending_with_one_zero;
        ending_with_two_zeros = new_ending_with_two_zeros;
    }

    // Общее количество допустимых чисел
    return static_cast<double>(ending_with_nonzero +
        ending_with_one_zero +
        ending_with_two_zeros);
}

KNumberSolverResult KNumberSolver::solve() {
    KNumberSolverResult result;
    result.success = false;
    result.count = 0.0;
    result.error_message = "";

    if (!validateParameters()) {
        result.error_message = "Некорректные параметры: N должно быть 1 < N < 20, "
            "K должно быть 2 ≤ K ≤ 10, N + K < 26";
        return result;
    }

    result.count = calculateCount();
    result.success = true;

    return result;
}

bool KNumberSolver::saveResultToFile(const std::string& filename,
    const KNumberSolverResult& result) const {
    std::ofstream output_file(filename);
    if (!output_file.is_open()) {
        std::cerr << "Ошибка! Не удалось создать " << filename << std::endl;
        return false;
    }

    output_file << result.count;
    return output_file.good();
}

bool KNumberSolver::loadFromFile(const std::string& filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Ошибка! Не удалось открыть " << filename << std::endl;
        return false;
    }

    std::string line;
    if (!std::getline(input_file, line)) {
        std::cerr << "Ошибка! Файл пуст" << std::endl;
        return false;
    }

    std::istringstream iss(line);
    if (!(iss >> n_digits >> k_base)) {
        std::cerr << "Ошибка! Не удалось прочитать N и K" << std::endl;
        return false;
    }

    return validateParameters();
}