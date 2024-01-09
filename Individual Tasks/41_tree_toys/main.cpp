#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

// Структура, представляющая каждый набор игрушек
struct ToySet {
    int d;      // Число игрушек в наборе
    int t;      // Время изготовления набора
    int index;  // Индекс набора (для отслеживания выбранных наборов)
};

int main() {
    int s, n, m;
    input >> s >> n >> m;
    int size = n * m; // Максимальный доступный размер коробки

    // Создаем вектор, чтобы хранить информацию о каждом наборе игрушек
    vector<ToySet> sets(s);

    // Считываем данные о наборах из входного файла
    for (int i = 0; i < s; ++i) {
        input >> sets[i].d >> sets[i].t;
        sets[i].index = i + 1; // Индекс начинается с 1 для удобства вывода результата
    }

    input.close();

    // Сортируем наборы по времени изготовления (для случаев, когда в наборах разное число игрушек, но одно время)
    sort(sets.begin(), sets.end(), [](const ToySet& a, const ToySet& b) {
        if (a.t == b.t) {
            return a.d > b.d;
        }
        return a.t > b.t;
    });

    // Создаем двумерный массив dp для хранения результатов
    vector<vector<long long>> dp(s + 1, vector<long long>(size + 1, 0));

    // Заполняем dp с использованием динамического программирования
    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= size; ++j) {
            if (sets[i - 1].d <= j) {
                // Выбираем максимум между включением текущего набора и невключеением его
                dp[i][j] = max(dp[i][j], dp[i - 1][j - sets[i - 1].d] + sets[i - 1].t);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            // `dp[i - 1][j - sets[i - 1].d] + sets[i - 1].t` - это время изготовления, если мы включим текущий набор `i - 1`
            // в рассмотрение, учитывая его размер (`sets[i - 1].d`) и временные затраты (`sets[i - 1].t`),
            // и смотрим на оставшийся размер `j - sets[i - 1].d`.
        }
    }

    // Создаем вектор chosen_sets для хранения индексов выбранных наборов
    vector<int> chosen_sets;

    // Восстанавливаем выбранные наборы из dp
    for (int i = s; i > 0; --i) {
        if (dp[i][size] > dp[i - 1][size]) {
            chosen_sets.push_back(sets[i - 1].index);
            size -= sets[i - 1].d;
        }
    }

    output << chosen_sets.size() << endl;

    for (int i = 0; i < chosen_sets.size(); i++) {
        output << chosen_sets[i] << " ";
    }

    output.close();

    return 0;
}
