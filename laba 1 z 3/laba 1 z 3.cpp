//FIX_ME: Неинформативное имя функции
//старый код: double kichnye(int N, int K)
новый код : double CountValidNumbers(int N, int K)

//FIX_ME: Неинформативные и не соответствующие Google Style имена переменных
//старый код: long long nz = K - 1; long long oz = 1; long long tz = 0;
новый код : long long count_end_nonzero = K - 1;
long long count_end_one_zero = 1;
long long count_end_two_zeros = 0;

//FIX_ME: Неинформативные имена переменных в цикле
//старый код: long long nz_ = (K - 1) * (nz + oz);
//           long long oz_ = nz;
//           long long tz_ = tz + oz*K;
новый код : long long new_count_end_nonzero = (K - 1) * (count_end_nonzero + count_end_one_zero);
long long new_count_end_one_zero = count_end_nonzero;
long long new_count_end_two_zeros = count_end_two_zeros + count_end_one_zero * K;

//FIX_ME: Использование магических чисел в проверках
//старый код: if (N <= 1 || N >= 20)
//           if (K < 2 || K > 10 || N + K >= 26)
новый код : const int MIN_N = 2; const int MAX_N = 19;
const int MIN_K = 2; const int MAX_K = 10;
const int MAX_SUM = 25;

if (N < MIN_N || N > MAX_N)
if (K < MIN_K || K > MAX_K || N + K > MAX_SUM)

//FIX_ME: Неинформативное имя переменной результата
//старый код: double bebe = kichnye(N, K);
новый код : double result = CountValidNumbers(N, K);

//FIX_ME: Отсутствие проверки ввода (пользователь может ввести не число)
//старый код: cin >> N; cin >> K;
новый код : if (!(cin >> N)) {
    cout << "Ошибка: необходимо ввести число" << endl;
    return 1;
}

if (!(cin >> K)) {
    cout << "Ошибка: необходимо ввести число" << endl;
    return 1;
}

//FIX_ME: Отсутствие пробелов вокруг операторов в выводе
//старый код: cout << "Введите количество разрядов N (1 < N < 20): ";
новый код : cout << "Введите количество разрядов N (1 < N < 20): ";

//FIX_ME: Непонятная логика возврата (возвращается только nz + oz)
//старый код: return nz + oz;
новый код : // Сумма чисел, оканчивающихся на ненулевую цифру и на один ноль
return count_end_nonzero + count_end_one_zero;

//FIX_ME: Отсутствие комментариев, объясняющих алгоритм
//старый код: (нет комментариев)
новый код : // Динамическое программирование:
// count_end_nonzero - числа, оканчивающиеся на ненулевую цифру
// count_end_one_zero - числа, оканчивающиеся ровно на один ноль
// count_end_two_zeros - числа, оканчивающиеся на два нуля
// На каждом шаге добавляем одну цифру слева

//FIX_ME: Неправильный стиль отступов и расположения скобок
//старый код:
//for (int i = 2; i <= N; i++) {
//        long long nz_ = (K - 1) * (nz + oz);
//        long long oz_ = nz;
//        long long tz_ = tz + oz*K;
//        nz = nz_;
//        oz = oz_;
//        tz = tz_;
//    }
новый код :
for (int i = 2; i <= N; ++i) {
    long long new_count_end_nonzero = (K - 1) * (count_end_nonzero + count_end_one_zero);
    long long new_count_end_one_zero = count_end_nonzero;
    long long new_count_end_two_zeros = count_end_two_zeros + count_end_one_zero * K;

    count_end_nonzero = new_count_end_nonzero;
    count_end_one_zero = new_count_end_one_zero;
    count_end_two_zeros = new_count_end_two_zeros;
}