// using namespace std;

// Ошибка: неинформативные имена переменных и параметров
// double kichnye(int N, int K) {
double CountNumbersWithoutThreeZeros(int n, int k) {

// Ошибка: неинформативные имена переменных (nz, oz, tz)
// long long nz = K - 1;
// long long oz = 1;
// long long tz = 0;
  long long ending_with_nonzero = k - 1;
  long long ending_with_one_zero = 1;
  long long ending_with_two_zeros = 0;

// Ошибка: использование постфиксного инкремента i++
// for (int i = 2; i <= N; i++) {
  for (int i = 2; i <= n; ++i) {

// Ошибка: неверные формулы пересчета для динамического программирования
// long long nz_ = (K - 1) * (nz + oz);
// long long oz_ = nz;
// long long tz_ = tz + oz*K;
    long long new_ending_with_nonzero = (k - 1) * (ending_with_nonzero + 
                                      ending_with_one_zero + ending_with_two_zeros);
    long long new_ending_with_one_zero = ending_with_nonzero;
    long long new_ending_with_two_zeros = ending_with_one_zero;

// Ошибка: неправильное присваивание переменных
// nz = nz_;
// oz = oz_;
// tz = tz_;
    ending_with_nonzero = new_ending_with_nonzero;
    ending_with_one_zero = new_ending_with_one_zero;
    ending_with_two_zeros = new_ending_with_two_zeros;

// Ошибка: возвращали только nz + oz, не учитывая tz
// return nz + oz;
  return static_cast<double>(ending_with_nonzero + ending_with_one_zero + ending_with_two_zeros);

// Ошибка: неверный параметр для setlocale
// setlocale(LC_ALL, "ru");
  std::setlocale(LC_ALL, "Russian");

// Ошибка: в условии использован оператор "  " вместо ||
// if (N <= 1  N >= 20) {
  if (n <= 1 || n >= 20) {

// Ошибка: в условии использован оператор "  " вместо ||
// if (K < 2  K > 10 || N + K >= 26) {
  if (k < 2 || k > 10 || n + k >= 26) {

// Ошибка: неинформативное имя переменной и вызов функции со старыми именами
// double bebe = kichnye(N, K);
  double result = CountNumbersWithoutThreeZeros(n, k);

// Ошибка: отсутствовало объявление using std::cout или std:: перед cout
// cout << "Введите количество разрядов N (1 < N < 20): ";
  std::cout << "Введите количество разрядов N (1 < N < 20): ";

// аналогично для всех cin и cout
// cin >> N;
  std::cin >> n;

// cin >> K;
  std::cin >> k;

// cout << "Некорректные входные данные" << endl;
  std::cout << "Некорректные входные данные" << std::endl;

// cout << "Некорректные значения" << endl;
  std::cout << "Некорректные значения" << std::endl;

// cout << "Количество чисел, в которых не содержится более двух подряд идущих нулей: " << bebe << endl;
  std::cout << "Количество чисел, в которых не содержится более двух подряд идущих нулей: " 
            << result << std::endl;
