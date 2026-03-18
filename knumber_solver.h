#ifndef KNUMBER_SOLVER_H
#define KNUMBER_SOLVER_H

#include <string>

struct KNumberSolverResult {
    double count;
    bool success;
    std::string error_message;
};

class KNumberSolver {
public:
    KNumberSolver() = default;

    // Устанавливает параметры задачи
    bool setParameters(int n, int k);

    // Решает задачу подсчета K-ичных чисел без трех подряд идущих нулей
    KNumberSolverResult solve();

    // Сохраняет результат в файл
    bool saveResultToFile(const std::string& filename, const KNumberSolverResult& result) const;

    // Загружает параметры из файла
    bool loadFromFile(const std::string& filename);

    // Геттеры
    int getN() const { return n_digits; }
    int getK() const { return k_base; }

private:
    int n_digits = 0;      // N - количество разрядов
    int k_base = 0;        // K - основание системы счисления

    bool validateParameters() const;
    double calculateCount() const;
};

#endif // KNUMBER_SOLVER_H