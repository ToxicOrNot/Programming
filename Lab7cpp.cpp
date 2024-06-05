#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int max_lectures(vector<pair<int, int>>& lectures) {
    // Сортируем заявки по времени окончания
    sort(lectures.begin(), lectures.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // Инициализируем переменные
    int count = 0;
    int end_time = 0;

    // Проходим по всем заявкам
    for (const auto& lecture : lectures) {
        int si = lecture.first;
        int fi = lecture.second;
        // Если начало лекции больше или равно времени окончания предыдущей выбранной лекции
        if (si >= end_time) {
            // Выбираем эту лекцию
            count += 1;
            end_time = fi;
        }
    }

    return count;
}

int boxes_weight(int n, vector<pair<int, int>>& boxes) {
    int m = 1;
    // Сортируем коробки по весу, затем по стоимости
    sort(boxes.begin(), boxes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });

    int weight_left = boxes[0].second;
    for (const auto& box : boxes) {
        int wi = box.first;
        int ci = box.second;
        if (wi <= weight_left) {
            m += 1;
            if (weight_left - wi < ci) {
                weight_left -= wi;
            } else {
                weight_left = ci;
            }
        }
    }

    return m;
}

int main() {
    int choose;
    cin >> choose;

    switch (choose) {
        case 1: {
            // Ввод данных для задачи 1
            int N;
            cin >> N;
            vector<pair<int, int>> lectures(N);
            for (int i = 0; i < N; ++i) {
                cin >> lectures[i].first >> lectures[i].second;
            }

            // Вычисление и вывод результата
            int result = max_lectures(lectures);
            cout << result << endl;
            break;
        }

        case 2: {
            // Ввод данных для задачи 2
            int n;
            cin >> n;
            vector<pair<int, int>> boxes(n);
            for (int i = 0; i < n; ++i) {
                cin >> boxes[i].first >> boxes[i].second;
            }

            // Вычисление и вывод результата
            int result = boxes_weight(n, boxes);
            cout << result << endl;
            break;
        }

        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}
